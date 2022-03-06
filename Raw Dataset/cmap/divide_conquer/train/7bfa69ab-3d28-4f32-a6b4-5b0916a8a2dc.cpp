#include<fstream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

typedef pair<long long,long long> pii;

pii a[100005];

pii r[100005];

pii v[100005];

int n,ps,pd;

long long dist(pii A,pii B)

{

    return (long long)(A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second);

}

long long re(int st,int dr)

{

    int m=0;

    if(st==dr)

        return 1000000000000000000000LL;

    int mij=(st+dr)/2;

    long long rez=min(re(st,mij),re(mij+1,dr));

    ps=st;

    pd=mij+1;

    for(int i=st;i<=dr;i++)

        if((a[ps].second<a[pd].second||pd>dr)&&ps<=mij)

        {

            v[i]=a[ps];

            ps++;

        }

        else

        {

            v[i]=a[pd];

            pd++;

        }

    for(int i=st;i<=dr;i++)

        a[i]=v[i];

    for(int i=st;i<=dr;i++)

        if(abs(a[i].first-a[mij].first)<=rez)

        {

            m++;

            r[m]=a[i];

        }

    for(int i=1;i<=m;i++)

        for(int j=max(1,i-7);j<i;j++)

            rez=min(rez,dist(r[j],r[i]));

    return rez;

}

long long t;

int main()

{

    fin>>n;

    for(int i=1;i<=n;i++)

        fin>>a[i].first>>a[i].second;

    sort(a+1,a+n+1);

    t=re(1,n);

    fout<<fixed<<setprecision(6)<<sqrt(t);

}
