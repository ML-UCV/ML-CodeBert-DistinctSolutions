#include <fstream>
#include <stdint.h>
#include <math.h>



using namespace std;
fstream f1("dmin.in", ios::in);
fstream f2("dmin.out", ios::out);
int32_t nr[1505];
int16_t viz[1505], n, m;
double a[1505][1505], d[1505];
const double ep=0.00000001;
const double inf=999999999;
void citire()
{
    int32_t c;
    int16_t i, j, x, y;
    f1>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        if(i!=j)
    {
        a[i][j]=inf;
        a[j][i]=inf;
    }
    for(i=1; i<=m; i++)
    {
        f1>>x>>y>>c;
        a[x][y]=log(c);
        a[x][y]=log(c);
    }
}
double modul(double val)
{
    if(val>=0.0) return 0;
    else return (-val);
}
void dijkstra(int16_t x0)
{
    double mini;
    int16_t i, j, vfmin;

    viz[x0]=1;
    for(i=1; i<=n; i++)
        {
            d[i]=a[x0][i];
            if(a[x0][i]!=inf) nr[i]=1;
        }

    for(i=1; i<n; i++)
    {
        mini=inf;
        vfmin=0;
        for(j=1; j<=n; j++)
            if((!viz[j])&&(d[j]<mini))
        {
            vfmin=j;
            mini=d[j];
        }
        viz[vfmin]=1;
        if(vfmin!=0)
        {
            for(j=1; j<=n; j++)
                if((!viz[j])&&(j!=vfmin))
            {
                if((d[j]-d[vfmin]-a[vfmin][j])>=ep)
                {
                    d[j]=d[vfmin]+a[vfmin][j];
                    nr[j]=nr[vfmin];
                }
                else if(modul(d[j]-(d[vfmin]+a[vfmin][j]))<=ep)
                        {
                            nr[j]+=nr[vfmin];
                            nr[j]%=104659;
                        }
            }
        }
    }
}
void afis()
{
    int16_t i;
    for(i=2; i<=n; i++)
        f2<<nr[i]<<" ";
}
int main()
{
    citire();
    dijkstra(1);
    afis();
    return 0;
}
