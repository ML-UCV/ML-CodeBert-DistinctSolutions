#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



string a, b;

vector <int> fin;

int aux[2000001];

int nrpos;



void pref()

{

    int q=0;

    for(int i=2; i<=a.size(); i++)

    {

        while(q && a[q+1]!=a[i]) q=aux[q];

        if(a[q+1]==a[i]) ++q;

        aux[i]=q;

    }

}



int main()

{

    getline(in, a);

    getline(in, b);

    a+=' ', b+=' ';

    for(int i=a.size()-1; i; i--) a[i]=a[i-1];

    for(int i=b.size()-1; i; i--) b[i]=b[i-1];

    a[0]=' ', b[0]=' ';

    pref();

    int q=0;

    for(int i=1; i<b.size(); i++)

    {

        while(q && a[q+1]!=b[i]) q=aux[q];

        if(a[q+1]==b[i]) ++q;

        if(q==a.size()-1)

        {

            fin.push_back(i-q);

            q=aux[q];

        }

    }

    out<<fin.size()<<'\n';

    for(int i=0; i<fin.size() && i<1000; i++) out<<fin[i]<<' ';

    return 0;

}
