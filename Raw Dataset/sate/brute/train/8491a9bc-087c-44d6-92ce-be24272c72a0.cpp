#include <fstream>
#include <vector>
using namespace std;
ifstream cin("sate.in");
ofstream cout("sate.out");
vector<vector<int>>G;
vector<vector<int>>H;
int main()
{
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    G = vector<vector<int>>(N + 1);
    H = vector<vector<int>>(N + 1);
    int x, y, cost;
    for(int i = 1; i <= M; i++){
        cin >> x >> y >> cost;
        G[x].push_back(y); H[x].push_back(cost);
        G[y].push_back(x); H[y].push_back(cost);
    }
    const int k = 30010;
    int coada[k] = {}, viz[k] = {}, inc = 1, Sf = 1, l = 1, sol[k] = {};
    coada[1] = X;
    viz[X] = 1;
    while(inc <= Sf){
        int nc = coada[inc];
        //for(int j: G[nc])
        for(int i = 0; i < G[nc].size(); i++){
            int j = G[nc][i];
            if(viz[j] == 0){
                Sf++;
                coada[Sf] = j;
                if(nc > j)
                    sol[j] = sol[nc] - H[nc][i];
                else
                    sol[j] = sol[nc] + H[nc][i];
                viz[j] = 1;
            }
        }
        inc++;
    }

    cout << sol[Y];
    return 0;
}
