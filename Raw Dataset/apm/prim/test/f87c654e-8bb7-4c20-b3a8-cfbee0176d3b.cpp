#include<iostream>
#include<fstream>
#include<vector>
#include<queue>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



vector< vector< pair<int, int> > > w;

vector< pair<int,int> >apm;

priority_queue< pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > >h;



int s,i;



bool b[200001];



void prim (int x)

{

    for(i = 0; i < w[x].size(); i++)

        if(!b[w[x][i].first])

            h.push(make_pair(w[x][i].second, make_pair(x, w[x][i].first)));



    b[x] = 1;



    while ( !h.empty() && b[h.top().second.second])

        h.pop();





    if(!h.empty())

    {

        int val = h.top().first, xn = h.top().second.first, yn = h.top().second.second;

        h.pop();



        apm.push_back(make_pair(xn,yn));

        s += val;



        prim(yn);

    }



}



int main()

{

    int n, m, x, y, cost;



    f >> n >> m;



    w.resize(n+1);



    for(i = 0; i < m; i++)

    {

        f>>x>>y>>cost;



        w[x].push_back(make_pair(y,cost));

        w[y].push_back(make_pair(x,cost));

    }



    prim(1);



    g<<s<<'\n'<< apm.size()<< '\n';



    for( auto elem =apm.begin(); elem != apm.end(); elem++)

        g<<(*elem).first<<" " << (*elem).second<< '\n';



    return 0;

}
