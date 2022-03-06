#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, cnt = 0, niv = 0, Niv[100001], NivMin[100001];

vector<int> G[100001], Ctc[100001];

stack<int> Stack;

bool V[100001], InStack[100001];



void Dfs(int x)

{

    V[x] = true;

    ++niv;

    Niv[x] = NivMin[x] = niv;

    Stack.push(x);

    InStack[x] = true;

    for (int y : G[x])

    {

        if (!V[y])

        {

            Dfs(y);

            NivMin[x] = min(NivMin[x], NivMin[y]);

        }

        else if (InStack[y])

            NivMin[x] = min(NivMin[x], NivMin[y]);

    }

    if (Niv[x] == NivMin[x])

    {

        ++cnt;

        while (true)

        {

            Ctc[cnt].push_back(Stack.top());

            InStack[Stack.top()] = false;

            if (Stack.top() == x)

            {

                Stack.pop();

                break;

            }

            Stack.pop();

        }

    }

}



int main()

{

    fin >> n >> m;

    for (int i = 1; i <= m; ++i)

    {

        int x, y;

        fin >> x >> y;

        G[x].push_back(y);

    }

    for (int i = 1; i <= n; ++i)

    {

        if (!V[i])

            Dfs(i);

    }

    fout << cnt << '\n';

    for (int i = 1; i <= cnt; ++i)

    {

        for (int x : Ctc[i])

            fout << x << " ";

        fout << '\n';

    }



    return 0;

}
