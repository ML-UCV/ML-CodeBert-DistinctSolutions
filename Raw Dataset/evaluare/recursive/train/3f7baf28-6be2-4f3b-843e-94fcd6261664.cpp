#include <fstream>
using namespace std;

ifstream f ("evaluare.in");

ofstream g ("evaluare.out");

const int nmax=1e5+3;

char s[nmax];

int fact();

int termen(),k;



int eval()

{

      int r=termen();

      while(s[k]=='+'||s[k]=='-')

      {

            ++k;

            if(s[k-1]=='-') r-=termen();

            else r+=termen();

      }

      return r;

}



int termen()

{

      int r=fact();

      while(s[k]=='*'||s[k]=='/')

      {

            ++k;

            if(s[k-1]=='*') r*=fact();

            else r/=fact();

      }

      return r;

}



int fact()

{

      int r=0;

      if(s[k]=='(')

      {

            ++k;

            r=eval();

            ++k;

      }



      while(s[k]>='0'&&s[k]<='9')

      {

            r=r*10+s[k]-'0';

            ++k;

      }



      return r;

}



int main()

{

      f.getline(s+1,nmax-1);

      k=1;

      g<<eval();

      return 0;

}
