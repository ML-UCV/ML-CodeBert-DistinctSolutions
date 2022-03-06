#include<cstdio>
#include<vector>
using namespace std;

const int N=100001;

vector<int> s[N],u[N],v[N];

int n,m,a[N],c,r,x,y,i,j;

bool b[N];

void A(int i)

{

    if(b[i])

  return;

 int j,k;

 for(b[i]=1,k=u[i].size(),j=0;j<k;j++)

  A(u[i][j]);

    a[++c]=i;

}

void B(int i)

{

    if(!b[i])

  return;

 int j,k;

 for(b[i]=j=0,k=v[i].size();j<k;j++)

     B(v[i][j]);

    s[r].push_back(i);

}

int main()

{

    freopen("ctc.in","r",stdin),freopen("ctc.out","w",stdout),scanf("%d%d",&n,&m);

    while(m--)

     scanf("%d%d",&x,&y),u[x].push_back(y),v[y].push_back(x);

    for(i=1;i<=n;i++)

  A(i);

    for(i=n;i;i--)

  if(b[a[i]])

   r++,B(a[i]);

 for(printf("%d\n",r),i=r;i;i--)

 {

  for(c=s[i].size(),j=0;j<c;j++)

   printf("%d ",s[i][j]);

  printf("\n");

 }

}
