#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
vector < pair < double, int > > v[ 1505 ];

priority_queue < pair < double, int > > Q;



double dist[ 1505 ];

int in_queue[ 1505 ];

int dinamica[ 1505 ];



void aflaDrumuri( int nod ){



    int i, k, fiu;

    double cost;



    dist[ nod ] = 0;

    dinamica[ nod ] = 1;

    Q.push( { 0.0, nod } );



    while( !Q.empty() ){

        nod = Q.top().second;

        Q.pop();

        if( in_queue[ nod ] ) continue;

        in_queue[ nod ] = 1;

        for( i = 0; i < v[ nod ].size(); ++i ){

            fiu = v[ nod ][ i ].second;

            cost = v[ nod ][ i ].first;

            if( dist[ fiu ] - ( dist[ nod ] + cost ) > 1e-10 ){

                dist[ fiu ] = dist[ nod ] + cost;

                dinamica[ fiu ] = dinamica[ nod ];

                Q.push( { -dist[ fiu ], fiu } );

            }

            else if( fabs( dist[ fiu ] - ( dist[ nod ] + cost ) ) < 1e-10 ){

                dinamica[ fiu ] += dinamica[ nod ];

                dinamica[ fiu ] %= 104659;

            }

        }

    }







}



int main()

{



    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);



    int n, m, i, j, s, t, d, k, x, y, c;



    scanf("%d%d",&n,&m);

    while( m-- ){

        scanf("%d%d%d",&x,&y,&c);

        v[ x ].push_back( { log10( c ), y } );

        v[ y ].push_back( { log10( c ), x } );

    }



    for( i = 1; i <= n; ++i )

        dist[ i ] = 10000.0;



    aflaDrumuri( 1 );

    for( i = 2; i <= n; ++i )

        printf("%d ",dinamica[ i ]);





    return 0;



}
