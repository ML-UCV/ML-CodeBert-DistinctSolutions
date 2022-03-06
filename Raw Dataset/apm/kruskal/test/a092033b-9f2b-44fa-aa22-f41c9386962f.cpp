#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int NMAX = 4e5 + 5;

int t[NMAX], r[NMAX], total;

vector<pair<int, int>> er;



struct edge{

 int x, y, p;

}v[NMAX];



bool srt(edge a, edge b){return a.p < b.p;}



int FindT(int nod)

{

 while(t[nod] != nod)

  nod = t[nod];

 return nod;

}



void UN(int nx, int ny)

{

 if(r[nx] < r[ny]) t[nx] = ny;

 else if(r[nx] > r[ny]) t[ny] = nx;

 else t[nx] = ny, ++r[ny];

}



int main()

{

 ios::sync_with_stdio(false);

 fin.tie();



 int n, m;



 fin >> n >> m;



 for(int i = 1; i <= m; ++i)

  fin >> v[i].x >> v[i].y >> v[i].p;

 for (int i = 1; i <= m; ++i)

  t[i] = i, r[i] = 1;



 sort(v + 1, v + m + 1, srt);



 for(int i = 1; i <= m; ++i)

 {

  int auxf1 = FindT(v[i].x), auxf2 = FindT(v[i].y);

  if(auxf1 != auxf2)

  {

   UN(auxf1, auxf2);

   er.push_back({v[i].x, v[i].y});

   total += v[i].p;

  }

 }



 fout << total << "\n" << er.size() << "\n";



 for (auto i : er)

  fout << i.second << " " << i.first << "\n";



 return 0;

}
