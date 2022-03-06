#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>




using namespace std;



ifstream cin("ctc.in");

ofstream cout("ctc.out");



vector <int> InitGraph[100005], ReverseGraph[100005];

vector <int> StrongComponents[100005];

stack <int> Stack;

int N, M, strongComponents;

bool visited[100005];



void FirstDFS(int node)

{

    int currentNode;

    visited[node] = true;

    for(int i = 0; i < InitGraph[node].size(); i++){

        currentNode = InitGraph[node][i];

        if(visited[currentNode] == false){

            FirstDFS(currentNode);

        }

    }

    Stack.push(node);

}



void SecondDFS(int node)

{

    int currentNode;

    visited[node] = true;

    StrongComponents[strongComponents].push_back(node);

    for(int i = 0; i < ReverseGraph[node].size(); i++){

        currentNode = ReverseGraph[node][i];

        if(!visited[currentNode]){

            SecondDFS(currentNode);

        }

    }

}



int main()

{

    int nodeX, nodeY, currentNode;

    cin >> N >> M;

    for(int i = 1; i <= M; i++){

        cin >> nodeX >> nodeY;

        InitGraph[nodeX].push_back(nodeY);

        ReverseGraph[nodeY].push_back(nodeX);

    }

    for(int i = 1; i <= N; i++){

        if(!visited[i]){

            FirstDFS(i);

        }

    }

    memset(visited,false,sizeof(visited));

    while(!Stack.empty()){

        currentNode = Stack.top();

        if(visited[currentNode] == false){

            ++strongComponents;

            SecondDFS(currentNode);

        }

        Stack.pop();

    }

    cout << strongComponents << "\n";

    for(int i = 1; i <= strongComponents; i++){

        for(int j = 0; j < StrongComponents[i].size(); j++){

            cout << StrongComponents[i][j] << " ";

        }

        cout << "\n";

    }

    return 0;

}
