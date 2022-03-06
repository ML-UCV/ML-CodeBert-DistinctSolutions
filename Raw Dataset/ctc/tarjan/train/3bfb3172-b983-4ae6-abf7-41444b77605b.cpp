#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
using namespace std;

const string fileName="ctc";

ifstream in (fileName+".in");

ofstream out(fileName+".out");

const int nmax=1e5;

int n, m;

vector <int> muchii[nmax+2];

int low[nmax+2];

int x, y;

bool onStack[nmax+2];

int tin[nmax+2];

vector <vector <int> > comp;

vector <int> stk;

int mom;

int partComp[nmax+2];

void dfs(int nod){

    stk.push_back(nod);

    onStack[nod]=true;

    low[nod]=tin[nod]=++mom;

    for(auto &x:muchii[nod]){

        if(onStack[x]){

            low[nod]=min(low[nod], tin[x]);

        }

        else if(tin[x]==0){

            dfs(x);

            low[nod]=min(low[nod], low[x]);

        }

    }

    if(low[nod]>=tin[nod]){

        comp.push_back(vector<int>());

        while(!stk.empty()&&stk.back()!=nod){

            comp.back().push_back(stk.back());

            partComp[stk.back()]=comp.size();

            onStack[stk.back()]=false;

            stk.pop_back();

        }

        comp.back().push_back(nod);

        partComp[stk.back()]=comp.size();

        onStack[stk.back()]=false;

        stk.pop_back();

    }

}

ostream & operator << (ostream & out, pair<int, int> & per){

    out<<per.first<<" "<<per.second;

    return out;

}

template <typename T>

ostream & operator << (ostream & out, vector <T> & vec){

    for(auto &x:vec)

        out<<x<<" ";

    return out;

}

vector <pair <int, int> > sol;

int main()

{

    in>>n>>m;

    for(int i=1; i<=m; i++){

        in>>x>>y;

        muchii[x].push_back(y);

    }

    for(int i=1; i<=n; i++)

        if(tin[i]==0)

            dfs(i);



    out<<comp.size()<<"\n";

    for(auto &x:comp)

        out<<x<<"\n";
    return 0;

}
