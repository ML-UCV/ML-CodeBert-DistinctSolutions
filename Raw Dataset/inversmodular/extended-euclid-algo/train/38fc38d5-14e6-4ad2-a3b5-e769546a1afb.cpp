#include <cstdio>


int inv_mod(int x,int b)

{

    int r,q[100],nr=0,bz=b;

    while(b)

    {

        q[++nr]=x/b;

        r=x%b;

        x=b;b=r;

    }

    int a=1,a1,b1;

    b=0;

    while(nr)

    {

        a1=b;

        b1=a-q[nr--]*b;

        a=a1;b=b1;

    }

    return ((long long)bz+a%bz)%bz;

}



int main()

{

    int a,b;FILE *f=fopen("inversmodular.in","r");

    fscanf(f,"%d%d",&a,&b);

    f=fopen("inversmodular.out","w");

    fprintf(f,"%d",inv_mod(a,b));

    return 0;

}
