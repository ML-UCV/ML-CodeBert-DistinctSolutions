#include <fstream>
#include <stack>
#include <string>
#include <map>


using namespace std;
ifstream fi("evaluare.in");
ofstream fo("evaluare.out");


char exp[100005], *p=exp;
map<char, int> OP;

void initOP();
bool op(char c);
int ordin(char c);
int efectueaza(int a, int b, char op);
int eval();
int termen();
int factor();



int main()
{
 fi>>exp;
 initOP();
 fo<<eval();

 fi.close();
 fo.close();
 return 0;
}

void initOP()
{
 OP['+']=1, OP['-']=1, OP['*']=2, OP['/']=2;
}


bool op(char c)
{
 return OP.find(c)!=OP.end();
}



int ordin(char c)
{
 return OP[c];
}


int efectueaza(int a, int b, char op)
{
 if (op == '+') return a+b;
 else if (op == '-') return a-b;
 else if (op == '*') return a*b;
 else return a/b;
}





int eval()
{
 int res=termen();
 while(op(*p) && ordin(*p)==1)
 {
  char aux = *p;
  p++;
  res=efectueaza(res, termen(), aux);
 }
 return res;
}


int termen()
{
 int res=factor();
 while(op(*p) && (ordin(*p) == 2))
 {
  char aux = *p;
  p++;
  res=efectueaza(res, factor(), aux);
 }
 return res;
}


int factor()
{
 int res=0;
    if ( *p == '(' )
    {
        p++;
  res = eval();
  p++;
    }
    else
    {
        while ( *p>='0' && *p<='9' )
        {
            res = res*10 + (*p - '0');
   p++;
  }
    }
    return res;
}
