#include <bits/stdc++.h>






using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

struct tip

{

    long double x;

    long double y;

};

tip v[100005];

int i,j;

long double sol,dist;

inline long double get_dist(const tip &a, const tip &b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

inline bool cmp(const tip &a, const tip &b)

{

    return a.x<b.x;

}

int main()

{int n;

f>>n;

for(i=1;i<=n;i++)

    f>>v[i].x>>v[i].y;

sort(v+1,v+n+1,cmp);

sol=get_dist(v[1],v[2]);

for(i=1;i<=n;i++)

    for(j=i-1;j>0 and v[i].x-v[j].x<sol;j--)

    {

        dist=get_dist(v[j],v[i]);

        if(dist<sol) sol=dist;

    }

g<<fixed<<setprecision(6)<<sol;



    return 0;

}
