#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



pair <long long, long long> v[100001];



long long dist(long long x1, long long x2, long long y1, long long y2)

{

    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

}



long long distDouaPuncte(int x, int y)

{

    return dist( v[x].first, v[y].first, v[x].second, v[y].second );

}



long long DEI(int st, int dr)

{

    if( dr - st <=3 )

    {

        long long d = distDouaPuncte(0,1);

        if( dr - st ==3 )

        {

            d = min( d, distDouaPuncte(1,2) );

            d = min( d, distDouaPuncte(0,2) );

        }

        return d;

    }



    long long med = st + (dr - st)/2;

    long long d = min( DEI(st, med), DEI(med, dr) );



    vector <pair <long long, long long> > aux;



    for(int i=st;i<dr;i++)

        aux.emplace_back(v[i].second,v[i].first);



    sort(aux.begin(), aux.end());



    for(unsigned int i=0;i<aux.size();i++)

    {

        for(unsigned int j=i+1; j<i+8 && j<aux.size() ;j++)

        {

            d = min(d, dist(aux[i].first ,aux[j].first, aux[i].second, aux[j].second));

        }

    }

    return d;

}



int main()

{

    int n;

    f>>n;

    for(int i=0;i<n;i++)

        f>>v[i].first>>v[i].second;



     sort(v, v+n);



     g<<fixed<< setprecision(6) << sqrt (DEI(0, n));

    return 0;

}
