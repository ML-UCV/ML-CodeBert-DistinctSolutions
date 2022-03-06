#include <bits/stdc++.h>




using namespace std;



class InParser

{

private:

    FILE *fin;

    char *buff;

    int sp;



    char read_ch()

    {

        ++sp;

        if(sp==4096)

        {

            sp=0;

            fread(buff,1,4096,fin);

        }

        return buff[sp];

    }



public:

    InParser(const char* nume)

    {

        fin=fopen(nume,"r");

        buff=new char[4096]();

        sp=4095;

    }



    InParser& operator >> (int &n)

    {

        char c;

        while(!isdigit(c=read_ch())&&c!='-');

        int sgn=1;

        if (c=='-')

        {

            n=0;

            sgn=-1;

        }

        else

        {

            n=c-'0';

        }

        while(isdigit(c=read_ch()))

        {

            n=10*n+c-'0';

        }

        n*=sgn;

        return *this;

    }



    InParser& operator >> (long long &n)

    {

        char c;

        n=0;

        while(!isdigit(c=read_ch())&&c!='-');

        long long sgn=1;

        if(c=='-')

        {

            n=0;

            sgn=-1;

        }

        else

        {

            n=c-'0';

        }

        while(isdigit(c=read_ch()))

        {

            n=10*n+c-'0';

        }

        n*=sgn;

        return *this;

    }

};



class OutParser

{

private:

    FILE *fout;

    char *buff;

    int sp;



    void write_ch(char ch)

    {

        if(sp==50000)

        {

            fwrite(buff,1,50000,fout);

            sp=0;

            buff[sp++]=ch;

        }

        else

        {

            buff[sp++]=ch;

        }

    }



public:

    OutParser(const char* name)

    {

        fout=fopen(name,"w");

        buff=new char[50000]();

        sp=0;

    }

    ~OutParser()

    {

        fwrite(buff,1,sp,fout);

        fclose(fout);

    }



    OutParser& operator <<(int vu32)

    {

        if(vu32<=9)

        {

            write_ch(vu32+'0');

        }

        else

        {

            (*this) <<(vu32/10);

            write_ch(vu32%10+'0');

        }

        return *this;

    }



    OutParser& operator <<(long long vu64)

    {

        if(vu64<=9)

        {

            write_ch(vu64+'0');

        }

        else

        {

            (*this) <<(vu64/10);

            write_ch(vu64%10+'0');

        }

        return *this;

    }



    OutParser& operator <<(char ch)

    {

        write_ch(ch);

        return *this;

    }

    OutParser& operator <<(const char *ch)

    {

        while(*ch)

        {

            write_ch(*ch);

            ++ch;

        }

        return *this;

    }

};

InParser f ("ctc.in");

OutParser g ("ctc.out");



int n, m, x, y, viz[100005], nr;

vector < int > G[100005], GT[100005], CTC[100005];

stack < int > S;



void read () {

    f >> n >> m;

    while (m --) {

        f >> x >> y;

        G[x].push_back (y);

        GT[y].push_back (x);

    }

}



void DFSP (int k) {

    viz[k] = 1;

    for (unsigned int i = 0; i < G[k].size(); ++i) {

        int vecin = G[k][i];

        if (!viz[vecin]) DFSP (vecin);

    }

    S.push (k);

}



void DFSM (int k) {

    viz[k] = 2;

    CTC[nr].push_back (k);

    for (unsigned int i = 0; i < GT[k].size(); ++i) {

        int vecin = GT[k][i];

        if (viz[vecin] == 1) DFSM (vecin);

    }

}



void solve () {

    for (int i = 1; i <= n; ++i) if (!viz[i]) DFSP (i);

    while (!S.empty()) {

        int nod = S.top();

        S.pop();

        if (viz[nod] == 1) {

            nr ++;

            DFSM (nod);

        }

    }

}



void print () {

    g << nr << '\n';

    for (int i = 1; i <= nr; ++i, g << '\n')

    for (unsigned int j = 0; j < CTC[i].size(); ++j)

    g << CTC[i][j] << " ";

}



int main()

{

    read();

    solve();

    print();

    return 0;

}
