#include<bits/stdc++.h>
using namespace std;

int main()

{

ifstream f("cmmdc.in");

ofstream g("cmmdc.out");

int a,b;

f>>a>>b;

while(b!=0)

{

int r=a%b;

a=b;

b=r;

}

if(a==1)

g<<0;

else

g<<a;

return 0;

}
