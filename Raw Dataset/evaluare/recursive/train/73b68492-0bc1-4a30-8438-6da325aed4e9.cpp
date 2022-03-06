#include<bits/stdc++.h>
typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;



const int nmax=1e5+19;

const int mod=6669666;



using namespace std;



string s;

int i;



int baga1();

int baga2();

int baga3();



int baga3()



{

  int x=0;

  if(s[i]=='(')

  {

    i++;

    x=baga1();

    i++;

  } else

  {

    while(s[i]>='0' && s[i]<='9') x=x*10+(s[i++]-48);

  }



  return x;

}



int baga2()

{

  int x=baga3();

  while(s[i]=='*' || s[i]=='/')

  {

    i++;

    if(s[i-1]=='*') x*=baga3();

    if(s[i-1]=='/') x/=baga3();

  }



  return x;

}



int baga1()

{

  int x=baga2();

  while(s[i]=='+' || s[i]=='-')

  {

    i++;

    if(s[i-1]=='+') x+=baga2();

    if(s[i-1]=='-') x-=baga2();

  }



  return x;

}



int main()

{

  ios_base::sync_with_stdio(0); cin.tie();

  freopen("evaluare.in","r",stdin);

  freopen("evaluare.out","w",stdout);

  cin>>s;

  cout<<baga1();

}
