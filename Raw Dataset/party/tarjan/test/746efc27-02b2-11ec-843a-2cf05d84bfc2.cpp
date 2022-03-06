#include <fstream>
#include <vector>


using namespace std;



const char InFile[]="party.in";

const char OutFile[]="party.out";

const int MaxN=205;



ifstream fin(InFile);

ofstream fout(OutFile);



int N,M,x,y,op,ind,comp,C[MaxN],low[MaxN],niv[MaxN],S[MaxN],SOL[MaxN];

vector<int> G[MaxN],GC[MaxN],El[MaxN];



void Tarjan(int nod)

{

 low[nod]=niv[nod]=++ind;

 S[++S[0]]=nod;

 for(vector<int>::iterator it=G[nod].begin();it!=G[nod].end();++it)

 {

  int &vcn=*it;

  if(!low[vcn])

  {

   Tarjan(vcn);

  }

  else if(low[vcn]>0)

  {

   if(low[vcn]<low[nod])

   {

    low[nod]=low[vcn];

   }

  }

 }



 if(low[nod]==niv[nod])

 {

  ++comp;

  int tnod;

  do

  {

   tnod=S[S[0]];

   --S[0];

   C[tnod]=comp;

   low[tnod]=-low[tnod];

   El[comp].push_back(tnod);

  }while(tnod!=nod);

 }

}



void DFS(int nod)

{

 low[nod]=0;

 for(vector<int>::iterator it=GC[nod].begin();it!=GC[nod].end();++it)

 {

  int &vcn=*it;

  if(low[vcn])

  {

   DFS(vcn);

  }

 }

 S[++S[0]]=nod;

}



inline int NON(int x)

{

 if(x>N)

 {

  return x-N;

 }

 return x+N;

}



int main()

{

 fin>>N>>M;

 for(register int i=1;i<=M;++i)

 {

  fin>>x>>y>>op;

  if(op==1)

  {

   y+=N;

  }

  else if(op==2)

  {

   x+=N;

  }

  else if(op==3)

  {

   y+=N;

   x+=N;

  }

  G[NON(x)].push_back(y);

  G[NON(y)].push_back(x);

 }

 fin.close();



 for(register int i=1;i<=(N<<1);++i)

 {

  if(!low[i])

  {

   Tarjan(i);

  }

 }



 for(register int i=1;i<=(N<<1);++i)

 {

  for(vector<int>::iterator it=G[i].begin();it!=G[i].end();++it)

  {

   GC[C[i]].push_back(C[*it]);

  }

 }



 for(register int i=1;i<=(N<<1);++i)

 {

  if(low[i])

  {

   DFS(i);

  }

 }



 while(S[0])

 {

  int c=S[S[0]];

  for(vector<int>::iterator it=El[c].begin();it!=El[c].end();++it)

  {

   int &nod=*it;

   if(SOL[nod]==0)

   {

    SOL[nod]=-1;

    SOL[NON(nod)]=1;

   }

  }

  --S[0];

 }



 int nrsol=0;

 for(register int i=1;i<=N;++i)

 {

  if(SOL[i]==1)

  {

   ++nrsol;

  }

 }



 fout<<nrsol<<"\n";

 for(register int i=1;i<=N;++i)

 {

  if(SOL[i]==1)

  {

   fout<<i<<"\n";

  }

 }

 fout.close();

 return 0;

}
