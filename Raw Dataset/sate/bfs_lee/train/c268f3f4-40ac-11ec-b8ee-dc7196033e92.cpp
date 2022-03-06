
#include<bits/stdc++.h>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector<pair<int, int>> graph[30001];
int distances[30001];
int visited[30001];

int main()
{
    int n,m,x,y,i,d,curr,neigh,distance,a,b;
    fin>>n>>m>>x>>y;
    for(i=0;i<m;i++){
        fin>>a>>b>>d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, -d});
    }
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    int found = 0;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        for(auto i:graph[curr]){
            neigh = i.first;
            distance = i.second;
            if(!visited[neigh]){
                visited[neigh] = 1;
                distances[neigh] = distances[curr] + distance;
                q.push(neigh);

                if(neigh == y){
                    fout<<distances[y]<<"\n";
                    cout<<distances[y];
                    found = 1;
                    break;
                }
            }
        }
        if(found){
           break;
        }
    }


    return 0;
}
