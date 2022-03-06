#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>






char buf[16384];

int pbuf=16384;

FILE*fi,*fo;

inline char nextch(){

    if(pbuf==16384){

        fread(buf, 16384, 1, fi);

        pbuf=0;

    }

    return buf[pbuf++];

}

inline long long nextnum(){

    long long a=0;

    char c=nextch();

    while((c<'0' || c>'9') && c!='-')

        c=nextch();

    int semn=1;

    if(c=='-'){

        semn=-1;

        c=nextch();

    }

    while('0'<=c && c<='9'){

        a=a*10+c-'0';

        c=nextch();

    }

    return a*semn;

}





int aib[50000 +1], n;

inline void add(int poz,int nr){

    for(int i=poz;i<=n;i+=(((i-1)^i)&i))

        aib[i]+=nr;

}

inline int sum(int poz){

    int s=0;

    for(int i=poz;i>0;i-=(((i-1)^i)&i))

        s=s+aib[i];

    return s;

}



char v1[50000 +1], v2[50000 +1];

int f1[27], f2[27];

int p[50000 +1];

std::vector <int> poz[27];

int last[27];

int main(){

    fi=fopen("swap.in","r");

    fo=fopen("swap.out","w");

    char c=nextch();

    int n1=0;

    while('a'<=c && c<='z'){

        v1[++n1]=c-'a'+1;

        f1[c-'a'+1]++;

        c=nextch();

    }



    c=nextch();

    int n2=0;

    while('a'<=c && c<='z'){

        v2[++n2]=c-'a'+1;

        poz[c-'a'+1].push_back(n2);

        f2[c-'a'+1]++;

        c=nextch();

    }



    int z=1;

    while(z<27 && f1[z]==f2[z])

        z++;

    if(z!=27){

        fprintf(fo,"-1");

        return 0;

    }

    for(int i=1;i<=n1;i++)

        p[i]=poz[v1[i]][last[v1[i]]++];

    int ans=0;

    n=n1;

    for(int i=n1;i>0;i--){

        ans+=sum(p[i]);



        add(p[i], 1);

    }

    fprintf(fo,"%d", ans);

    fclose(fi);

    fclose(fo);

    return 0;

}
