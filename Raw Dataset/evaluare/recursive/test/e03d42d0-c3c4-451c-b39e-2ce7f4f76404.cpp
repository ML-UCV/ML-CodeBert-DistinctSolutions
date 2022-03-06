#include <fstream>

using namespace std;

const int N=200001;
char s[N];
int p = 0;

ifstream fin ("evaluare.in");
ofstream fout ("evaluare.out");

int expresie();
int termen();
int factor();

int expresie()
{
    int sum = termen();
    while( s[p] == '+' || s[p] == '-' )
    {
        if( s[p] == '+')
        {
            p++;
            sum+=termen();
        }
        else
        {
            p++;
            sum-=termen();
        }
    }
    return sum;
}

int termen()
{
    int prod = factor();
    while( s[p] == '*' || s[p] == '/')
    {
        if( s[p] == '*')
        {
            p++;
            prod*=factor();
        }
        else
        {
            p++;
            prod/=factor();
        }
    }
    return prod;
}

int factor()
{
    int val=0,semn=1;
    while( s[p] == '-' )
    {
        p++;
        semn=-semn;
    }
    if( s[p] == '(')
    {
        p++;
        val=expresie();
        p++;
        return semn*val;
    }
    while( s[p]>='0' && s[p]<='9')
    {
        val=val*10+s[p++]-'0';
    }
    return semn*val;
}

int main()
{
    fin.getline(s,200001);
    fout<<expresie();
    return 0;
}
