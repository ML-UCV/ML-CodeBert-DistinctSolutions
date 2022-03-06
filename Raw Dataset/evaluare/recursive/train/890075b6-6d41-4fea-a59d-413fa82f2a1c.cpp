#include <cstdio>
#include <cstring>

using namespace std;

const int LMAX = 2;
char op[4][4]={"+-","*/","^",""};

const int NMAX = 100005;

char s[NMAX];
char *p=s;

int eval(int a,int b, char sign){
 if(sign=='+')
  return a+b;
 if(sign=='-')
  return a-b;
 if(sign=='*')
  return a*b;
 if(sign=='/')
  return a/b;
}


int expr(int lvl){
 int x;
 if(lvl==LMAX)
  if(*p=='('){
   ++p;
   x=expr(0);
   ++p;
   return x;
  }else{
   for(x=0;*p>='0' && *p<='9';++p)
    x=x*10+*p-'0';
   return x;
  }
 else{
  int y=0;
  for(x=expr(lvl+1);strchr(op[lvl],*p);x=y)
   y=eval(x,expr(lvl+1),*p++);

  return x;
 }
}

int main(){
 freopen("evaluare.in","r",stdin);
 freopen("evaluare.out","w",stdout);
 scanf("%s",s);

 int n=strlen(s);
 s[n]=1;

 printf("%d\n",expr(0));
}
