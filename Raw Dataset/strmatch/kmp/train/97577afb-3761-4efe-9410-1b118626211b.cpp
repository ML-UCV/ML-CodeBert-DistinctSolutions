#include <fstream>
#include <cstring>




using namespace std;

ifstream in("strmatch.in");

ofstream out("strmatch.out");



char model[2000000 +5], s[2000000 +5];

int pr[2000000 +5], cod[1005];

int n,m,cnt;



inline void prefix()

{

    int i, q;

    q=-1;

    pr[0]=-1;

    for(i=1;i<m;i++)

    {

        while(q!=-1 && model[q+1]!=model[i])

            q=pr[q];

        if(model[q+1]==model[i])

            q++;

        pr[i]=q;

    }

}



inline void solve()

{

    int i,q;

    q=-1;

    for(i=0;i<n;i++)

    {

        while(q!=-1 && model[q+1]!=s[i])

            q=pr[q];

        if(model[q+1]==s[i])

            q++;

        if(q==m-1)

        {

            cnt++;

            if(cnt<=1000) cod[cnt]=i-m+1;

            q=pr[m-1];

        }

    }

}



int main()

{

    in>>model; in.get();

    in>>s;

    m=strlen(model);

    n=strlen(s);



    prefix();

    solve();



    out<<cnt<<'\n';

    if(cnt>1000) cnt=1000;

    for(int i=1;i<=cnt;i++) out<<cod[i]<<' ';

    return 0;

}
