#include <bits/stdc++.h>






using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

char a[2000010],b[2000010];

int poz,i,pozitiea,pozitieb,pozitie,l1,l2,numar,p1,p2,hasha1,hashb1,hasha2,hashb2;

int v[1010];

int main()

{

    fin>>a>>b;

    l1=strlen(a);

    l2=strlen(b);

    if(l1>l2)

    {

        fout<<0;

        return 0;

    }

    p1=p2=1;

    for(i=0;i<l1;i++)

    {

        hasha1=(hasha1*73%100007 +a[i]%100007)%100007;

        hasha2=(hasha2*73%100021 +a[i]%100021)%100021;



        hashb1=(hashb1*73%100007 +b[i]%100007)%100007;

        hashb2=(hashb2*73%100021 +b[i]%100021)%100021;

        if(i>0)

        {

            p1=(p1*73)%100007;

            p2=(p2*73)%100021;

        }

    }

    if(hasha1==hashb1 && hasha2==hashb2)

        v[++numar]=0;

    for(i=l1;i<l2;i++)

    {

        hashb1=(((hashb1+100007 -(b[i-l1]*p1)%100007)*73%100007)+b[i])%100007;

        hashb2=(((hashb2+100021 -(b[i-l1]*p2)%100021)*73%100021)+b[i])%100021;

        if(hasha1==hashb1 && hasha2==hashb2)

        {

            numar++;

            if(numar<=1000)

                v[numar]=i-l1+1;

        }

    }

    fout<<numar<<'\n';

    numar=min(numar,1000);

    for(i=1;i<=numar;i++)

        fout<<v[i]<<" ";

    return 0;

}
