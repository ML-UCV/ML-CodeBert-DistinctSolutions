#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <bits/stdc++.h>




using namespace std;



const int N = 200005;



int n, m;

int cost[N];

vector<pair<int,int>>graf[N];

vector<pair<int,int>> ans;

bool amfost[N];



struct cmp{

    bool operator()(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){

        return a.second.second > b.second.second;

    }

};



priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , cmp> coada;



void calc(int nod, int last) {

    cost[nod] = 0;

    coada.push(make_pair(nod, make_pair(last, cost[nod])));



    while(coada.empty() == false) {

        last = coada.top().second.first;

        nod = coada.top().first;

        coada.pop();







        if(amfost[nod] == true) {

            cout << "JUCK" << '\n';

            continue;

        }



        ans.push_back(make_pair(nod, last));

        amfost[nod] = true;



        for (int i = 0; i < (int)graf[nod].size(); ++i) {



            int to = graf[nod][i].first;

            int drum = graf[nod][i].second;



            if(cost[to] > drum && amfost[to] == false){

                cost[to] = drum;



                coada.push(make_pair(to, make_pair(nod, cost[to])));

            }



        }





    }



}



int main() {

    ifstream fin("apm.in");

    ofstream fout("apm.out");



    fin >> n >> m;



    for (int i = 1; i <= n; ++i)

        cost[i] = INT_MAX;



    int costMin = INT_MAX, nodMin;

    for (int i = 1; i <= m; ++i) {

        int a, b, c;

        fin >> a >> b >> c;

        graf[a].push_back(make_pair(b,c));

        graf[b].push_back(make_pair(a,c));



        if(costMin > c) {

            costMin = c;

            nodMin = a;

        }

    }

    calc(nodMin, 0);



    int sum = 0;

    for (int i = 1; i <= n; ++i) {

        sum += cost[i];





    }



    fout << sum << '\n';

    fout << (int)ans.size() - 1<< '\n';

    for (int i = 1; i < (int)ans.size(); ++i)

        fout << ans[i].first << " " << ans[i].second << '\n';



    return 0;

}
