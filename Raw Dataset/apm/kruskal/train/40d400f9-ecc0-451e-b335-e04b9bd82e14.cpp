#include  <iostream>
#include  <fstream>
#include  <algorithm>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



const int Nmax = 4e5 + 5;

struct Muchie{

  int x, y, c;

}M[Nmax];

struct cmp{

  bool operator()(Muchie x, Muchie y)

  {

    return x.c < y.c;

  }

};

int n, m, k, Total;

int TT[Nmax], RG[Nmax];

pair <int, int>P[Nmax];



void Read()

{

  in>>n>>m;

  for(int i = 1; i <= m; i++)

    in>>M[i].x>>M[i].y>>M[i].c;

  sort(M + 1, M + m + 1, cmp());

  for(int i = 1; i <= n; i++)

  {

    TT[i] = i;

    RG[i] = 1;

  }



}



int Find(int Nod)

{

  while(TT[Nod] != Nod)

    Nod = TT[Nod];

  return Nod;

}



void Unire(int x, int y)

{

  if(RG[x] < RG[y])

    TT[x] = y;

  else if(RG[x] > RG[y])

    TT[y] = x;

  else if(RG[x] == RG[y])

  {

    TT[x] = y;

    RG[y]++;

  }

}



void Solve()

{

  for(int i = 1; i <= m; i++)

  {

    int tatal_x = Find(M[i].x);

    int tatal_y = Find(M[i].y);

    if(tatal_x != tatal_y)

    {

      Unire(tatal_x, tatal_y);

      P[++k].first = M[i].x;

      P[k].second = M[i].y;

      Total += M[i].c;

    }

  }

}



void Print()

{

  out<<Total<<'\n'<<k<<'\n';

  for(int i = 1; i <= k; i++)

    out<<P[i].first<<' '<<P[i].second<<'\n';

}



int main()

{

  Read();

  Solve();

  Print();

}
