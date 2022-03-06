#include <iostream>
#include<fstream>
using namespace std;

int a,b;

ifstream in("cmmdc.in");

ofstream out("cmmdc.out");

int main()

{ in>>a>>b;

    while(a!=b) if(a>b)

               a=a-b;

              else

                b=b-a;

              if(a==1)

                out<<0;

              else

                out<<a;

    return 0;

}
