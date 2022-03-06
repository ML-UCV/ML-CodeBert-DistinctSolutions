#include <bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, l, sol;

pair<int, int> p[100005];

vector<int> graph[100005], out[100005];

stack<int> stk;

bitset<100005> check, inS;



void dfs(int now);



int main()

{



    fin >> n >> m;

    while(m--){

        int x, y;

        fin >> x >> y;



        graph[x].push_back(y);

    }



    for(int i = 1; i <= n; ++i){

        if(!check[i]) dfs(i);

    }



    fout << sol << "\n";

    for(int i = 1; i <= sol; ++i){

        for(auto it:out[i]) fout << it << " ";

        fout << "\n";

    }



    return 0;

}



void dfs(int now){

    ++l;

    p[now] = {l, l};

    check[now] = inS[now] = true;

    stk.push(now);



    for(auto next:graph[now]){

        if(!check[next]){

            dfs(next);

            p[now].second = min(p[now].second, p[next].second);

        }

        else if(inS[next]) p[now].second = min(p[now].second, p[next].first);

    }



    if(p[now].first == p[now].second){

        ++sol;



        while(stk.top() != now){

            out[sol].push_back(stk.top());

            inS[stk.top()] = false;

            stk.pop();

        }



        out[sol].push_back(stk.top());

        inS[stk.top()] = false;

        stk.pop();

    }



}
