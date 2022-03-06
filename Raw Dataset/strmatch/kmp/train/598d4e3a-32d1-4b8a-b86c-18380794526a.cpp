#include <iostream>
#include <fstream>


using namespace std;

const int N = 2e6;
const int M = 2e6;
char txt[N], pat[M];
int lps[M];
int result[N];
int n, m;

ifstream fin ( "strmatch.in" );
ofstream fout ( "strmatch.out" );

void process_lps () {

    lps[0] = 0;

    int i = 1, len = 0;
    while ( i < m ) {
       if ( pat[i] == pat[len] ) {
         len ++ ;
         lps[i] = len;
         i ++;
       }
       else if ( len != 0 )
         len = lps[len-1];
       else
         len = 0, i ++;
    }
}


int main()

{

   char ch;
   m = 0;
   ch = fin.get ();

   while ( ch != '\n' ){
      pat[m++] = ch;
      ch = fin.get ();
   }

   n = 0, ch = fin.get ();
   while ( ch != EOF && ch != '\n' ){
      txt[n++] = ch;
      ch = fin.get ();
   }

   process_lps ();

   int i = 0, j = 0;
   int n_res = 0;
   while ( i < n ) {
      if ( pat[j] == txt[i] )
        i ++, j ++;
      if ( j == m ) {
        result[n_res++] = i - j;
        j = lps[j-1];
      }
      else if ( i < n && pat[j] != txt[i] ){
        if ( j > 0 )
          j = lps[j-1];
        else
          i ++;
      }
   }

   fout << n_res << '\n';
   for ( int i = 0; i < min ( n_res, 1000 ); i ++ )
      fout << result[i] << ' ';

    return 0;

}
