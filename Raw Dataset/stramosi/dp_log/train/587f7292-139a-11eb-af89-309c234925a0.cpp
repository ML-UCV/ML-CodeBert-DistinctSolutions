#include <cstdio>
using namespace std;

const int N=250005;

int p[20][N];

int lg2[N];

const int put[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};

int main()

{

    FILE*fin,*fout;

    fin=fopen("stramosi.in","r");

    fout=fopen("stramosi.out","w");

    int n,q;

    fscanf(fin,"%d%d",&n,&q);

    for(int i=1;i<=n;++i)

        fscanf(fin,"%d",&p[0][i]);

    lg2[1]=0;

    for(int i=2;i<N;++i)

        lg2[i]=lg2[i/2]+1;

    for(int log=1;log<20;++log)

        for(int i=1;i<=n;++i)

            p[log][i]=p[log-1][p[log-1][i]];

    int poz,rk;

    for(int i=1;i<=q;++i)

    {

        fscanf(fin,"%d%d",&poz,&rk);

        while(rk)

        {

            poz=p[lg2[rk]][poz];

            if(poz==0)

                break;

            rk-=put[lg2[rk]];

        }

        fprintf(fout,"%d\n",poz);

    }

    return 0;

}
