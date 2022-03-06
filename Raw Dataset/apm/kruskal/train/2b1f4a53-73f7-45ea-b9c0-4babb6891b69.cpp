#include <fstream>
#include <algorithm>



using namespace std;
ifstream in ( "apm.in" );
ofstream out( "apm.out" );
struct potae{
    int x, y, cost;
} v[200200], sol[200200];
int n, m, i, t[200200], much, rx, ry, total;

bool cmp ( potae a, potae b ){
    return a.cost < b.cost;
}

int rad ( int a ){
    while ( t[a] > 0 )
        a = t[a];
    return a;
}

int main() {
    in>>n>>m;
    for ( i=1; i <= m; i++ )
        in>>v[i].x>>v[i].y>>v[i].cost;

    sort( v+1, v+m+1, cmp );

    for ( i=1; i <= n; i++ )
        t[i] = -1;
    for ( i=1; i <= m && much < n; i++ ){
        rx = rad( v[i].x );
        ry = rad( v[i].y );
        if ( rx == ry )
            continue;
        if ( t[rx] < t[ry] ){
            t[rx] += t[ry];
            t[ry] = rx;
        } else {
            t[ry] += t[rx];
            t[rx] = ry;
        }
        sol[++much] = { v[i].x, v[i].y };
        total += v[i].cost;
    }
    out<<total<<"\n"<<n-1<<"\n";
    for ( i=1; i < n; i++ )
        out<<sol[i].x<<" "<<sol[i].y<<"\n";
    return 0;
}
