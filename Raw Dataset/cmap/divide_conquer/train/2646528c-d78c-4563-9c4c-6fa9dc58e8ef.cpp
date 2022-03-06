#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



const int N=100001;

const int MAX=2000000001;

pair <long long,long long>p[N];

pair <long long,long long>a[N];

int n;



double dist(long long x1,long long y1,long long x2,long long y2)

{

    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

}



double divide(int st,int dr)

{

    if(dr-st<=2)

    {

        double d=MAX;

        for(int i=st;i<dr;i++)

        {

            for(int j=i+1;j<=dr;j++)

            {

                d=min(d,dist(p[i].first,p[i].second,p[j].first,p[j].second));

            }

        }

        return d;

    }

    int mij=(st+dr)/2;

    double dmin=min(divide(st,mij),divide(mij,dr));

    mij=(st+dr)/2;

    int top=0;

    for(int i=st;i<=dr;i++)

    {

        if(p[i].first>=p[mij].first-dmin&&p[i].first<=dmin+p[mij].first)

        {

            a[++top]=make_pair(p[i].second,p[i].first);

        }

    }

    sort(a+1,a+top+1);

    for(int i=1;i<top;i++)

    {

        for(int j=i+1;j<=top&&j<=i+7;j++)

        {

            dmin=min(dmin,dist(a[i].first,a[i].second,a[j].first,a[j].second));

        }

    }

    return dmin;

}



int main()

{

    fin>>n;

    for(int i=1;i<=n;i++)

    {

        fin>>p[i].first>>p[i].second;

    }

    sort(p+1,p+n+1);

    fout<<fixed<<setprecision(6)<<divide(1,n);

    return 0;

}
