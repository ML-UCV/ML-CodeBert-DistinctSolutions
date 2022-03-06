#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
using namespace std;



int N,Q;



vector <int> D[250005];

vector <int> :: iterator it;



int P[250005];

int LEVEL[250005];

int TABLE[250005][20];



FILE *_fin;

int _in_loc;

char _in_buff[4096];



FILE *_fout;

int _out_loc;

char _out_buff[50000];







void write_init(const char* name)

{

    _fout=fopen(name, "w");

    _out_loc=0;

}



void write_ch(char ch)

{

    if (_out_loc==50000)

    {

        fwrite(_out_buff,1,50000,_fout);

        _out_loc=0;

        _out_buff[_out_loc++]=ch;

    }

    else

    {

        _out_buff[_out_loc++]=ch;

    }

}



void write_u32(unsigned int vu32)

{

    if (vu32<=9)

    {

        write_ch(vu32+'0');

    }

    else

    {

        write_u32(vu32/10);

        write_ch(vu32%10+'0');

    }

}



void write_appendix()

{

    fwrite(_out_buff,1,_out_loc,_fout);

    fclose(_fout);

}



void read_init(const char* nume)

{

 _fin=fopen(nume, "r");

 _in_loc=4095;

}



char read_ch()

{

 ++_in_loc;

 if (_in_loc==4096)

    {

        _in_loc = 0;

  fread(_in_buff,1,4096,_fin);

 }

 return _in_buff[_in_loc];

}



int read_u32()

{

 int u32 = 0; char c;

 while (!isdigit(c=read_ch()) && c!='-')

    {



    }

 int sgn=1;

 if (c=='-')

    {

  sgn=-1;

 }

 else

    {

  u32=c-'0';

 }

 while (isdigit(c=read_ch()))

    {

  u32=u32*10+c-'0';

 }

 return u32*sgn;

}



void df (int varf,int level)

{

    vector <int> :: iterator it;

    LEVEL[varf]=level;

    for (it=D[varf].begin();it!=D[varf].end();++it)

    {

        df(*it,level+1);

    }

}



int walk (int varf,int dist)

{



    if (LEVEL[varf]<=dist)

    {

        return 0;

    }

    int p;

    for (p=18;p>=0;--p)

    {

        if((1<<p)<=dist)

        {

            varf=TABLE[varf][p];

            dist=dist-(1<<p);

        }

    }

    return varf;

}



int main()

{

    read_init("stramosi.in");

    write_init("stramosi.out");

 N=read_u32();

 Q=read_u32();

    int i,j,c,v;

    for (i=1;i<=N;++i)

    {

        int parinte;

        parinte=read_u32();

        P[i]=parinte;

        D[parinte].push_back(i);

    }
    for (i=1;i<=N;++i)

    {

        if (P[i]==0)

        {

            df(i,1);

        }

    }
    for (i=1;i<=N;++i)

    {

        TABLE[i][0]=P[i];

    }

    for (c=1;c<=18;++c)

    {

        for (v=1;v<=N;++v)

        {

            if ((1<<c)>=LEVEL[v])

            {

                TABLE[v][c]=0;

            }

            else

            {

                TABLE[v][c]=TABLE[TABLE[v][c-1]][c-1];

            }

        }

    }
    for (i=1;i<=Q;++i)

    {

        int v,d;

        v=read_u32();

        d=read_u32();

        int varf=walk(v,d);

        write_u32(varf);

        write_ch('\n');

    }

    write_appendix();

    return 0;

}
