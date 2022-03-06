#include <fstream>




using namespace std;

int v[100005];

int interclaseaza(int st,int dr)

{

    int mij=(st+dr)/2,i=st,j=mij+1,n3=0,nU=0;

    int *u=new int[dr-st+2];

    while (i<=mij && j<=dr)

    {

        if (v[i]<=v[j])

        {

            u[++nU]=v[i];

            i++;

        }

        else

        {

            u[++nU]=v[j];

            n3=(n3+(mij-i+1))%9917;

            j++;

        }

    }

    while (i<=mij)

    {

        u[++nU]=v[i];

        i++;

    }

    while (j<=dr)

    {

        u[++nU]=v[j];

        j++;

    }

    for (i=st;i<=dr;i++)

    {

        v[i]=u[i-st+1];

    }

    delete []u;

    return n3;



}

int inversiuni(int st, int dr)

{

    if (st==dr)

        return 0;

    int mij=(st+dr)/2;

    int n1=inversiuni(st,mij);

    int n2=inversiuni(mij+1,dr);

    return (n1+n2+interclaseaza(st,dr))%9917;

}

int main()

{

    ifstream fin("inv.in");

    ofstream fout("inv.out");

    int n,i;

    fin>>n;

    for (i=1;i<=n;i++)

    {

        fin>>v[i];

    }

    fout<<inversiuni(1,n)<<'\n';

    fin.close();

    fout.close();

    return 0;

}
