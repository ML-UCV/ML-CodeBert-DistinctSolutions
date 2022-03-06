#include <fstream>
#include <vector>
#include <set>
using namespace std;
ifstream cin("apm.in");
ofstream cout("apm.out");
int n ,m ;
set <pair<int,pair<int,int>>> s;
vector <pair<int,int>> L[1000001],sol;
int costmin;
int ans,viz[1000001];
int main() {
    int x , y ,cost;
    cin >> n >> m;
    for(int i =1 ;i <=m; i ++)
    {
        cin >> x >> y >> cost;
        L[x].push_back({y,cost});
        L[y].push_back({x,cost});
    }
    viz[1] = 1;
    for(auto i:L[1])
        s.insert({i.second,{1,i.first}});
    for(int i =2 ;i <=n ;i ++)
    {
        auto nod= s.begin();
        while(true){
            nod = s.begin();
            if(viz[nod ->second.second])
                s.erase(nod);
            else
            {
                break;
            }
        }
        sol.push_back(nod->second);
        viz[nod->second.second] =1;
        costmin +=nod->first;
        for(auto j : L[nod ->second.second])
        {
            s.insert({j.second, {nod ->second.second, j.first}});
        }
    }
    cout <<costmin<<'\n'<<n -1<<'\n';
    for(auto i :sol)
    {
        cout << i.first <<" "<<i.second<<'\n';
    }
    return 0;
}
