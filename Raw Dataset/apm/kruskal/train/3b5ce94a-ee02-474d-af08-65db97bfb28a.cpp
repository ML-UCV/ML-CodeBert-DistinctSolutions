#include<fstream>
#include<algorithm>
std::ifstream f("apm.in");

std::ofstream g("apm.out");





const int LIM = 500000;

int N, M,Sum;

int tata[LIM], rang[LIM];

int nr;

struct muchie

{

 int first,second,cost;

 int einarbore;

}m[LIM];







bool cnd(muchie a, muchie b)

{

 return (a.cost < b.cost);

}





void citire()

{

 f >> N >> M;



 for (int i = 1; i <= M; i++)

  f >> m[i].first >> m[i].second >> m[i].cost;



 std::sort(m + 1, m + M + 1, cnd);
}



int T(int x)

{

 if (tata[x] == 0)

  return x;

 else

 {

  int y = T(tata[x]);

  tata[x] = y;

  return y;

 }

}



void unire(muchie &x)

{

 int tf = T(x.first);

 int ts = T(x.second);

 if (tf != ts)

 {

  if (rang[tf] > rang[ts])

   tata[ts] = tf;

  else

  {

   tata[tf] = ts;

   if (rang[tf] == rang[ts])

    rang[ts]++;

  }

  Sum += x.cost;

  nr++;

  x.einarbore = 1;





 }



}



void Kruskal()

{





 for (int i = 1; i <= M; i++)

  if (tata[m[i].first] != tata[m[i].second] || (!tata[m[i].first] && !tata[m[i].second]))

   unire(m[i]);







   g << Sum;

   g << '\n' << nr << '\n';

   for (int i = 1; i <= M; i++)

    if(m[i].einarbore)

     g << m[i].first << " " << m[i].second << '\n';



}





int main()

{

 citire();

 Kruskal();

 f.close();

 return 0;

}
