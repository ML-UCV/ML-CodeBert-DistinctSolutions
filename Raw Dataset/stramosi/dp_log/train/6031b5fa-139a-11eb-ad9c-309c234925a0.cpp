#include <fstream>






using namespace std;







ifstream fin( "stramosi.in" );



ofstream fout( "stramosi.out" );



int dp[250001][19];



int lg[250001];



int main() {



    int n, m, i, j, a, b;



    fin >> n >> m;



    for( i = 1; i <= n; ++i )



        fin >> dp[i][0];



    for( i = 1; i <= n; ++i )



        for( j = 1; j <= 18; ++j )



            dp[i][j] = dp[dp[i][j - 1]][j - 1];



    for( i = 2; i <= n; ++i )



      lg[i] = lg[i >> 1] + 1;



    for( i = 1; i <= m; ++i ) {



        fin >> a >> b;



        for( j = 18; j >= 0; --j )



          if( b & (1 << j) )



            a = dp[a][j];



        fout << a << "\n";



    }



    return 0;



}
