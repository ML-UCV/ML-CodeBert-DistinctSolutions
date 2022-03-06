#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
vector < pair <int, int > > graf[30001];
int D, dis, x, y, Nods, Arcs, Origin, End, i, a[4], nr, k, j;
char S[31];
bool ok, viz[30001];
void dfs(int node){
    viz[node] = 1;
    for(int i = 0; i < graf[node].size(); i++){
        if(ok == 1)
            return;
        if(viz[graf[node][i].first] == 0){
            D = D + graf[node][i].second;
            if(graf[node][i].first == End){
                g << D;
                ok = 1;
            }
            dfs(graf[node][i].first);
            D = D - graf[node][i].second;
        }
    }
}
int main()
{   f >> Nods >> Arcs >> Origin >> End;
    f.get();
    for(i = 1; i <= Arcs; i++){
        f.getline(S, 31);
        k = 0;
        for(j = 1; j <= 3; j++){
            nr = 0;
            while(S[k] >= '0' && S[k] <= '9'){
                nr = nr * 10 + (S[k] - '0');
                k++;
            }
            while(S[k] == ' ')
                k++;
            a[j] = nr;
        }
        if(a[1] > a[2])
            swap(a[1], a[2]);
        graf[a[1]].push_back({a[2], a[3]});
        graf[a[2]].push_back({a[1], -a[3]});
    }
    dfs(Origin);
    return 0;
}
