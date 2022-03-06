#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

struct nod
{
    int val,d;
    nod *next;
};
nod *l[30001];
int n,m,s,f;
int dis[30001];

void adauga(int i,int j,int z)
{
    nod *a=new nod;
    a->val=j;
    a->d=z;
    a->next=l[i];
    l[i]=a;
}

void citire()
{
        fin>>n>>m>>s>>f;
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            fin>>x>>y>>z;
            adauga(x,y,z);
            adauga(y,x,z);
        }
}

void parcurgere()
{
    queue<int> q;
    q.push(s);
    dis[s]= 0;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(nod *p=l[top];p!=NULL;p=p->next)
        {
            if(dis[p->val]==0 and p->val!=s)
            {
                if(top>=s and p->val>=s)
                {
                    if(top>p->val) dis[p->val]=dis[top]-p->d;
                    else dis[p->val]=dis[top]+p->d;
                }
                if(top<=s and p->val<=s)
                {
                    if(top<p->val) dis[p->val]=dis[top]-p->d;
                    else dis[p->val]=dis[top]+p->d;
                }
                if((top<=s and p->val>=s) or (top>=s and p->val<=s))
                {
                   dis[p->val]=p->d-dis[top];
                }
                q.push(p->val);
            }

        }
    }
}

int main()
{
 citire();
 parcurgere();
 fout<<dis[f];
    return 0;
}
