#include<cstdio>
#include<cstring>


char s[2000001],u[2000001];

int v[1001],i,t,k,m,n,j,p[2000001],q;

int main()

{

    freopen("strmatch.in","r",stdin),freopen("strmatch.out","w",stdout),scanf("%s\n%s",s,u),m=strlen(s),n=strlen(u);

    for(i=2;i<m;i++)

    {

        while(k&&s[k+1]!=s[i])

            k=p[k];

        if(s[k+1]==s[i])

            k++;

        p[i]=k;

    }

    for(j=1;j<n;j++)

    {

        while(q&&s[q+1]!=u[j])

            q=p[q];

        if(s[q+1]==u[j])

            q++;

        if(q==m-1&&s[0]==u[j-q])

        {

            if(t<1000)

                v[t]=j-m+1;

            t++;

        }

    }

    printf("%d\n",t);

    for(i=0;i<(t>1000?1000:t);i++)

        printf("%d ",v[i]);

}
