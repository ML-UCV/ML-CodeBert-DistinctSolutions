#include <iostream>
#include <bits/stdc++.h>


using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

int N,M,x,y;

vector<int> Graph[100004];

int ids[100004];

int lowLink[100004];

bool OnStack[100004];

stack<int> Stack;

int id = 0;

int counter = 0;

int check=0;

vector<int> answer[100004];



void DFS(int nod)

{



    Stack.push(nod);

    OnStack[nod] = true;





    ids[nod] = id;



    lowLink[nod] = id;



    id++;



    for(int i=0; i<Graph[nod].size(); i++)

    {

        if(ids[Graph[nod][i]]==0)

            DFS(Graph[nod][i]);



        if(OnStack[Graph[nod][i]])

            lowLink[nod] = min(lowLink[nod], lowLink[Graph[nod][i]]);

    }



    if(ids[nod]==lowLink[nod])

    {

        while(!Stack.empty())

        {

            int nodCurent = Stack.top();

            Stack.pop();

            OnStack[nodCurent]=false;

            lowLink[nodCurent]=ids[nod];

            if(nodCurent==nod)

                break;

        }



    }

}



int main()

{

    in>>N>>M;

    for(int i=1; i<=M; i++)

    {

        in>>x>>y;

        Graph[x].push_back(y);

    }



    memset(ids,0,sizeof(ids));

    memset(lowLink,0, sizeof(lowLink));

    memset(OnStack,0,sizeof(OnStack));



    for(int i=1; i<=N; i++)

        if(ids[i]==0)

            DFS(i);





    for(int i=1; i<=N; i++)

        answer[lowLink[i]].push_back(i);

    for(int i=0; i<100004; i++)

        if(answer[i].size()!=0)

            check+=1;

    out<<check<<'\n';

    for(int i=0; i<100004; i++)

    {

        if(answer[i].size()!=0)

        {

            check+=1;

            for(auto temp : answer[i])

                out<<temp<<" ";

            out<<'\n';

        }

    }

    return 0;

}
