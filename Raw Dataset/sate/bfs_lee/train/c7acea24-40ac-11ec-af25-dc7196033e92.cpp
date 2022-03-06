#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

#define MAX 30005

using namespace std;
fstream in("sate.in");
ofstream out("sate.out");

vector<pair<int,int>> A[MAX];
int N, M, X,Y, L;
int cost[MAX];
int S[MAX];
pair<int,int> muchii[MAX];
void BFS(int nod)
{
    L = 1;
    S[L] = nod; //Add the node to the queue
    cost[nod] = 0; //Cost to same node is 0
    muchii[nod].first = -1;
    for(int i = 1; i <= L; i++) //While queue is not empty
        for(auto vecin : A[S[i]]) // Check the neighbours
            if(cost[vecin.first] == -1)   //If not visited already
            {
                S[++L] = vecin.first; //Add to queue
                muchii[vecin.first]= {S[i],vecin.second}; //Increase cost of neighbour
                cost[vecin.first] =0;
                if(vecin.first==Y) // Am ajuns la satul cerut
                    return;
            }



}
int main()
{
    in >> N >> M >> X>>Y;
    memset(cost, -1, sizeof(cost)); //Set all the costs to -1
    int x, y,t;
    for(int i = 1; i <= M; i++)
    {
        in >> x >> y>>t;
        A[x].push_back({y,t}); //Read as adiacency list
        A[y].push_back({x,t});
    }

    BFS(X);
    int answer = 0;
    while(muchii[Y].first!=-1) // Cat timp avem lant
    {
        if(Y > muchii[Y].first) // Daca e in directia buna, crestem suma
            answer+=muchii[Y].second;
        else
            answer-=muchii[Y].second; // Altfel scadem
        Y = muchii[Y].first; // Trecem la urmatorul sat
    }

    out<<answer;
    return 0;
}
