#include<fstream>
#include<vector>
#include<deque>
using namespace std;

const int MaxNodesCnt = 3e4 + 5, buffSZ = 4e4 + 5;

char buff[buffSZ];
int buffPointer = buffSZ - 1;

inline void read(int &no){

    while(!isdigit(buff[buffPointer]))
        if(++buffPointer == buffSZ){

            buffPointer = 0;
            fread(buff, 1, buffSZ, stdin);
        }
    no = 0;
    while(isdigit(buff[buffPointer])){

        no = no * 10 + buff[buffPointer] - '0';
        if(++buffPointer == buffSZ){

            buffPointer = 0;
            fread(buff, 1, buffSZ, stdin);
        }
    }
}

struct Graph{

    int newNode, cost;
};

vector<Graph> adjList[MaxNodesCnt];
int dist[MaxNodesCnt];
int nodesCnt, edgesCnt, startNode, endNode;

inline void readData(){

    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);

    read(nodesCnt); read(edgesCnt); read(startNode); read(endNode);

    int from, to, cost;
    while(edgesCnt--){

        read(from); read(to); read(cost);
        adjList[from].push_back({to, cost});
        adjList[to].push_back({from, -cost});
    }
}

inline void BFS(int node){

    deque<int> Queue;
    Queue.push_back(node);

    int newNode, cost;

    while(!Queue.empty()){

        node = Queue.front();
        Queue.pop_front();

        for(const Graph &nextNode : adjList[node]){

            newNode = nextNode.newNode;
            cost = nextNode.cost;
            if(dist[newNode] == 0 and newNode != startNode){

                dist[newNode] = dist[node] + cost;
                Queue.push_back(newNode);
            }
        }
    }
}

int main(){

    readData();
    BFS(startNode);
    printf("%d", dist[endNode]);
}
