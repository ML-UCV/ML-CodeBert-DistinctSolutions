#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>




using namespace std;

typedef struct{

int x,y;

}punct;

punct p[100010];

int i,j,n;

long long sol;

long long dist(punct a,punct b)

{

    return (long long)((long long)(a.x-b.x)*(a.x-b.x)+(long long)(a.y-b.y)*(a.y-b.y));

}

bool cmp(punct a,punct b)

{

    return a.x<b.x;

}



int main()

{

    ifstream fi("cmap.in");

    ofstream fo("cmap.out");

    fi>>n;

    for(i=0;i<n;i++)

    fi>>p[i].x>>p[i].y;

    sort(p,p+n,cmp);

    sol=(1LL<<61);

    for(i=0;i<n;i++)

    for(j=i+1;j<=i+3 and j<n;j++)

        if(dist(p[i],p[j])<sol) sol=dist(p[i],p[j]);

    fo<<setprecision(6)<<fixed;

    fo<<sqrt((double)sol)<<"\n";

    return 0;

}
