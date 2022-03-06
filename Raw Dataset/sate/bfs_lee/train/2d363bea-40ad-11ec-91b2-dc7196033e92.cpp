#include <fstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector< pair<int, int> > v[30005];
int n, m, home, town, d[30005];

int main()
{
    ifstream fin ("sate.in");
    ofstream fout ("sate.out");
    fin >> n >> m >> home >> town;
    while(m--){
        int x, y, z;
        fin >> x >> y >> z;
        if(x > y)
            swap(x, y);
        v[x].push_back(make_pair(y, z));
        v[y].push_back(make_pair(x, -z));
    }
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(home);
    d[home] = 0;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (unsigned i = 0; i < v[k].size(); ++i)
            if((d[v[k][i].first] == -1 || d[v[k][i].first] > d[k] + v[k][i].second) && v[k][i].first != home){
                d[v[k][i].first] = d[k] + v[k][i].second;
                q.push(v[k][i].first);
            }
    }
    fout << d[town] << "\n";
    fin.close();
    fout.close();
    return 0;
}
