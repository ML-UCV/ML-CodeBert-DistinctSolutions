#include <bits/stdc++.h>

std::ifstream fin("ctc.in");
std::ofstream fout("ctc.out");

int n, m, nodeIndex;
std::vector<int> nei[100001], id, lowLink;
std::vector<bool> inStack;
std::stack<int> stack;
std::vector<std::vector<int>> comp;

void dfs(int x){
    id[x] = lowLink[x] = nodeIndex++;
    stack.push(x);
    inStack[x] = true;
    for(auto node: nei[x]){
        if(id[node] == -1)
            dfs(node);
        if(inStack[node])
            lowLink[x] = std::min(lowLink[node], lowLink[x]);
    }

    if(id[x] == lowLink[x]){
        std::vector<int> aux;
        while(stack.top() != x){
            inStack[stack.top()] = false;
            aux.push_back(stack.top());
            stack.pop();
        }
        inStack[stack.top()] = false;
        aux.push_back(stack.top());
        stack.pop();
        comp.push_back(aux);
    }
}


int main()
{
    int x, y, i;
    fin >> n >> m;
    id.resize(n + 1, -1);
    lowLink.resize(n + 1);
    inStack.resize(n + 1, false);

    for(i = 0; i < m; i++){
        fin >> x >> y;
        nei[x].push_back(y);
    }

    for(i = 1; i <= n; i++)
        if(id[i] == -1)
            dfs(i);

    fout << comp.size() << '\n';
    for(auto i: comp){
        for(auto j: i)
            fout << j << " ";
        fout << '\n';
    }




    return 0;
}
