#include <bits/stdc++.h>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int fn[30010],v[30010],rez[30010],n;



void add(int k, int val)

{

    while(k<=n)

    {

        fn[k]+=val;

        k+=k&-k;

    }

}



int find(int val)

{

    int step,i;

    for (step = 1; step<=n; step<<=1);

    for (i = 0; step>0; step>>=1)

        if (i+step<=n && fn[i+step]<val)

        {

            i+=step;

            val-=fn[i];

        }

    return i+1;

}



int main()

{

    fin>>n;

    for(int i=1;i<=n;i++)

    {

        fin>>v[i];

        add(i,1);

    }

    for (int i=n;i>=1;i--)

    {

        int poz=find(v[i]);

        rez[poz]=i;

        add(poz,-1);

    }

    for (int i = 1; i<=n; i++)

        fout << rez[i] << "\n";

}
