#include <bits/stdc++.h>






using namespace std;



vector <pair<long long,long long> > v;

long long dist(pair <long long,long long> a,pair<long long,long long> b)

{

    long long p1x=a.first;

    long long p1y=a.second;

    long long p2x=b.first;

    long long p2y=b.second;

    return ((p1x-p2x)*(p1x-p2x)+(p1y-p2y)*(p1y-p2y));

}

long long divideEtImpera(long long st,long long dr)

{

    long long mij,minL,minR;

    long long d;

    if(dr-st<=3)

    {

        long long minim=1e18;

        unsigned int i,j;

        for(i=st;i<=dr;i++)

        {

            for(j=i+1;j<=dr;j++)

            {

                minim=min(minim,dist(v[i],v[j]));

            }

        }

        return minim;

    }

    unsigned int i,j;

    mij=st+(dr-st)/2;

    d=min(divideEtImpera(st,mij),divideEtImpera(mij+1,dr));

    vector < pair<long long,long long> > new_v;

    for(i=st;i<=dr;i++)

    {

        if(abs(v[mij].first-v[i].first)<d)

        {

            new_v.push_back({v[i].second,v[i].first});

        }

    }

    sort(new_v.begin(),new_v.end());

    for(i=0;i<new_v.size();i++)

    {

        for(j=i+1;j<new_v.size() && j < i + 8;j++)

        {

                long long new_d;

                new_d=dist(new_v[i],new_v[j]);

                if(new_d<d)

                {

                    d=new_d;

                }

            }

    }

    return d;

}

int main()

{

    ifstream fin("cmap.in");

    ofstream fout("cmap.out");

    int n,i,j;

    long long a,b;

    double f;

    double min=999999999;

    fin>>n;

    for(i=1;i<=n;i++)

    {

        fin>>a>>b;

        v.push_back({a,b});

    }

    long long dist_best=1e9;

    sort(v.begin(),v.end());

    dist_best=divideEtImpera(0,n-1);

    fout<<fixed<<setprecision(6)<<sqrt((double)dist_best);

    fin.close();

    fout.close();

    return 0;

}
