#include <fstream>
using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int N,M,X,Y,s[30002],a[100025],b[100025],d[100025];

int main()
{
    f>>N>>M>>X>>Y;
    s[X]=1;
    for(int i=1;i<=M;++i)
    {
        f>>a[i]>>b[i]>>d[i];
    }

    f.close();
    while(!s[Y])
    {
        for(int i=1;i<=M;++i)
            {
             if(s[a[i]] && !s[b[i]])
                {
                    s[b[i]]=s[a[i]]+d[i];
                }
            else
                if(!s[a[i]] && s[b[i]])
                    {
                        s[a[i]]=s[b[i]]-d[i];
                    }
            }
    }

    g<<s[Y]-1;
    return 0;
}
