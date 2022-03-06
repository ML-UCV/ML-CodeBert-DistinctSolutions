#include <iostream>
#include <fstream>
#include <vector>
#include <stack>


using namespace std;



int N,M;

stack<int> Stack;

vector<int>Graf[100010],Lowlink(100010,-1),Indx(100010,-1),ONstack(100010,0);

vector<vector<int>> result;



void Tarjan(int x)

{

    static int index = 0;

    Indx[x] = Lowlink[x] = index;

    index++;

    Stack.push(x);

    ONstack[x] = 1;



    for (int it : Graf[x])

    {

        if (Indx[it] == -1)

            Tarjan(it);

        if (ONstack[it])

            Lowlink[x] = min(Lowlink[x], Lowlink[it]);

    }

    if (Indx[x] == Lowlink[x])

    {

        vector<int> aux;



        while (Stack.top() != x)

        {

            aux.push_back(Stack.top());

            ONstack[Stack.top()] = 0;

            Stack.pop();

        }



        aux.push_back(Stack.top());

        ONstack[Stack.top()] = 0;

        Stack.pop();



        result.push_back(aux);

    }

}

int main()

{

    ifstream in ("ctc.in");

    ofstream out("ctc.out");



    int x,y;



    in>>N>>M;

    for( int i = 0; i < M; ++i)

    {

        in>>x>>y;

        Graf[x].push_back(y);



    }



    for(int i = 1; i <=N; ++i)

        if (Indx[i] == -1)

            Tarjan(i);





    out << result.size() << "\n";



    for (auto it : result)

    { for (int x : it)

            out<< x << " ";

        out << "\n";

    }

    return 0;

}
