#include <cstdio>
#include <vector>





using namespace std;





int N,M;
vector <short int> L[2*105];
vector <short int> T[2*105];
short int timp[2*105],order[2*105];
int next_time;
short int CTC[2*105],cnt_ctc=0;

vector <short int> LCTC[2*105];
short int timeCTC[2*105];
vector <short int> sol;

inline short int cuminus(short int x)
{
 if(x<=N)
  return x+N;
 else
  return x-N;
}

inline void add(short int a, short int b)
{
 L[cuminus(a)].push_back(b); T[b].push_back(cuminus(a));
 L[cuminus(b)].push_back(a); T[a].push_back(cuminus(b));
}

void get_data()
{
 short int u,v,type;
 scanf("%d %d",&N,&M);
 for(int i=0;i<M;i++)
 {
  scanf("%hd %hd %hd",&u,&v,&type);
  switch(type)
  {
   case 0: add(u,v);
    break;
   case 1: add(u,cuminus(v));
    break;
   case 2: add(cuminus(u),v);
    break;
   case 3: add(cuminus(u),cuminus(v));
    break;
  }
 }
}

void df1(int vertex)
{
 for(vector <short int>::iterator i=L[vertex].begin(); i!=L[vertex].end(); ++i)
  if(timp[*i]==-1)
  {
   timp[*i]=0;
   df1(*i);
   ++next_time;
  }
 timp[vertex]=next_time;
}

void df2(int vertex)
{
 for(vector <short int>::iterator i=T[vertex].begin(); i!=T[vertex].end(); ++i)
  if(!CTC[*i])
  {
   CTC[*i]=cnt_ctc;
   df2(*i);
  }
}

void df3(int vertex)
{
 for(vector <short int>::iterator i=LCTC[vertex].begin(); i!=LCTC[vertex].end(); ++i)
  if(timeCTC[*i]==-1)
  {
   timeCTC[*i]=0;
   df3(*i);
   ++next_time;
  }
 timeCTC[vertex]=next_time;
}


int main()
{
 freopen("party.in","r",stdin);
 freopen("party.out","w",stdout);
 get_data();

 int i;
 next_time=1;
 for(i=1;i<=2*N;i++)
  timp[i]=-1;
 for(i=1;i<=2*N;i++)
  if(timp[i]==-1)
  {
   timp[i]=0;
   df1(i);
   ++next_time;
  }
 for(i=1;i<=2*N;i++)
 {
  order[2*N-timp[i]+1]=i;
  CTC[i]=0;
 }
 for(i=1;i<=2*N;i++)
  if(!CTC[order[i]])
  {
   CTC[order[i]]=++cnt_ctc;
   df2(order[i]);
  }

 for(i=1;i<=2*N;i++)
  for(vector <short int>::iterator it=L[i].begin(); it!=L[i].end(); ++it)
   if(CTC[i]!=CTC[*it])
    LCTC[CTC[i]].push_back(CTC[*it]);
 next_time=1;
 for(i=1;i<=cnt_ctc;i++)
  timeCTC[i]=-1;
 for(i=1;i<=cnt_ctc;i++)
  if(timeCTC[i]==-1)
  {
   timeCTC[i]=0;
   df3(i);
   ++next_time;
  }

 for(i=1;i<=N;i++)
  if(timeCTC[CTC[i]]<timeCTC[CTC[cuminus(i)]])
   sol.push_back(i);

 printf("%d\n",(int)sol.size());
 for(vector <short int>::iterator it=sol.begin(); it!=sol.end(); ++it)
  printf("%d\n",(int)(*it));
 printf("23");

 return 0;
}
