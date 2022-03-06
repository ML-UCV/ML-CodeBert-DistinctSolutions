# include <bits/stdc++.h>
char a[50005];

char b[50005];

int r[26];

std :: queue < int > v[26];

int s[200005],p[50005];

int n;

void update(int p,int u,int v,int nod)

{

    if (p == u) s[nod] = 1;

    else

    {

        int m = (p + u) / 2;

        if (v <= m) update(p,m,v,nod*2);

        else update(m+1,u,v,nod*2+1);

        s[nod] = s[nod*2] + s[nod*2+1];

    }

}

int query(int p,int u,int r,int nod)

{

    if (u <= r) return s[nod];

    int ans = 0;

    int m = (p + u) / 2;

    ans += query(p,m,r,nod*2);

    if (m+1<=r) ans += query(m+1,u,r,nod*2+1);

    return ans;

}

int main(void)

{

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);

    fgets(a+1, 50001, stdin);fgets(b+1, 50001, stdin);

    n = strlen(a+1);

    for (int i = 1;i <= n;++i) a[i] -= 'a',b[i] -= 'a';

    for (int i = 1;i <= n;++i) ++r[a[i]],--r[b[i]];

    for (int i = 0;i < 26;++i) if (r[i])

                        return printf("-1\n"),0;

    for (int i = 1;i <= n;++i)

        v[b[i]].push(i);

    int ans = 0;

    for (int i = 1;i <= n;++i)

        {

            p[i] = n - v[a[i]].front() + 1;v[a[i]].pop();

        }

    for (int i = 1;i <= n;++i) ans += query(1,n,p[i],1),update(1,n,p[i],1);

    return printf("%d\n",ans),0;

}
