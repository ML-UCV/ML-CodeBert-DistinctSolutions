#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct point {

int x, y;

};





point v[100000], aux[100000];

inline long long square( int x ) {

return ( long long ) x * x;}

inline double edist( point a, point b ) {

return sqrt( square( a.x - b.x ) + square( a.y - b.y ) );}

inline bool cmp( point a, point b ) {

return ( a.x < b.x );}

void read( FILE *fin, int &n ) {

fscanf( fin, "%d", &n );

for ( int i = 0; i < n; ++i )

fscanf( fin, "%d%d", &v[i].x, &v[i].y );}

void merge( int left, int middle, int right ) {

int i = left, j = middle + 1, pos = left - 1;

while ( i <= middle && j <= right )

if ( v[i].y <= v[j].y ) {

aux[++pos] = v[i];

++i;

} else {

aux[++pos] = v[j];

++j;}

while ( i <= middle ) {

aux[++pos] = v[i];

++i;}

while ( j <= right ) {

aux[++pos] = v[j];

++j;}

for ( i = left; i <= right; ++i )

v[i] = aux[i];}

double min_dist( int left, int right ) {

if ( left >= right )

return 1000000000.0;

if ( left + 1 == right )

return edist( v[left], v[right] );

int middle = ( left + right ) >> 1, x_mid = v[middle].x;

double dist_left = min_dist( left, middle ), dist_right = min_dist( middle + 1, right );

double dist = min( dist_left, dist_right );

merge( left, middle, right );

int count = 0;

for ( int i = left; i <= right; ++i )

if ( abs( v[i].x - x_mid ) <= dist )

aux[++count] = v[i];

double res = dist;

for ( int i = 1; i <= count; ++i )

for ( int j = i + 1; j <= count && j < i + 8; ++j )

res = min( res, edist( aux[i], aux[j] ) );

return res;}

int main() {

FILE *fin, *fout;

fin = fopen ( "cmap.in", "r" );

int n;

read( fin, n );

fclose( fin );

sort( v, v + n, cmp );

fout = fopen( "cmap.out", "w" );

fprintf( fout, "%.6f\n", min_dist( 0, n - 1 ) );

fclose( fout );}
