#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>



using namespace std;

FILE*f=fopen("party.in","r");
FILE*g=fopen("party.out","w");

int n,m,index;
int viz[105<<1],lowest[105<<1],niv[105<<1],comp[105<<1],last[105<<1],gr_in[105<<1],sol[105<<1];
vector<int>G[105<<1],W[105<<1],v;
stack<int>st; int inst[105<<1];
vector< vector<int> >C;
queue<int>Q;

inline int NOT ( const int &x ){

 if ( x <= n ){
  return n+x;
 }
 return x-n;
}

inline void componenta ( const int &x ){
 int nod; v.clear();

 do{
  nod = st.top(); v.push_back(nod); comp[nod] = C.size()+1;
  st.pop(); inst[nod] = 0;
 }while(x != nod);

 C.push_back(v);
}

void DFS ( int nod ){
 viz[nod] = 1; niv[nod] = lowest[nod] = ++index;
 st.push(nod); inst[nod] = 1;

 for ( vector<int>::iterator itt = G[nod].begin() ; itt != G[nod].end() ; ++itt ){
  int nodvcn = (*itt);

  if ( !viz[nodvcn] ){
   DFS(nodvcn);
   lowest[nod] = min(lowest[nod],lowest[nodvcn]);
  }
  else{
   if ( inst[nodvcn] ){
    lowest[nod] = min(lowest[nod],lowest[nodvcn]);
   }
  }
 }

 if ( lowest[nod] == niv[nod] ){
  componenta(nod);
 }
}

inline void CTC () {

 for ( int i = 1 ; i <= (n<<1) ; ++i ){
  if ( !viz[i] ){
   DFS(i);
  }
 }
}

inline void solve () {

 int Ncomp = C.size();
 for ( int i = 0 ; i < Ncomp ; ++i ){
  for ( vector<int>::iterator itt = C[i].begin() ; itt != C[i].end() ; ++itt ){
   int x = (*itt);

   for ( vector<int>::iterator vecin = G[x].begin() ; vecin != G[x].end() ; ++vecin ){
    int compvcn = comp[*vecin];
    if ( last[compvcn] != i+1 && compvcn != i+1 ){
     W[i+1].push_back(compvcn); ++gr_in[compvcn];
     last[compvcn] = i+1;
    }
   }
  }
 }

 for ( int i = 1 ; i <= Ncomp ; ++i ){
  if ( !gr_in[i] ){
   Q.push(i);
  }
 }

 int nod;
 for ( ; !Q.empty() ; ){
  nod = Q.front(); Q.pop();

  for ( vector<int>::iterator itt = W[nod].begin() ; itt != W[nod].end() ; ++itt ){
   int nodvcn = (*itt);
   --gr_in[nodvcn];
   if ( !gr_in[nodvcn] )
    Q.push(nodvcn);
  }
  if ( last[nod] == -1 ) continue ;

  for ( vector<int>::iterator itt = C[nod-1].begin() ; itt != C[nod-1].end() ; ++itt ){
   sol[*itt] = 0;
  }
  nod = comp[NOT(C[nod-1][0])]; last[nod] = -1;
  for ( vector<int>::iterator itt = C[nod-1].begin() ; itt != C[nod-1].end() ; ++itt ){
   sol[*itt] = 1;
  }
 }

 int Nsol = 0;
 for ( int i = 1 ; i <= n ; ++i ){
  Nsol += sol[i];
 }
 fprintf(g,"%d\n",Nsol);
 for ( int i = 1 ; i <= n ; ++i ){
  if ( sol[i] ){
   fprintf(g,"%d\n",i);
  }
 }
}

int main () {

 fscanf(f,"%d %d",&n,&m);
 int a,b,tip;
 for ( int i = 1 ; i <= m ; ++i ){
  fscanf(f,"%d %d %d",&a,&b,&tip);

  if ( tip == 1 ){
   b = -b;
  }
  else{
   if ( tip == 2 ){
    a = -a;
   }
   else{
    if ( tip == 3 ){
     a = -a; b = -b;
    }
   }
  }

  if ( a < 0 ) a = -a+n;
  if ( b < 0 ) b = -b+n;
  G[NOT(a)].push_back(b);
  G[NOT(b)].push_back(a);
 }

 CTC();
 solve();

 fclose(f);
 fclose(g);

 return 0;
}
