#include<cstdio>
#include<cstring>
#include<list>
using namespace std;

list<int>L[27];

long long n,m,i,j,l,a[50100],x,sum,w[50100];

char s[50100],s1[50100];

FILE *f,*g;

int query(int p){

    int s=0;

    for(int i=p;i>0;i-=(i&-i)){

        s+=a[i];

    }

    return s;

}

void update(int p,int x){

    for(int i=p;i<=l+1;i+=(i&-i)){

        a[i]+=x;

    }

}

int main(){

    f=fopen("swap.in","r");

    g=fopen("swap.out","w");

    fscanf(f,"%s\n%s",s,s1);

    l=strlen(s);

    for(i=0;i<l;i++){

        L[s[i]-'a'].push_back(i+1);

    }

    sum=(l-1)*l/2;

    for(i=0;i<l;i++){

        if(L[s1[i]-'a'].size()==0){

            fprintf(g,"-1");

            return 0;

        }

        w[i+1]=L[s1[i]-'a'].front();

        x=w[i+1];

        update(x,1);

        sum-=query(x-1);

        L[s1[i]-'a'].pop_front();

    }

    fprintf(g,"%lld",sum);





    fclose(f);

    fclose(g);

    return 0;

}
