#include <fstream>
using namespace std;

ifstream cin("stramosi.in");

ofstream cout("stramosi.out");

int logs[250001],n,parent[18][250001];

void build(){

    for(int i = 1;(1 << i) <= n;i++){

        for(int j = 1;j <= n;j++){

            parent[i][j] = parent[i - 1][parent[i-1][j]];

        }

    }

}

int main()

{

    int i,m,x,y;

    cin >> n >> m;

    for(i = 1;i <= n;i++){

        cin >> x;

        parent[0][i] = x;

    }

    build();

    while(m--){

        cin >> x >> y;

        int r = 0,pas = 18,rez = 0,ii = x;

        while(pas >= 0){

                if(r + (1 << pas) <= y){

                    ii = parent[pas][ii];

                    r += (1 << pas);

                }

            pas--;

        }

        cout << ii << "\n";

    }

    return 0;

}
