#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



int n, m, i, a, b, c, t[200004];

pair<int, pair<int, int> > edge[400002];

vector<pair<int, int> > sol;



int rad(int nod){

    while(t[nod] > 0)

        nod = t[nod];

    return nod;

}



int main(){

    fin>>n>>m;

    for(i=1;i<=m;i++){

        fin>>a>>b>>c;

        edge[i] = {c, {a, b}};

    }

    sort(edge+1, edge+m+1);

    for(i=1;i<=n;i++)

        t[i] = -1;

    pair<int, int> muchie = edge[1].second;

    sol.push_back(muchie);

    t[muchie.first]--;

    t[muchie.second] = muchie.first;

    int ind = 2;

    int cost = edge[1].first;

    while(sol.size() < n-1){

        muchie = edge[ind].second;

        a = muchie.first;

        b = muchie.second;

        int rad1 = rad(a);

        int rad2 = rad(b);

        if(rad1 != rad2){

            sol.push_back(muchie);

            cost += edge[ind].first;

            if(t[rad1] < t[rad2]){

                t[rad1] += t[rad2];

                t[rad2] = rad1;

            }

            else{

                t[rad2] += t[rad1];

                t[rad1] = rad2;

            }

        }

        ind++;

    }

    fout<<cost<<"\n"<<sol.size()<<"\n";

    for(i=0;i<sol.size();i++)

        fout<<sol[i].first<<" "<<sol[i].second<<"\n";

    return 0;

}
