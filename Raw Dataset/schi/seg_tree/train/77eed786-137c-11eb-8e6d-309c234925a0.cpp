#include <iostream>
#include <fstream>


using namespace std;



ifstream in("schi.in");

ofstream out("schi.out");



const int dim = 30005;



int n,m,arb[4*dim],a[dim],rasp[dim];



void update(int nod,int st,int dr,int index,int val)

{

    if (st == dr)

    {

        arb[nod] = val;

        return ;

    }

    int mid = (st+dr)/2;

    if (index <= mid)

    {

        update(2*nod,st,mid,index,val);

    }

    else

    {

        update(2*nod+1,mid+1,dr,index,val);

    }

    arb[nod] = arb[2*nod] + arb[2*nod+1];

}



int query(int nod,int st,int dr,int value)

{

    if (st == dr)

    {

        return st;

    }

    int mid = (st+dr)/2;

    if (value == arb[nod])

    {

        if (arb[2*nod] >= value)

        {

            return query(2*nod,st,mid,value);

        }

        else

        {

            return query(2*nod+1,mid+1,dr,value - arb[2*nod]);

        }

    }

    else

    {

        if (arb[2*nod] < value)

        {

            return query(2*nod+1,mid+1,dr,value-arb[2*nod]) ;

        }

        else

        {

            return query(2*nod,st,mid,value);

        }

    }

}



int main()

{

    in >> n;

    int log = 1;

    while (log <= n)

    {

        log *= 2;

    }

    log /= 2;

    for (int i=1; i<=n; i++)

    {

        update(1,1,n,i,1);

        in >> a[i];

    }

    for (int i=n; i>=1; i--)

    {

        int poz = query(1,1,n,a[i]);

        rasp[poz] = i;

        update(1,1,n,poz,0);

    }

    for (int i=1; i<=n; i++)

    {

        out << rasp[i] << "\n";

    }

    return 0;

}
