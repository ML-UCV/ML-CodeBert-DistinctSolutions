#include<fstream>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int N,M,x,y,s[30003],a[100025],b[100025],d[100025];
int main()
{
    f>>N>>M>>x>>y;

    s[x]=1;

    for( int i=1; i<=M; i++ )
      f>>a[i]>>b[i]>>d[i];

    while(!s[y])
        {
            for( int i=1; i<=M; i++ )
            {
                if( s[a[i]]&&!s[b[i]] )
                s[b[i]]=s[a[i]]+d[i];
    else
        if( !s[a[i]]&&s[b[i]] )
        s[a[i]]=s[b[i]]-d[i];
            }
        }

    g<<s[y]-1<<"\n";

    return 0;
}


