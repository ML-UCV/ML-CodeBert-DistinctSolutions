#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;

const int MAXN = 2e5 + 5;

const int MAXM = 4e5 + 5;

struct muchie{

 int x, y, cost;

};

muchie M[MAXM];



int tip,x,y;



ifstream fin("apm.in");

ofstream fout("apm.out");

int t[MAXN],n,m,h[MAXN];

vector < pair < int ,int > > ans;

bool cmp(muchie x, muchie y) {

 return x.cost < y.cost;

}



int findroot(int nod) {

 if(t[nod] == nod)

  return nod;

 return t[nod] = findroot(t[nod]);

}



void Union(int rad1, int rad2) {

 if(h[rad1] > h[rad2]) {

  t[rad2] = rad1;

}

else

 if(h[rad1] < h[rad2]) {

  t[rad1] = rad2;

}

else

{

 t[rad1] = rad2;

 h[rad2]++;

}



}



int main() {

 fin >> n >> m;

 for (int i = 1; i <= n; ++i) {

  t[i] = i;

  h[i] = 1;

}

 for ( int i = 1; i <= m; ++i){

 fin >> M[i].x >> M[i].y >> M[i].cost;

}

 sort(M+1,M+m+1,cmp);

 long long s = 0;

 for ( int i = 1; i <= m; ++i) {

  if(findroot(M[i].x) != findroot(M[i].y)) {

   Union(findroot(M[i].x),findroot(M[i].y));

   s+=M[i].cost;

   ans.push_back({M[i].x,M[i].y});

}

}

 fout << s <<"\n"<< ans.size() <<"\n";

 for ( auto idk : ans)

    fout << idk.second <<" "<< idk.first <<"\n";

}
