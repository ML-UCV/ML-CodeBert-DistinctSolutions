#include <fstream>

using namespace std;
ifstream cin ("stramosi.in");
ofstream cout ("stramosi.out");
int t[250003],r[250003][18],log[250003];
int main()
{
    int n,m,i,j,p,a,b;
    cin>>n>>m;
    for(i=2;i<=n;++i)
        log[i]=log[i/2]+1;
    for(i=1;i<=n;++i)
    {
        cin>>t[i];
        for(j=0;j<=log[n];++j)
        {
            if(j==0)
                r[i][j]=t[i];
            else
                r[i][j]=r[r[i][j-1]][j-1];
        }
    }
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        p=1<<17;
        while(p)
        {
            if(b>=p)
            {
                b-=p;
                a=r[a][log[p]];
            }
            p>>=1;
        }
        cout<<a<<'\n';
    }
    return 0;
}
