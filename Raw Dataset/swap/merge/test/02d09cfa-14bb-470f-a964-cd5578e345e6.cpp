#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream fin("swap.in");
ofstream fout("swap.out");

int n,i,j,u,nrn,rez,pfrz[250000],vs[250000];
string s;
vector<int> pos[300];

void make(int nd,int st,int dr)
{
 if(st==dr)
 {
  pfrz[++nrn]=nd;
  return;
 }
 int md=st+(dr-st)/2;
 make(2*nd,st,md);
 make(2*nd+1,md+1,dr);
}
int take(int nd,int sum)
{
 if(nd==1) return sum;
 if(nd/2*2+1!=nd) vs[nd/2*2+1]++;
 return take(nd/2,sum+vs[nd]);
}
int main() {

 getline(fin,s);
 n=(int)s.size();
 for(i=n-1;i>=0;i--)
  pos[s[i]-96].push_back(i);

 make(1,1,n);
 rez=-n;
 getline(fin,s);
 for(i=0;i<n;i++)
 {
  if(!pos[s[i]-96].size())
  {
   fout<<-1<<"\n";
   return 0;
  }
  u=pos[s[i]-96].back()+1;
  nrn=take(pfrz[u],0);
  rez+=u-nrn;
  pos[s[i]-96].pop_back();
 }
 fout<<rez<<"\n";
}
