#include <fstream>


using namespace std;



ifstream cin("schi.in");



ofstream cout("schi.out");



int tree[30000+5];





int v[30000+5],poz[30000+5];

int n;

int sum(int k)

{

    int s=0;

    while(k>=1)

    {

        s+=tree[k];

        k-=k&-k;

    }

    return s;

}

int bs(int val)

{

    int l=1,r=n,med;

    while(l<r)

    {

        med=(l+r)/2;

        int s=sum(med);

        if(s==val)

            r=med;

        else if(s>val)

            r=med-1;

        else l=med+1;

    }

    return l;

}

void add(int k,int x)

{

    while(k<=n)

    {

        tree[k]+=x;

        k+=k&-k;

    }

}

int main()



{





    cin>>n;



    for(int i=1;i<=n;++i)



        cin>>v[i],add(i,1);



    for(int i=n;i>=1;--i)

    {

        int e=bs(v[i]);

        poz[e]=i;

        add(e,-1);

    }



    for(int i=1;i<=n;++i)



        cout<<poz[i]<<'\n';



    return 0;



}
