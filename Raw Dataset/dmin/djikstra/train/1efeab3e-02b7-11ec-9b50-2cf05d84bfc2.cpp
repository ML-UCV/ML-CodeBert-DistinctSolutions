#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;



ifstream in("dmin.in");

ofstream out("dmin.out");



const int N = 1502;

const double eps = 0.0000001;

const int M = 104659;



int n, m, sol[N], nod;

double dist[N];

bool ver[N];

vector<pair<int, double> > v[N];

queue<int> q;



void dijkstra() {

 int i;

 vector<pair<int, double> >::iterator it;



 for(i = 1; i<=n; ++i)

  dist[i] = 29999999.0;



 ver[1] = true;

 q.push(1);

 dist[1] = 0;

 sol[1] = 1;



 while(!q.empty()) {

  nod = q.front();

  q.pop();

  ver[nod] = false;



  for(it = v[nod].begin(); it!=v[nod].end(); ++it) {

   if(dist[it->first] - dist[nod] - it->second > eps) {

    dist[it->first] = dist[nod] + it->second;

    sol[it->first] = sol[nod];



    if(!ver[it->first]) {

     q.push(it->first);

     ver[it->first] = true;

    }

   }

   else if(dist[nod] + it->second - dist[it->first] <= eps) {

    sol[it->first] += sol[nod];

    sol[it->first]%=M;

   }

  }

 }

}



int main() {

 int i, x, y;

 double c;



 in >> n >> m;



 for(i = 1; i<=m; ++i) {

  in >> x >> y >> c;

  c = log(c);



  v[x].push_back(pair<int, double>(y, c));

  v[y].push_back(pair<int, double>(x, c));

 }



 dijkstra();



 for(i = 2; i<=n; ++i)

  out << sol[i] << " ";



 return 0;

}
