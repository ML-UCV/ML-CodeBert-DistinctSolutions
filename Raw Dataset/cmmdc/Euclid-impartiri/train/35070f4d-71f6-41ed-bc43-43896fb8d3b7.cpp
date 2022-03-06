#include <fstream>


using namespace std;

ifstream cin("cmmdc.in");

ofstream cout("cmmdc.out");

int a, b;

int main()

{

    cin>>a>>b;

    if(b==0)

    {

        cout<<"0";

    }

    int r=a%b;

    while(r)

    {

        a=b;

        b=r;

        r=a%b;

    }

    if(b==1)

    {

        cout<<"0";

    }

    else

    {

        cout<<b;

    }

    return 0;

}
