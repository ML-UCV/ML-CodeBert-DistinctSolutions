#include <fstream>
#include <cstring>


using namespace std;

ifstream cin("evaluare.in");
ofstream cout("evaluare.out");

char op[100005],s[100005];
int nr[100005],nr_top,n,op_top;

int hai(int a, int b, char c)
{
    if(c=='+')
        return a+b;
    else if(c=='*')
        return a*b;
    else if(c=='-')
        return a-b;
    else if(c=='/')
        return a/b;
    else
        return -1;
}

bool semn(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    return false;
}

bool cifra(char c)
{
    if(c<='9' && c>='0')
        return true;
    return false;
}

int prioritate(char c)
{
    if(c=='+' || c=='-')
        return 0;
    if(c=='*' || c=='/')
        return 1;
    return -1;
}

int main() {
    cin.getline(s,100005);
    n=(int)strlen(s);
    op[0]='(';
    s[n]=')';
    s[n+1]='\0';
    for(int i=0;i<=n;i++)
        if(cifra(s[i]))
        {
            int x=0;
            do
            {
                x=x*10+(int)(s[i]-'0');
                i++;
            }
            while (cifra(s[i]));
            i--;
            nr[++nr_top]=x;
        }
        else if(s[i]=='(')
            op[++op_top]=s[i];
        else if(s[i]==')')
        {
            while(op[op_top]!='(')
            {
                int x=hai(nr[nr_top-1], nr[nr_top],op[op_top]);
                nr_top--;
                nr[nr_top]=x;
                op_top--;
            }
            op_top--;
        }
        else if(semn(s[i]))
        {
            while(op_top>0 && prioritate(s[i])<=prioritate(op[op_top]))
            {
                int x=hai(nr[nr_top-1], nr[nr_top],op[op_top]);
                nr[--nr_top]=x;
                op_top--;
            }
            op[++op_top]=s[i];
        }
    cout<<nr[1];
    return 0;
}
