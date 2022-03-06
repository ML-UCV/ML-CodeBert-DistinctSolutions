#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

ifstream f("swap.in"); ofstream g("swap.out");

const int Nmax=50001;

int n,nr,p[Nmax],v[Nmax],x[27],y[27];

char a[Nmax],b[Nmax];

vector <int> L[27];

void merge(int st, int dr, int m)

{ int i=st,j=m+1,k=st;

    while(i<=m && j<=dr)

  if(p[i]<p[j]) v[k++]=p[i++]; else v[k++]=p[j++], nr+=j-k;

    while(i<=m) v[k++]=p[i++];

    while(j<=dr) v[k++]=p[j++];

    for(i=st;i<k;i++) p[i]=v[i];

}

void sort(int st, int dr)

{ int m;

    if(st<dr)

    { m=(st+dr)>>1;

        sort(st,m); sort(m+1,dr); merge(st,dr,m);

    }

}

int main()

{ f>>a>>b; n=strlen(a);

 int i,e=0;

 for(i=0;i<n;++i) ++x[a[i]-'a'], ++y[b[i]-'a'], L[b[i]-'a'].push_back(i);

 for(i=0;i<26;++i)

  { if(x[i]!=y[i]) e=1;

   x[i]=0;

  }

 if(e) g<<"-1\n"; else

 { for(i=0;i<n;++i) p[i]=L[a[i]-'a'][x[a[i]-'a']++];

  sort(0,n-1);

  g<<nr<<'\n';

 }

 g.close(); return 0;

}
