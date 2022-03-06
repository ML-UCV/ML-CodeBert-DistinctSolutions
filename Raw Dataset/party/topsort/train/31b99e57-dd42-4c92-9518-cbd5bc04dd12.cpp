#include <cstdio>
#include <vector>
using namespace std;







vector<int> v[210];



vector<int> vComp[210];







int comp[210], stiva[210], nivmin[210], niv[210], viz[210], t[210], val[210], nInv;
int N, M;



int ncomp, stivaLast = -1, ult = -1;



void sortareTopologica(int i)



{



int j;



(viz + N)[i] = 1;



for(j = 0; j < vComp[i].size(); ++j)



if(!(viz + N)[ vComp[i][j] ]) sortareTopologica( vComp[i][j] );



t[i] = ++ult;



}







void comp_tare(int i)



{



int j;



(viz + N)[i] = 1;



stiva[++stivaLast] = i;



for(j = 0; j < (v + N)[i].size(); ++j)



if(!(viz + N)[ (v + N)[i][j] ])



{



(niv + N)[ (v + N)[i][j] ] = (nivmin + N)[ (v + N)[i][j] ]= (niv + N)[i] + 1;



comp_tare((v + N)[i][j]);



if((nivmin + N)[ (v + N)[i][j] ] < (nivmin + N)[i]) (nivmin + N)[i] = (nivmin + N)[ (v + N)[i][j] ];



}



else if((niv + N)[ (v + N)[i][j] ] < (nivmin + N)[i]) (nivmin + N)[i] = (niv + N)[ (v + N)[i][j] ];



if((niv + N)[i] == (nivmin + N)[i])



{



(comp + N)[i] = ++ncomp;



for(j = stivaLast; j >= 0 && stiva[j] != i; --j)



(comp + N)[stiva[j]] = ncomp;



stivaLast = j - 1;



}



}



void add(int x, int y, int t)



{



if(t == 0)



{



(v + N)[-x].push_back(y);



(v + N)[-y].push_back(x);



}



else if(t == 1) (v + N)[-x].push_back(-y);



else if(t == 2) (v + N)[-y].push_back(-x);



else if(t == 3)



{



(v + N)[x].push_back(-y);



(v + N)[y].push_back(-x);



}



}







int main()



{



int i, j, x, y, tt;







freopen("party.in", "r", stdin);



freopen("party.out", "w", stdout);





scanf("%d %d", &N, &M);



for(i = 1; i <= M; ++i)



{



scanf("%d %d %d", &x, &y, &tt);



add(x, y, tt);



}





for(i = -N; i <= N; ++i)



if(i == 0) continue;



else if(!(viz + N)[i])



{



(niv + N)[i] = (nivmin + N)[i] = 1;



comp_tare(i);



}



for(i = -N; i <= N; ++i)



if(i == 0) continue;



else for(j = 0; j < (v + N)[i].size(); ++j)



if((comp + N)[i] != (comp + N)[ (v + N)[i][j] ])



vComp[ (comp + N)[i] ].push_back((comp + N)[ (v + N)[i][j] ]);







for(i = 1; i <= ncomp; ++i) (viz + N)[i] = 0;



for(i = 1; i <= ncomp; ++i)



if(!(viz + N)[i]) sortareTopologica(i);







for(i = 1; i <= N; ++i)



{



if(t[ (comp + N)[i] ] < t[ (comp + N)[-i] ]) val[i] = 1, ++nInv;



else val[i] = 0;



}



printf("%d\n", nInv);



for(i = 1; i <= N; ++i)



if(val[i]) printf("%d\n", i);



return 0;







}
