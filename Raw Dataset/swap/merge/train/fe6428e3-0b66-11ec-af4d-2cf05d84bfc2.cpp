#include <fstream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

queue<int>v2[27];

int n,i,ap[27],v[50001],rasp,v3[50001];

char s[50001],s2[50001];

void merge_sort(int in,int sf)

{

    if(in==sf)

    {

        return;

    }

    int mij=(in+sf)/2;

    merge_sort(in,mij);

    merge_sort(mij+1,sf);

    int i=in;

    int j=mij+1;

    int poz=in;

    while(i<=mij && j<=sf)

    {

        if(v[i]<=v[j])

        {

            v3[poz]=v[i];

            i++;

        }

        else

        {

            v3[poz]=v[j];

            rasp+=j-poz;

            j++;

        }

        poz++;

    }

    while(i<=mij)

    {

        v3[poz]=v[i];

        i++;

        poz++;

    }

    while(j<=sf)

    {

        v3[poz]=v[j];

        rasp+=j-poz;

        j++;

        poz++;

    }

    for(i=in;i<=sf;i++)

    {

        v[i]=v3[i];

    }

    return;

}

int main()

{

    f>>s;

    n=strlen(s);

    f>>s2;

    for(i=0;i<n;i++)

    {

        ap[s[i]-'a']++;

        v2[s[i]-'a'].push(i);

        ap[s2[i]-'a']--;

    }

    for(i=0;i<='z'-'a';i++)

    {

        if(ap[i]!=0)

        {

            g<<-1;

            return 0;

        }

    }

    for(i=0;i<n;i++)

    {

        v[v2[s2[i]-'a'].front()]=i+1;

        v2[s2[i]-'a'].pop();

    }

    merge_sort(0,n-1);

    g<<rasp;

    return 0;

}
