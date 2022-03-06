#include <bits/stdc++.h>




using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



vector<pair<int,pair<int,int> > >muchii;

int n,m,t[200001],h[200001];

vector<pair<int,int> >sol;



bool muchie(int x,int y)

{



    int x1,y1,r1=x,r2=y,c;



    while(r1!=t[r1])

        r1=t[r1];



    while(r2!=t[r2])

        r2=t[r2];



    while(r1!=t[x])

    {

        x1=t[x];

        t[x]=t[x1];

        x=x1;

    }



    while(r2!=t[y])

    {

        y1=t[y];

        t[y]=t[y1];

        y=y1;

    }



    if(r1==r2)return false;



    if(h[r1]>h[r2])

    {

        t[r2]=r1;

        c=r1;

    }

    else

    {

        t[r1]=r2;

        c=r2;

    }



    if(h[r1]==h[r2])

        h[c]++;



    return true;



}



int main()

{

    f>>n>>m;

    for(int i=1;i<=m;++i)

    {

        int x,y,c;

        f>>x>>y>>c;

        muchii.push_back(make_pair(c,make_pair(x,y)));

    }

    sort(muchii.begin(),muchii.end());



    for(int i=1;i<=n;++i)

    {

        t[i]=i;

        h[i]=1;

    }



    n--;

    int sol2=n,cost=0;

    int i=0;

    while(n)

    {



        if(muchie(muchii[i].second.first,muchii[i].second.second))

        {

            n--;

            cost+=muchii[i].first;

            sol.push_back(make_pair(muchii[i].second.first,muchii[i].second.second));

        }

        i++;



    }

    g<<cost<<'\n'<<sol2<<'\n';

    for(int i=0;i<sol.size();++i)

    {



        g<<sol[i].first<<" "<<sol[i].second<<'\n';



    }





    return 0;

}
