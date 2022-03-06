#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

string a,c;

unsigned int z[3000001];

int rez[2000001],cont,l,lef,righ;

void Z()

{

    int n=c.size();

    for(int i=1; i<n; i++)

    {

        if(i>righ)

        {

            while(z[i]+i<n and c[z[i]+i]==c[z[i]])

                ++z[i];

            lef=i;

            righ=i+z[i]-1;

        }

        else

        {

            if(i+z[i-lef]-1<righ)

               z[i]=z[i-lef];

            else

            {

                z[i]=righ-i+1;

                while(z[i]+i<n and c[z[i]+i]==c[z[i]])

                ++z[i];

                lef=i;

                righ=i+z[i]-1;

            }

        }

        if(z[i]==l)

        {

            ++cont;

            if(cont<=1000)

                rez[cont]=i-l-1;

        }

    }

}

int main()

{

    ifstream cin ("strmatch.in");

    ofstream cout ("strmatch.out");

    getline(cin,a);

    c=a;

    l=a.size();

    c.push_back('$');

    cin>>a;

    c+=a;

    Z();

    cout<<cont<<"\n";

    for(int i=1; i<=cont and i<=1000; i++)

        cout<<rez[i]<<" ";

    return 0;

}
