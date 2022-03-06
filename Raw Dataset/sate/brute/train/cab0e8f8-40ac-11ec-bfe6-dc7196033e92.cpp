#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 30001
#define SZ(x) ((int) (x).size())
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");

int n, m, sizeOf[NMAX], start, finish;
long long sum[NMAX];
vector< pair <int,int> > nodes[NMAX];
void read(){
    f >> n >> m >> start >> finish;
    int x, y, d;
    for (int i = 1; i <= m; i++){
        f >> x >> y >> d;
        nodes[x].push_back(make_pair(y,d));
        nodes[y].push_back(make_pair(x,d));
    }
}
bool findFinish = false;
void euler(int node){
    int i = 0;
    while (i < nodes[node].size()){
        if (findFinish == true)
            break;
        int next = nodes[node][i].first;
        if (next > node)
            sum[next] = sum[node] + nodes[node][i].second;
        else
            sum[next] = sum[node] - nodes[node][i].second;
        nodes[node].erase(nodes[node].begin() + i);
        i--;
        int index = 0;
        bool find_ = false;
        while (index < nodes[next].size() && find_ == false){
            if (nodes[next][index].first == node){
                find_ = true;
                nodes[next].erase(nodes[next].begin() + index);
            }
            index++;
        }
        i++;
        if (next == finish){
            g << sum[next] << "\n";
            findFinish = true;
            break;
        }
        else
            euler(next);
    }
}
int main()
{
    read();
    euler(start);
    return 0;
}
