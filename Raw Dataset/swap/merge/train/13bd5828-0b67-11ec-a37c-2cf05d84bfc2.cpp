#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

ifstream f("swap.in"); ofstream g("swap.out");

const int Nmax=50005;

int n,nr,i,j,p[Nmax],v[Nmax],x[27],y[27];

char a[Nmax],b[Nmax];

vector <int> L[27];

void merge(int st, int dr, int m)

{ int i=st,j=m+1,k=st;

    while(i<=m && j<=dr)

  if(p[i]<p[j]) {v[k]=p[i]; k++; i++;}

   else {v[k]=p[j]; k++; j++; nr=nr+j-k;}

    while(i<=m) {v[k]=p[i]; k++; i++;}

    while(j<=dr) {v[k]=p[j]; k++; j++;}

    for(i=st;i<k;i++) p[i]=v[i];

}

void sort(int st, int dr)

{ int m;

    if(st<dr)

    { m=(st+dr)>>1;

        sort(st,m);

        sort(m+1,dr);

        merge(st,dr,m);

    }

}

int main()

{ f>>a+1>>b+1;

 n=strlen(a+1);

 for(i=1;i<=n;++i)

 { ++x[a[i]-'a']; ++y[b[i]-'a'];

  L[b[i]-'a'].push_back(i);

 }

 int e=0;

 for(i=0;i<26;++i)

  { if(x[i]!=y[i]) e=1;

   x[i]=0;

  }

 if(e) g<<"-1\n"; else

 {

  for(i=1;i<=n;++i)

  {

   j=x[a[i]-'a']++;

   p[i]=L[a[i]-'a'][j];

  }

  sort(1,n);

  g<<nr<<'\n';

 }

 g.close(); return 0;

}
