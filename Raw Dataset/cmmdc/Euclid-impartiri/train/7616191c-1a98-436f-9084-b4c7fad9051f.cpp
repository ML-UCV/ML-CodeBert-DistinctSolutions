#include <cstdio>

using namespace std;

FILE *f = fopen("cmmdc.in","r");
FILE *g = fopen("cmmdc.out","w");

int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a % b);
}

int main(){

    int a,b;

    fscanf(f,"%d %d",&a,&b);

    fprintf(g,"%d\n",gcd(a,b) == 1 ? 0:gcd(a,b));

    fclose(f);
    fclose(g);

    return 0;
}
