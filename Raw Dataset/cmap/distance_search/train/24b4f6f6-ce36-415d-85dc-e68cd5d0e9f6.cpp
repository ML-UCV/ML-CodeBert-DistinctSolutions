#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include <math.h>


using namespace std;

class punct{

public:

    unsigned long long x;

    unsigned long long y;

    bool operator <(const punct p2) const

    {

        return x < p2.x;

    }

};

int n, i, j;

punct p[100005];

long long dist(punct p1, punct p2)

{

    return ( (p1.x - p2.x)*(p1.x - p2.x) +

                 (p1.y - p2.y)*(p1.y - p2.y) );

}

int main()

{

    ifstream in("cmap.in");

    ofstream out("cmap.out");

    in>>n;

    for(i=0;i<n;i++)

        in>>p[i].x>>p[i].y;

    sort(p,p+n);

    long long sol=4e18;

    for(i=0;i<n;i++)

        for(j=i+1;j<=i+3 and j<n;j++)

            if(dist(p[i],p[j])<sol)

                sol=dist(p[i],p[j]);

    out<<fixed<<setprecision(6)<<sqrt((double)sol)<<"\n";

    in.close();

    out.close();

    return 0;

}
