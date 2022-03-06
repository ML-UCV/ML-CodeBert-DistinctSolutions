#include <fstream>
using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



string s;

int ind;



int pri0();

int pri1();

int pri2();





int pri0(){

  int x=pri1();

  while(s[ind]=='+'||s[ind]=='-'){

    if(s[ind]=='+') ind++, x=x+pri1();

    else ind++, x-=pri1();

  }

  return x;

}



int pri1(){

  int x=pri2();

  while(s[ind]=='*'||s[ind]=='/'){

    if(s[ind]=='*') ind++, x=x*pri2();

    else ind++, x/=pri2();

  }

  return x;

}



int pri2(){

  int x=0;

  if(s[ind]=='('){

     ind++;

     x=pri0();

     ind++;

  }

  else{

    while(s[ind]>='0'&&s[ind]<='9'){

      x=x*10+s[ind]-'0';

      ind++;

    }

  }

  return x;

}



int main()

{

    fin>>s;

    fout<<pri0();

    return 0;

}
