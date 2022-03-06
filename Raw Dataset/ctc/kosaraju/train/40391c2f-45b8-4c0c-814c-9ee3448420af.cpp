#include <fstream>
#include <vector>




using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector <int> v[100005],vt[100005],ctc[100005];

int timp[100005], sw[100005], nrc[100005], nr, swt[100005], n, m, nrctc, ID[100005];



void df (int i )

{

 vector <int> :: iterator it;

 sw[i]=1;

 for (it=v[i].begin();it<v[i].end();it++)

  if (!sw[*it])

   df(*it);

 timp[++nr]=i;

}



void df2 (int i )

{

 vector <int> :: iterator it;

 swt[i]=1;

 ctc[nrctc].push_back(i);

 for (it=vt[i].begin();it<vt[i].end();it++)

  if (!swt[*it])

   df2(*it);

}



void comp()

{

 int i,j;

 nrctc=0;

 nr=0;

 for (i=1;i<=n;i++)

  if (!sw[i])

   df(i);



 for (j=nr;j;j--)

  if (!swt[timp[j]])

   {

   nrctc++;

   df2(timp[j]);

   }

}



int main ()

{

 int i,x,y;

 f >> n >> m;

 for (i = 1; i <= m; i++)

 {

  f >> x >> y;

  v[x].push_back(y);

  vt[y].push_back(x);

 }

 comp();



 vector <int > ::iterator it;

 g << nrctc << '\n';

 for (i = 1; i <= nrctc; i++)

 {

  for (it = ctc[i].begin(); it < ctc[i].end(); it++)

   g << *it << ' ';

  g << '\n';

 }



 return 0;

}
