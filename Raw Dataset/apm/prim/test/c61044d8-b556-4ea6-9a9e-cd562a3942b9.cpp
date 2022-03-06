#include <iostream>
#include<math.h>
#include<vector>
#include<fstream>
#include<algorithm>
#include<deque>
#include<queue>

using namespace std;

ifstream fin("trees.in");
ofstream fout("trees.out");



const int NR = 2e5 + 10 , oo = 2e9;
int n , m ;
vector < int > d ( NR , oo ) ;
struct node{
    int nod , cost , tata;
};
struct cmp {
    bool operator() ( node i , node j ) {
        return i.cost > j.cost ;
    }
};
ifstream in("apm.in");
ofstream out("apm.out");
priority_queue < node,vector<node>,cmp> pq;
vector < pair < int , int > > v [ NR ] , sol ;
int viz [ NR ] ;
signed main() {
    int x , y , i , z ;
    in >> n >> m ;
    for ( i = 1 ; i <= m ; ++ i ) {
        in >> x >> y >> z ;
        v [ x ].emplace_back( make_pair( y , z ) ) ;
        v [ y ].emplace_back( make_pair( x , z ) ) ;
    }
    d [ 1 ] = 0 ;
    node temp ;
    temp.cost = 0;
    temp.nod = 1;
    temp.tata = -1;
    pq.push(temp);
    int nod ;
    long long sum = 0 ;
    while ( !pq.empty() ) {
        nod = pq.top().nod ;
        node temp2 = pq.top();
        pq.pop();
        if ( viz [ nod ] )
            continue ;
        sum += temp2.cost;
        viz [ nod ] = 1 ;
        sol.push_back(make_pair(temp2.nod,temp2.tata));
        for ( auto it : v [ nod ] ) {
            if ( !viz [ it.first ] ) {
                temp.nod = it.first ;
                temp.cost = it.second ;
                temp.tata = nod ;
                pq.push(temp);
            }
        }
    }
    out << sum << '\n' ;
    out << sol.size() - 1 << '\n' ;
    for ( auto it : sol ) {
        if ( it.second != -1 )
        out << it.second << ' ' << it.first << '\n' ;
    }
    return 0;
}
