#include "bits/stdc++.h"
using namespace std;



int main()

{

    ifstream cin("cmmdc.in");

    ofstream cout("cmmdc.out");

    int a, b;

    cin>>a>>b;

    while(a!=0 && b!=0)

    {

        if(a>b)

        {

            a%=b;

        }

        else b%=a;

    }

    if (a+b==1)

    {

        cout <<0;

    }

    else cout<<a+b;

    return 0;

}
