#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");



const int mod=9917;

const int nmax=100005;



int n,aib[nmax];



struct arr

{

    int val,poz;

}v[nmax];



bool cmp(arr a,arr b)

{

    return (a.val>b.val || (a.val==b.val && a.poz>b.poz));

}



void read()

{

    fin>>n;



    for(int i=1;i<=n;i++)

    {

        fin>>v[i].val;

        v[i].poz=i;

    }



    sort(v+1,v+n+1,cmp);

}



void update(int poz)

{

    for(;poz<=n;poz+= poz & -poz)

        aib[poz]++;

}



int query(int poz)

{

    int ans=0;



    for(;poz;poz-= poz & -poz)

        ans+=aib[poz];



    return ans;

}



void solve()

{

    int ans=0;



    for(int i=1;i<=n;i++)

    {

        ans=ans+query(v[i].poz-1);

        ans%=mod;



        update(v[i].poz);

    }



    fout<<ans;

}



int main()

{

    read();

    solve();



    return 0;

}
