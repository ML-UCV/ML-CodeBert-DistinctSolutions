#include <iostream>
#include <queue>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>





using namespace std;

pair<long long,long long> v[100010];
long long n,i,j ,m,ans;

double dist( pair<long long,long long> a, pair<long long,long long> b ){
  return sqrt( (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) );
}

bool cmp( pair<long long,long long> a, pair<long long,long long> b ){
  if( a.second > b.second ) return true;
  else if( a.second < b.second ) return false;
  if( a.first >= b.first ) return true;
  return false;
}

long double cmapip( long long left, long long right ){
  long long middle = ( left + right ) / 2;
  double ans = 2000000000;
  if( right - left <= 3 ){
    for( long long i = left ; i <= right ; i++ ){
      for( long long j = i + 1 ; j <= right ; j++ ){
        ans = min( ans , dist( v[ i ] , v[ j ] ) );
      }
    }
    return ans;
  }
  ans = min( cmapip( left , middle ) , cmapip( middle + 1 , right ) );
  vector< pair<long long,long long> > vec;
  for( int i = left ; i <= right ; i++ ){
    if( abs( v[ i ].first - v[ middle ].first ) <= ans ){
      vec.push_back( v[ i ] );
    }
  }
  int l = vec.size();
  sort(vec.begin(), vec.end(), [](auto &left, auto &right) {
    return left.second < right.second;
});
  for( int i = 0 ; i < l ; i++ ){
    for( int j = i + 1 ; j < min( l , i + 8 ) ; j++ ){
      ans = min( ans , dist( vec[ i ] , vec[ j ] ) );
    }
  }
  return ans;
}

int main(){

  ifstream cin("cmap.in");
  ofstream cout("cmap.out");

  cin >> n;
  for( long long i = 1 ; i <= n ; i++ ){
    cin >> v[ i ].first >> v[ i ].second;
  }
  sort( v + 1 , v + n + 1 );
  cout << fixed << setprecision(7) << cmapip( 1 , n );

return 0;
}
