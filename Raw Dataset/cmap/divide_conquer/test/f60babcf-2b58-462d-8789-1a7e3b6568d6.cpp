#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>






using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");

int n;

long double mn;

pair<int,int> v[100001];

vector<pair<int,int> > A,B;



bool comp(pair<int,int> a, pair<int,int> b)

{

    return a.first<b.first;

}



long double dist(pair<int,int> a, pair<int,int> b)

{

    if(a==b)

        g<<"NU";

    return sqrt(((long double)(a.first-b.first) * (a.first-b.first)) + ((long double)(a.second-b.second) * (a.second-b.second)));

}



bool comp2(pair<int,int> a,pair<int,int> b)

{

    return a.second<b.second;

}



long double divide(int a,int b)

{

    if (b-a+1<=1)

        return 1e9;



    long double mn = min(divide(a,(a+b)/2),divide((a+b)/2+1,b));



    A.clear();

    B.clear();



    for (int i=(a+b)/2;v[i].first>=v[(a+b)/2].first - mn && i>=a;i--)

        A.push_back(v[i]);

    sort(A.begin(),A.end(),comp2);



    for (int i=(a+b)/2+1;v[i].first<=v[(a+b)/2+1].first + mn && i<=b;i++)

        B.push_back(v[i]);

    sort(B.begin(),B.end(),comp2);



    int i1 = 0,i2 = 0;

    while (i1<A.size() && i2<B.size())

    {



        for(int i3 = max(0,i2 - 2) ;i3 < min((int)B.size(), i2+3);i3++)

        {
            mn = min(mn,dist(A[i1],B[i3]));

        }



        if (A[i1].second<B[i2].second)

            i1++;

        else

            i2++;

    }



    return mn;

}



int main()

{
    f>>n;

    for (int i=1;i<=n;i++)

    {

        int x,y;

        f>>x>>y;

        v[i] = make_pair(x,y);

    }



    sort(v+1,v+n+1,comp);



     long double x = divide(1,n);



    g<<fixed;

    g<<setprecision(7)<<x;



    return 0;

}
