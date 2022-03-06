#include <bits/stdc++.h>


using namespace std;



pair < double , double > v[100002];



inline double dist(int i, int j)

{

    return sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second));

}



int main()

{

    ifstream f("cmap.in");

    ofstream g("cmap.out");

    int n;

    f>>n;

    for(int i=1;i<=n;i++)

        f>>v[i].first>>v[i].second;

    sort(v+1,v+n+1);



    double vmin=dist(1,2);

    for(int i=1;i<=n-1;i++)

        for(int j=i+1;j<=n && fabs(v[j].first-v[i].first)<=vmin;j++)

        {

            double x=dist(i,j);

            if(x<vmin)

                vmin=x;

        }



    g<<setprecision(6)<<fixed<<vmin<<'\n';

    f.close();

    g.close();

    return 0;

}
