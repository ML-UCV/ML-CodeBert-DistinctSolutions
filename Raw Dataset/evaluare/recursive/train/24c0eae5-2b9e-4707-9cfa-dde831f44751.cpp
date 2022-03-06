#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f("evaluare.in");

ofstream g("evaluare.out");

char s[100000],*p;



long long eval();

long long term();

long long fact();



long long eval()

{long long r;

r=term();

while(*p=='+'||*p=='-')

   {if(*p=='+'){p++;r+=term();}

   else if(*p=='-'){p++;r-=term();}

   }

return r;

}



long long term()

{long long r=fact();

while(*p=='*'||*p=='/')

   {if(*p=='*'){p++;r*=fact();}

    else if(*p=='/'){p++;r=r/fact();}

   }

return r;

}



long long fact()

{long long r=0;

if(*p=='('){p++;r=eval();p++;}

else {

    while(*p>='0'&&*p<='9')

        {r=r*10+*p-'0';

        p++;

        }

    }

return r;

}



int main()

{

f.getline(s,100000);

p=s;

  g<<eval();





    return 0;

}
