#include<bits/stdc++.h>


using namespace std;





ifstream in("stramosi.in");

ofstream out("stramosi.out");



int n,query_count;

int father[250001];

int stramosi[20][250001];







void read()

{

    in>>n>>query_count;

    for(int i=1; i<=n; i++)

    {

        in>>father[i];

    }

}



void precompute()

{

    for(int i=1; i<=n; i++)

    {

        stramosi[0][i]=father[i];

    }



    for(int k=1; k<=log2(n); k++)

    {

        for(int i=1; i<=n; i++)

        {

            stramosi[k][i]=stramosi[k-1][stramosi[k-1][i]];

        }

    }

}







int n_father(int n,int q)

{

    while(q)

    {

        int l=q&(-q);

        int lg=log2(l);

        n=stramosi[lg][n];

        q-=l;

    }

    return n;

}







int main()

{

    read();

    precompute();

    int a,b;

    for(int i=0;i<query_count;i++){

        in>>a>>b;

        out<<n_father(a,b)<<'\n';

    }

}
