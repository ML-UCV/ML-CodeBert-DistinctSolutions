#include <fstream>
using namespace std;

ifstream in("evaluare.in");

ofstream out("evaluare.out");

char a[100001];

int x;

int expresie();

int termen();

int evaluare();

int main()

{ in>>a;

  out<<expresie();

  in.close();

  out.close();

  return 0;

}

int expresie()

{ int r=termen();

  while(a[x]=='+' || a[x]=='-' || a[x]=='/' || a[x]=='*')

  { x++;

    if(a[x-1]=='+')

       r=r+evaluare();

    else if(a[x-1]=='-')

       r=r-evaluare();

    else if(a[x-1]=='*')

       r=r*termen();

    else if(a[x-1]=='/')

       r=r/termen();

  }

  return r;

}

int evaluare()

{ int r=termen();

  while(a[x]=='*' || a[x]=='/')

  { x++;

    if(a[x-1]=='*')

       r=r*termen();

    else if(a[x-1]=='/')

       r=r/termen();

  }

  return r;

}

int termen()

{ int k=0;

  if(a[x]=='(')

  { x++;

    k=expresie();

    x++;

  }

  else

  { while(a[x]>='0' && a[x]<='9')

      k=k*10+a[x]-'0',x++;

  }

  return k;

}
