#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(int &numar)
{
     numar = 0;
     while (buff[poz] < '0' || buff[poz] > '9')
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
}

int n,m,x,y,s,d,c;
int cs[30001];
bool viz[30001];
queue<int> q;

struct sat
{
    vector<int> vecini;
    vector<int> cost;
} a[30001];

int main()
{
    freopen("sate.in","r",stdin);
    freopen("sate.out","w",stdout);

    citeste(n);
    citeste(m);
    citeste(x);
    citeste(y);
    if(x>y)
    {
        int t=y;
        y=x;
        x=t;
    }

    for(int i=1;i<=m;i++)
    {
        citeste(s);
        citeste(d);
        citeste(c);
        if(s>d)
        {
            int t=d;
            d=s;
            s=t;
        }
        a[s].vecini.push_back(d);
        a[s].cost.push_back(c);
        a[d].vecini.push_back(s);
        a[d].cost.push_back(-c);
    }

    q.push(x);
    int current;
    while(!q.empty())
    {
        current=q.front();
        q.pop();
        if(current==y)
        {
            break;
        }
        int vc;
        int dst;
        while(!a[current].vecini.empty())
        {
            vc=a[current].vecini.back();
            dst=a[current].cost.back();
            if(viz[vc]==0)
            {
                viz[vc]=1;
                cs[vc]=cs[current]+dst;
                q.push(vc);
            }
            a[current].vecini.pop_back();
            a[current].cost.pop_back();
        }
    }
    printf("%d",cs[y]);
}
