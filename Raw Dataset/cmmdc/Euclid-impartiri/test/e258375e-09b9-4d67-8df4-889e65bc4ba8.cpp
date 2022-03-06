#include <iostream>
#include<fstream>
using namespace std;

int euclid(int x,int y)

{

    if(y==0)

     return x;

    else

        return euclid(y,x%y);



}

ifstream fin("cmmdc.in");

ofstream fout("cmmdc.out");

int main()

{

 int a,b,c;

 fin>>a>>b;

 c=euclid(a,b);

 if(c!=1)

 fout<<c;

 else

 fout<<'0';

}
