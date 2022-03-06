#include <fstream>


using namespace std;



int main()

{

    ifstream cin("cmmdc.in");

    ofstream cout("cmmdc.out");

    int a,b,rest;

    cin>>a>>b;

    while(b>0)

    {

        rest=a%b;

        a=b;

        b=rest;

    }

    if(a==1)

    {

        cout<<"0";

    }

    else

    {

        cout<<a;

    }

    return 0;

}
