#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int N, M, i, j, V, VP;

pair<int, int> P[100001];

vector<vector<int> > Graph(100001);

vector<vector<int> > Sol; vector<int> Empty;

stack<int> S;

bool Check[100001], SCheck[100001];

void DFS(int i);

int main()

{

    freopen("ctc.in", "r", stdin);

    freopen("ctc.out", "w", stdout);

    scanf("%d%d", &N, &M);

    Sol.push_back(Empty);

    for(i=1; i<=N; ++i) Graph[i].push_back(0);

    for(i=1; i<=M; ++i){

        int x, y;

        scanf("%d%d", &x, &y);

        Graph[x].push_back(y);

        ++Graph[x][0];

    }

    for(i=1; i<=N; ++i)

        if(Check[i]==false) DFS(i);

    printf("%d\n", V);

    for(i=1; i<=V; ++i){

        for(j=0; j<Sol[i].size(); ++j) printf("%d ", Sol[i][j]);

        printf("\n");

    }

    return 0;

}

void DFS(int i){

    P[i].first=P[i].second=++VP;

    Check[i]=SCheck[i]=true;

    S.push(i);

    int j;

    for(j=1; j<=Graph[i][0]; ++j){

        if(Check[Graph[i][j]]==false){

            DFS(Graph[i][j]);

            P[i].second=min(P[i].second, P[Graph[i][j]].second);

        }

        else if(SCheck[Graph[i][j]]==true) P[i].second=min(P[i].second, P[Graph[i][j]].first);

    }

    if(P[i].first==P[i].second){

        ++V;

        Sol.push_back(Empty);

        while(S.top()!=i){

            Sol[V].push_back(S.top());

            SCheck[S.top()]=false;

            S.pop();

        }

        Sol[V].push_back(S.top());

            SCheck[S.top()]=false;

            S.pop();

    }

    return;

}
