#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

int i,n,j;

long double Min;

struct du{

    int x,y;}points[100003];

    int cmp(du a,du b){

        return a.x<b.x;}

long double dist (du a,du b){

    return sqrt(1ll*(b.x-a.x)*(b.x-a.x)+1ll*(b.y-a.y)*(b.y-a.y));

    }

int main()

{

    f>>n;

    for(i=1;i<=n;i++)

        f>>points[i].x>>points[i].y;

    sort(points+1,points+n+1,cmp);

    Min=(1ll<<60);

    for(i=1;i<=n;i++)

        for(j=i+1;j<=n;j++){

            if(points[j].x-points[i].x>Min)

                break;

            Min=min(Min,dist(points[j],points[i]));

}

g<<setprecision(6)<<fixed<<Min;

    return 0;

}
