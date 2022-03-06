#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
using namespace std;



const int N = 200005;





class MinHeap

{

    vector<pair<int, int>> heap;

    vector<int> nodePosition;

    int lastIndex;



public:

    MinHeap(int capacity)

    {

        lastIndex = 1;

        heap.resize(capacity + 1);

        nodePosition.resize(capacity + 1, -1);

    }



    void push(pair<int, int> x)

    {

        heap[lastIndex++] = x;

        nodePosition[x.second] = lastIndex - 1;

        bubbleUp(lastIndex-1);

    }



    void pop()

    {

        nodePosition[heap[1].second] = -1;

        heap[1] = heap[--lastIndex];

        nodePosition[heap[1].second] = 1;



        bubbleDown(1);
    }



    pair<int, int> top()

    {

        return heap[1];

    }



    int getNodeValue(int node)

    {

        int nodeIndex = nodePosition[node];

        return heap[nodeIndex].first;

    }





    void updateNodeValue(int node, int newValue)

    {

        int nodeIndex = nodePosition[node];

        heap[nodeIndex].first = newValue;

        bubbleUp(nodeIndex);

    }



    bool nodeExists(int node)

    {

        return nodePosition[node] != -1;

    }



    bool isEmpty()

    {

        return lastIndex == 1;

    }



private:

    void bubbleUp(int i)

    {

        if (i == 1)

            return;



        if (heap[i/2] > heap[i])

        {







            swapNode(i / 2, i);

            bubbleUp(i / 2);

        }

    }



    void bubbleDown(int i)

    {

        int st = i*2;

        int dr = st+1;



        if (dr > lastIndex)

            return;



        if (heap[st] <= heap[dr] && heap[st] < heap[i])

        {

            swapNode(st, i);

            bubbleDown(st);

        }

        else if (heap[dr] <= heap[st] && heap[dr] < heap[i])

        {

            swapNode(dr, i);

            bubbleDown(dr);

        }

    }



    void swapNode(int nodeIndex1, int nodeIndex2)

    {





        int node1 = heap[nodeIndex1].second;

        int node2 = heap[nodeIndex2].second;

        nodePosition[node2] = nodeIndex1;

        nodePosition[node1] = nodeIndex2;



        swap(heap[nodeIndex1], heap[nodeIndex2]);

    }



};





ifstream fin("apm.in");

ofstream fout("apm.out");



vector<pair<int, int>> g[N];

bool vis[N];

int tata[N];

int n, m;



int main()

{

    fin >> n >> m;

    for(int i = 0; i < m; i++)

    {

        int x, y, c;

        fin >> x >> y >> c;

        g[x].push_back({y, c});

        g[y].push_back({x, c});

    }



    MinHeap heap(n + 1);

    heap.push({0, 1});



    int costTotal = 0;

    while(!heap.isEmpty())

    {

        pair<int, int> minim = heap.top();

        int nod = minim.second;

        int cost = minim.first;

        heap.pop();



        if(vis[nod])

            continue;





        vis[nod] = true;

        costTotal += cost;



        for(auto y : g[nod])

            if(!vis[y.first])

            {

                if(!heap.nodeExists(y.first))

                {

                    heap.push({y.second, y.first});

                    tata[y.first] = nod;

                }

                else if(y.second < heap.getNodeValue(y.first))

                {

                    heap.updateNodeValue(y.first, y.second);

                    tata[y.first] = nod;

                }

            }

    }



    fout << costTotal << '\n';

    fout << n - 1 << '\n';

    for(int i = 2; i <= n; i++)

        fout << i << ' ' << tata[i] << '\n';



    return 0;

}
