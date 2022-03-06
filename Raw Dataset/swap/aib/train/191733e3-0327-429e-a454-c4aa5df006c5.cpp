#include<cstdio>
#include<cstring>
#include<list>
using namespace std;

list<int>L[27];

long long n,i,j,b,l,a[50100];

long long nr;

char s[50100],s1[50100];

FILE *f,*g;

void upd(int p,int x){

    for(int i=p;i<=l+1;i+=(i&(-i))){

        a[i]+=x;

    }

}

int query(int p){

    int s=0;

    for(int i=p;i>0;i-=(i&(-i))){

        s+=a[i];

    }

    return s;

}

int main(){

    f=fopen("swap.in","r");

    g=fopen("swap.out","w");

    fscanf(f,"%s%s",s,s1);

    l=strlen(s);

    for(i=0;i<l;i++){

        L[ s[i]-'a' ].push_back(i+1);

    }

    nr=l*(l-1)/2;

    for(i=0;i<l;i++){

        if(L[ s1[i]-'a' ].size()==0){

            fprintf(g,"-1");

            return 0;

        }

        b=L[ s1[i]-'a' ].front();

        upd(b,1);

        nr-=query(b-1);

        L[ s1[i]-'a' ].pop_front();

    }

    fprintf(g,"%lld",nr);

    fclose(f);

    fclose(g);

    return 0;

}
