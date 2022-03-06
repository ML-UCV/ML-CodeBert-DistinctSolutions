#include <bits/stdc++.h>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

int hash1a,hash2a,hash1b,hash2b;

char a[2000007],b[2000007];

vector<int> v;

int put1,put2;

int main()

{int lg1,i,lg2;

    fin.getline(a,2000007);

    fin.getline(b,2000007);

        lg1=strlen(a);

        lg2=strlen(b);

    put1=put2=1;

    if(lg1>lg2)

    {fout<<0;return 0;}

    for(i=0;i<lg1;i++)

    {

        hash1a=(hash1a*73 +a[i])%100019;

        hash2a=(hash2a*73 +a[i])%100021;

        hash1b=(hash1b*73 +b[i])%100019;

        hash2b=(hash2b*73 +b[i])%100021;

        if(i!=0)

            put1=(put1*73)%100019,put2=(put2*73)%100021;

    }

    if(hash1a==hash1b&&hash2a==hash2b)

        v.push_back(0);

    for(i=lg1;i<lg2;i++)

    {

        hash1b=((hash1b-(b[i-lg1]*put1)%100019 +100019)*73 +b[i])%100019;

        hash2b=((hash2b-(b[i-lg1]*put2)%100021 +100021)*73 +b[i])%100021;

        if(hash1a==hash1b&&hash2a==hash2b)

        v.push_back(i-lg1+1);

    }

    fout<<v.size()<<'\n';

    for(i=0;i<v.size()&&i<1000;i++)

        fout<<v[i]<<' ';

    return 0;

}
