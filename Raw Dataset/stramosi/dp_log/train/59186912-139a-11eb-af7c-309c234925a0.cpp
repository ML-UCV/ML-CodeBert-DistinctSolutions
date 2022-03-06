#include <fstream>
#include <algorithm>


using namespace std;



ifstream cin("stramosi.in");

ofstream cout("stramosi.out");



int N, M;

int dp[20][250005];



int main()

{

    int query1, query2, pas;

    cin >> N >> M;

    for(int i = 1; i <= N; i++){

        cin >> dp[0][i];

    }

    for(int i = 1; i < 20; i++){

        for(int j = 1; j <= N; j++){

            dp[i][j] = dp[i-1][dp[i - 1][j]];

        }

    }

    for(int i = 1; i <= M; i++){

        cin >> query1 >> query2;

        pas = 0;

        while(query2 != 0){

            if(query2 % 2 != 0){

                query1 = dp[pas][query1];

            }

            query2 >>= 1;

            ++pas;

        }

        cout << query1 << "\n";

    }

    return 0;

}
