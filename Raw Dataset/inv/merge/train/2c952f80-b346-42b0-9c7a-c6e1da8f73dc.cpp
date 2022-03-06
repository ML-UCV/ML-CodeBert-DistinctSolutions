#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



const int MOD = 9917 ;

int n ,v[100005] , tmp[100005];

long long sol = 0 ;



void MergeSort(int v[] , int st , int dr){

   if( st < dr ){

      int m = (st + dr) / 2 ;

      MergeSort( v , m+1 , dr ) ;

      MergeSort( v , st , m ) ;



      int i = st , j = m + 1 , k = 0 ;

      long long nr = 0 , rasp = 0 ;

      while( i<=m && j<=dr )

       if( v[i] > v[j] ){

          tmp[++k] = v[j++] ;

          nr++ ;

       }

       else{

          tmp[++k] = v[i++] ;

          rasp+=nr ;

       }

      while(i <= m){

            rasp+=nr ;

            tmp[++k] = v[i++] ;

      }

      while(j <= dr)

            tmp[++k] = v[j++] ;



      sol=(sol+rasp)%MOD ;



      for(i = st , j = 1 ; i <= dr ; i ++ , j ++)

            v[i] = tmp[j];

   }

}

int main()

{

f>>n;

for(int i=1 ; i<=n ; i++){

 f>>v[i] ;

}

MergeSort( v , 1 , n ) ;



g<<sol ;

}
