#include<iostream>
#include<algorithm>
#include<fstream>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



int n, m, cost;



class Edge

{

public:

    int source, destination, weight;

}edges[400010];





class Subset

{

public:

    int parent, rank;

};





bool cmp(Edge x, Edge y)

{

    return x.weight < y.weight;

}





void Read()

{

    int i;

    f>>n>>m;

    for(i = 0; i < m; i++)

    {

        int x,y,z;

        f>>x>>y>>z;

        edges[i].source = x;

        edges[i].destination = y;

        edges[i].weight = z;

    }

}
int Find(Subset subsets[], int i)

{

    if(subsets[i].parent != i)

        subsets[i].parent = Find(subsets, subsets[i].parent);



    return subsets[i].parent;

}



void Union(Subset subsets[], int x, int y)

{

    int xSet = Find(subsets, x);

    int ySet = Find(subsets, y);



    if(subsets[xSet].rank < subsets[ySet].rank)

        subsets[xSet].parent = ySet;

    else if (subsets[xSet].rank > subsets[ySet].rank)

        subsets[ySet].parent = xSet;

    else

    {

        subsets[ySet].parent = xSet;

        subsets[xSet].rank++;

    }

}



void Kruskal(Edge edges[])

{

    int count = 0, nr = 0;

    Edge result[400010];

    Subset subsets[400010];



    sort(edges, edges + m, cmp);

    for(int i = 0; i < n; i++)

    {

        subsets[i].parent = i;

        subsets[i].rank = 0;

    }



    while(count < n - 1 && nr < m)

    {

        Edge next = edges[nr++];

        int x = Find(subsets, next.source);

        int y = Find(subsets, next.destination);



        if(x != y)

        {

            result[count++] = next;

            Union(subsets, x, y);

        }

    }







    for(int i = 0; i < count; i++)

    {



        cost += result[i].weight;

    }

    g<<cost<<'\n';

    g<<count<<'\n';



    for(int i = 0; i < count; i++)

        g<<result[i].source<<" "<<result[i].destination<<'\n';





}



int main()



{

    Read();



    Kruskal(edges);







    return 0;

}
