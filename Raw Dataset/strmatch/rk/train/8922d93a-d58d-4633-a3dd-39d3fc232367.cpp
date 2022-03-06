#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string a,b;

unsigned int baz=71;

unsigned int ha[2000001],puteri[2000001],hasha;

int rez[2000001],cont;

int main()

{

    ifstream cin("strmatch.in");

    ofstream cout("strmatch.out");

    getline(cin,a);

    getline(cin,b);

    for(int i=a.size()-1; i>=0; --i)

        hasha=(hasha*baz+a[i]);

    for(int i=b.size()-1; i>=0; --i)

        ha[i]=(ha[i+1]*baz+b[i]);

    puteri[0]=1;

    for(int i=1; i<=b.size(); ++i)

        puteri[i]=(puteri[i-1]*baz);

    for(int i=a.size()-1; i<b.size(); ++i)

            if(hasha == ha[i-a.size()+1]-(ha[i+1]*puteri[a.size()]))

        {

                rez[cont]=i-a.size()+1;

                ++cont;

        }

    cout<<cont<<"\n";

    for(int i=0; i<cont and i<1000; i++)

        cout<<rez[i]<<" ";

    return 0;

}
