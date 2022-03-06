#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

struct nod{ int poz;

char c;};

ofstream fout("swap.out");

nod s1[50005],s2[50005];

char aux1[50005],aux2[50005];

int P[50005],M[1000],aib[50005],M1[1000],p=1,N1,N2;

long long S;

vector<int>m[50005];

void cit()

{int i,j;

    ifstream fin("swap.in");

    fin>>aux1>>aux2;

    N1=strlen(aux1),N2=strlen(aux2);

    for(i=0;aux1[i];i++)

     {s1[i].c=aux1[i];

      if(i==0||M[(int)s1[i].c]==0)

         {s1[i].poz=1;

         M[(int)s1[i].c]=1;

         }

         else s1[i].poz=M[(int)s1[i].c]+1,M[(int)s1[i].c]++;

     }

    for(i=0;aux2[i];i++)

    { s2[i].c=aux2[i];

    M1[(int)s2[i].c]++;

    }

    if(N1==N2)

     for(i=1;i<=500;i++)

      if(M[i]!=M1[i])

       {p=0; return;}





    cout<<1;

    for(i=0;s2[i].c;i++)

     {

     m[s2[i].c-'a'+1].push_back(i+1);

     }

     for(i=0;s1[i].c;i++)

     P[i+1]=m[s1[i].c-'a'+1][s1[i].poz-1];



         fin.close();

}



long long query(int p)

{long long s=0,i;

for(i=p;i;i-=i&-i)

 s+=aib[i];

return s;

}

void update (int p,int x)

 {long i;

 for(i=p;i<=N1;i+=i&-i)

  aib[i]+=x;



 }

void solve()

{int i;

    for(i=1;i<=N1;i++)

    {S+=(query(N1)-query(P[i]));



    update(P[i],1);

    }

    fout<<S;



}

int main()

{int i,j;

    cit();



    if(p==1)

    solve();

    else

    fout<<-1;

    fout.close();

    return 0;

}
