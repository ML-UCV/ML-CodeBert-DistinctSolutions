#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;



FILE *IN,*OUT;

int pos=0,out=0,sign,N,Ans=0,Total=0,Start,End,c1[26],c2[26];

int first[50005],apear[27],second[26][50005],Val;

char f[131072],Out[131072],str[10],c;



struct _Tree

{

    int Lower,Pos;

}T[132000];

inline void R_Ch(char &ch)

{

    ch=f[pos++];

     if(pos==131072)

            fread(f,131072,1,IN),pos=0;

}

inline void Write_Ch(char ch)

{

    Out[out++]=ch;

    if(out==131072)

        fwrite(Out,131072,1,OUT),out=0;

}

inline void Write_Int(int nr)

{

    int x=0;

    if(nr<0)Write_Ch('-'),nr=-nr;

    do

    {

        str[x++]=nr%10+'0';

        nr/=10;

    }

    while(nr);

    while(x>0)

        Write_Ch(str[--x]);

}

inline int max2(int a,int b)

{

    if (a>b) return a;

    else return b;

}

inline void Read(int &nr)

{

    sign=0;

    nr=0;

    while(f[pos]<'0'||f[pos]>'9')

    {

        if(f[pos]=='-')sign=1;

        pos++;

        if(pos==131072)

            fread(f,131072,1,IN),pos=0;

    }

    while(f[pos]>='0'&&f[pos]<='9')

    {

        nr=10*nr+f[pos++]-'0';

        if(pos==131072)

            fread(f,131072,1,IN),pos=0;

    }

    if(sign)nr=-nr;

}



void Update(int node,int start,int end,int V)

{

    if(start==end)

        T[node].Pos=V;

    else

    {

        int mid=(start+end)>>1;

        if(V<=mid)Update(2*node,start,mid,V);

        else Update(2*node+1,mid+1,end,V);

    }

}

void Query(int node,int start,int end)

{

    if(start==end)

    {

        Ans+=T[node].Pos+T[node].Lower;

        return;

    }

    else

    {

        Ans+=T[node].Lower;

        int mid=(start+end)>>1;

        if(Val<=mid)Query(2*node,start,mid);

        else

        {

            T[2*node].Lower++;

            Query(2*node+1,mid+1,end);

        }

    }

}

int main()

{

    IN=fopen("swap.in","r");

    OUT=fopen("swap.out","w");



    fread(f,1,131072,IN);

    R_Ch(c);

    while(c!='\n')

    {

        c1[c-'a']++;

        first[++N]=c-'a';

        R_Ch(c);

    }

    for(int i=1;i<=N;i++)

    {

        R_Ch(c);

        c2[c-'a']++;

        second[c-'a'][++apear[c-'a']]=i;

        Update(1,1,N,i);

    }

    bool possible=true;

    for(int i=0;i<=25&&possible;i++)

        if(c1[i]!=c2[i])possible=false;

    if(!possible)

    {

        Write_Ch('-');

        Write_Ch('1');

    }

    else

    {

        memset(apear,0,sizeof apear);

        for(int i=1;i<=N;i++)

        {

            Ans=0;

            Val=second[first[i]][++apear[first[i]]];

            Query(1,1,N);

            Total+=Ans-i;

        }

        Write_Int(Total);

    }

    if(out>0)fwrite(Out,1,out,OUT);

    return 0;

}
