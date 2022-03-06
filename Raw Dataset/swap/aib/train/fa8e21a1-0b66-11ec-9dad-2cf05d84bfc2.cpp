#include <bits/stdc++.h>


using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

vector <int> v[50];

vector <int> v1[50];

char a[50005],b[50005];

int n,n1,aib[50005],pozi[50];

int ub (int x)

{

    return x&(-x);

}

void update(int poz,int val)

{

    int i;

    for (i=poz;i<=n;i+=ub(i))

    {

        aib[i]+=val;

    }

}

int suma (int poz)

{

    int i,sum=0;

    for (i=poz;i>0;i-=ub(i))

    {

        sum=sum+aib[i];

    }

    return sum;

}

int main()

{

    f>>a>>b;

    n=strlen(a);

    for (int i=0;i<n;i++)

    {

        int valoare=a[i]-'a'+1;

        v[valoare].push_back(i+1);

    }

    for (int i=0;i<n;i++)

    {

       int valoare=b[i]-'a'+1;

        v1[valoare].push_back(i);

    }

    int ok=1;

    for (int i=1;i<=30;i++)

    {

        if (v[i].size()!=v1[i].size())

        {

            ok=0;

            break;

        }

    }

    if (ok==0)

    {

        g<<"-1";

    }

    else

    {

        int sum=0;

        for (int i=0;i<n;i++)

        {

            int valoare=b[i]-'a'+1;

            int pozitie=v[valoare][pozi[valoare]];

            sum=sum+pozitie-1-suma(pozitie);

            update(pozitie,1);

            pozi[valoare]++;

        }

        g<<sum;

    }

    return 0;

}
