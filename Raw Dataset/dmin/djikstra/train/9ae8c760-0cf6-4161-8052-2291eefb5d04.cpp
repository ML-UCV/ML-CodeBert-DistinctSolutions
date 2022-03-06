#include <bits/stdc++.h>


using namespace std;



ifstream in("dmin.in");

ofstream out("dmin.out");
int x,y,n,m;

double L[50005];

bool viz[50005];

const double eps = 1e-6;

double c;



vector <pair <int, double> > v[50005];

vector < int > T;



int D[50005];



int cmp(const int&a, const int&b){

    return(L[a] > L[b]);

}



void dijkstra(){



    int node;

    T.push_back(1);

    make_heap(T.begin(),T.end(),cmp);

    while(!T.empty()){

        node=T.front();

        pop_heap(T.begin(),T.end(),cmp);

        T.pop_back();

        for(int i=0;i<v[node].size();i++){

            if(L[v[node][i].first] > L[node] + v[node][i].second){

                L[v[node][i].first] = L[node] + v[node][i].second;

                T.push_back(v[node][i].first);

                push_heap(T.begin(),T.end(),cmp);

        }



    }

    }





}







int Solve(int node){



        if(viz[node])return D[node];

        viz[node]=1;

        for(int i=0;i<v[node].size();i++)

            if((max(L[v[node][i].first] - L[node] + v[node][i].second, -L[v[node][i].first] - L[node] + v[node][i].second)) < eps)

                D[node]+=Solve(v[node][i].first),D[node]%=104659;

        return D[node];





}



int main(){



    in>>n>>m;



    for(int i=1;i<=m;i++)

    {

        in>>x>>y>>c;

        v[x].push_back({y,log(c)});

        v[y].push_back({x,log(c)});



    }

    for(int i=2;i<=n;i++)

        L[i]=INFINITY;

    dijkstra();

    viz[1]=1;

    D[1]=1;

    for(int i=2;i<=n;i++){

        D[i]=Solve(i);

        }

    for(int i=2;i<=n;i++)

        out<<D[i]<<" ";

    return 0;

}
