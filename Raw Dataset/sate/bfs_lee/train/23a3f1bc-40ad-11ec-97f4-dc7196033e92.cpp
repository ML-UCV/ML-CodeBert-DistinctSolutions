#include <cstdio>
#include <vector>
#include <queue>
#define DIM 10000
#define DN 30001
using namespace std;
int n,m,x,y;
char buff[DIM];
int poz=0;
vector<pair<int,int> > V[DN];
queue<int> Q;
int VIZ[DN];
FILE *fi,*fo;
void citeste(int &numar)
{
     numar = 0;
     //cat timp caracterul din buffer nu e cifra ignor
     while (buff[poz] < '0' || buff[poz] > '9')
          //daca am "golit" bufferul atunci il umplu
          if (++poz == DIM)
               fread(buff,1,DIM,fi),poz=0;
     //cat timp dau de o cifra recalculez numarul
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,fi),poz=0;
     }
}
void bfs(int s)
{
    Q.push(s);
    VIZ[s]=1;
    while(!Q.empty())
    {
        int nod=Q.front();
        Q.pop();
        for(auto to:V[nod])
            if(!VIZ[to.first])
            {
                VIZ[to.first]=VIZ[nod]+to.second;
                if(to.first<nod)
                    VIZ[to.first]-=2*to.second;
                Q.push(to.first);
            }
    }
}
int main()
{
    fi=fopen("sate.in","r");
    fo=fopen("sate.out","w");
    citeste(n);
    citeste(m);
    citeste(x);
    citeste(y);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        citeste(a);
        citeste(b);
        citeste(c);
        V[a].push_back(make_pair(b,c));
        V[b].push_back(make_pair(a,c));
    }
    bfs(x);
    fprintf(fo,"%d",VIZ[y]-1);
    fclose(fi);
    fclose(fo);
    return 0;
}
