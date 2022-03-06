#include<fstream>
#include<iostream>
#include<cstring>
#include<queue>


using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

short r[50005];

int rez,n,f,g;

char a[50005],b[50005];

priority_queue<unsigned short>q[35];

void update(int poz)

{

    while(poz<=n)

    {

        r[poz]--;

        poz+=(poz&(-poz));

    }

}

int sum(int poz)

{

    int sum=0;

    while(poz)

    {

        sum+=r[poz];

        poz-=(poz&(-poz));

    }

    return sum;

}

int main()

{

    fin.getline(a+1,50005);

    fin.getline(b+1,50005);

    n=strlen(a+1);

    for(int i=1;i<=n;i++)

        q[a[i]-'a'].push(i);

    for(int i=n;i>0;i--)

    {

        if(q[b[i]-'a'].empty())

        {

            fout<<-1;

            return 0;

        }

        f=q[b[i]-'a'].top();

        q[b[i]-'a'].pop();

        g=f+sum(f);

        update(f);

        rez+=i-g;

    }

    fout<<rez;

}
