#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;

int aint[4*50005], nxt[50005], lst[27];
int n;
char a[50005];

int pozx, pozy;

void update(int nod, int left, int right)
{
    if(left==right)
    {
  aint[nod]++;
  return;
 }
 int mid=(left+right)/2;
 if(pozx<=mid) update(2*nod, left, mid);
 else update(2*nod+1, mid+1, right);
 aint[nod]=aint[2*nod]+aint[2*nod+1];
}

int query(int nod, int left, int right)
{
    if(pozx<=left&&right<=pozy)
    {
  return aint[nod];
 }
 int mid=(left+right)/2, ret=0;
 if(pozx<=mid) ret+=query(2*nod, left, mid);
 if(mid<pozy) ret+=query(2*nod+1, mid+1, right);
 return ret;
}

int main()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int i, poz, p, ok=1;
    int sol=0;
    a[0]='!';
    fgets(a+1, 50005, stdin);
    n=strlen(a)-2;
    for(i=n;i;i--)
    {
        nxt[i]=lst[a[i]-'a'];
        lst[a[i]-'a']=i;
    }
    fgets(a+1, 50005, stdin);
    for(i=1;a[i]!='\n';i++)
    {
        p=a[i]-'a';
        if(!lst[p])
        {
            ok=0;
            break;
        }
        poz=lst[p];
        lst[p]=nxt[lst[p]];
        pozx=poz;pozy=n;
        sol+=poz+query(1, 1, n)-i;
        pozx=poz;
        update(1, 1, n);
    }
    if(ok) printf("%d", sol);
    else printf("-1");
}
