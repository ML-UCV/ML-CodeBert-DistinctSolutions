#include<bits/stdc++.h>
using namespace std;



ifstream f("cmmdc.in");

ofstream g("cmmdc.out");





int cmmdc(int a,int b){

if (b==0) return a;

return cmmdc(b,a%b);

}



int main()

{int a,b;

f>>a>>b;

if(cmmdc(a,b)==1) g<<0;

else g<<cmmdc(a,b);

}
