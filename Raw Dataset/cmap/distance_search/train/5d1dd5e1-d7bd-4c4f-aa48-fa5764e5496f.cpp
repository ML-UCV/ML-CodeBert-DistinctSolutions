#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <set>
#include <algorithm>




using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



struct Point{

long long x,y;

bool operator< (const Point b) const

{

    return y < b.y;

}

};



Point a[100010];



long long n;



long long dist(Point a, Point b)

{

    return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);

}



bool XComparer(Point a,Point b)

{

    return a.x<b.x;

}





int main()

{



    fin>>n;

    long long H = (1LL<<60);

    for(long long i=1;i<=n;i++)

        fin>>a[i].x>>a[i].y;



    sort(a+1,a+1+n, XComparer);



    for(long long i=2;i<=n;i++)

        H = min(H,dist(a[i],a[i-1]));



    multiset<Point> Set;

    multiset<Point>::iterator in, sf;



    long long act=1;



    Point tmp;



    for(long long i=1;i<=n;i++)

    {

        while(act <= n && (a[act].x - a[i].x) * (a[act].x - a[i].x) < H )

        {

            Set.insert(a[act]);

            act++;

        }

        tmp.y = a[i].y - H + 1;

        in = Set.lower_bound(tmp);

        tmp.y = a[i].y + H - 1;

        sf = Set.upper_bound(tmp);





        while(in!= sf )

        {

            if(a[i].x != in->x || a[i].y != in->y)

                H = min(H,dist(a[i], *in ));



                in++;

        }





        in = Set.lower_bound(a[i]);

        Set.erase(in);





    }



    fout<<setprecision(6)<< fixed<< sqrt((double) H) <<'\n';





    return 0;

}
