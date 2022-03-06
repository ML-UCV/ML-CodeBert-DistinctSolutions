#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <climits>

using namespace std;

struct node{
    int index;
    int lowlink;
    bool onStack;
    node(int i, int l){
        this->index = i;
        this->lowlink = l;
        this->onStack = false;
    }
};

vector<int> neighbours[100000];
ifstream f("ctc.in");
ofstream g("ctc.out");
vector<node> nods;
int n, m;
int index;
stack<int> S;
vector<vector<int>> output;

void con(int z){
    nods[z].index = index;
    nods[z].lowlink = index;
    index++;
    S.push(z);
    nods[z].onStack = true;
    for (auto it : neighbours[z]) {
        if(nods[it].index == INT_MIN){
            con(it);
            nods[z].lowlink = min(nods[z].lowlink, nods[it].lowlink);
        }else if(nods[it].onStack){
            nods[z].lowlink = min(nods[z].lowlink, nods[it].index);
        }
    }
    if(nods[z].lowlink == nods[z].index){
        vector<int> comp;
        int w;
        do{
            w = S.top();
            S.pop();
            nods[w].onStack = false;
            comp.push_back(w + 1);
        } while (w != z);
        output.push_back(comp);
    }
}

int main() {
    f>>n>>m;
    for (int i = 0; i < n; ++i) {
        nods.emplace_back(INT_MIN, INT_MAX);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        f>>x>>y;
        x--, y--;
        neighbours[x].push_back(y);
    }
    for(int i = 0; i < n; ++i){
        if(nods[i].index == INT_MIN){
            con(i);
        }
    }
    g<<output.size()<<'\n';
    for(auto it : output){
        for(auto it2 : it){
            g<<it2<<' ';
        }
        g<<"\n";
    }
    return 0;
}
