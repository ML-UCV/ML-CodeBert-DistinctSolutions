#include<bits/stdc++.h>
using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");



const int NMAX=50005;



int n,m,len,fra[30],frb[30],AIB[NMAX];

char a[NMAX],b[NMAX];

long long sol;

queue<int>Q[30];



inline int zeros(int x)

{

    return x^(x&(x-1));

}



inline void Update(int poz,int val)

{

    for (int i=poz;i<=n;i+=zeros(i)) AIB[i]+=val;

}



inline int Query(int poz)

{

    int i,rez=0;

    for (i=poz;i>=1;i-=zeros(i)) rez+=AIB[i];

    return rez;

}



int main()

{

    int i,j,aux,poz;

    int C;

    bool ok;

    fin>>(a+1)>>(b+1);

    n=strlen(a+1);m=strlen(b+1);

    for (i=1;i<=n;i++) fra[a[i]-'a'+1]++;

    for (i=1;i<=m;i++) frb[b[i]-'a'+1]++;

    ok=1;

    for (i=1;i<=26;i++)

        if (fra[i]!=frb[i])

            ok=0;

    if (ok==0) {fout<<"-1";return 0;}

    for (i=1;i<=n;i++) Q[a[i]-'a'+1].push(i);

    for (i=1;i<=m;i++)

        {

            C=b[i]-'a'+1;poz=Q[C].front();

            aux=Query(n)-Query(poz-1);

            sol+=aux+poz-i;

            Update(poz,1);

            Q[C].pop();

        }

    fout<<sol<<"\n";

    return 0;

}
