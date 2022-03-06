#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

ifstream in ("strmatch.in");

ofstream out("strmatch.out");

char a[2000003], b[2000003];

int lps[2000003], sizeb;

vector <int> found;

void calclps()

{

    lps[0]=0;

    int poz1=0;

    for(int i=1; b[i]!='\0'; i++)

    {

        while(b[poz1]!=b[i]&&poz1!=0) poz1=lps[poz1-1];

        if(b[poz1]==b[i]) poz1++;

        lps[i]=poz1;

    }





}

int main()

{

    in.getline(b, 2000000001);

    in.getline(a, 2000000001);

    sizeb=strlen(b);

    calclps();

    int poz1=0;

    for(int i=0; a[i]!='\0';i++)

    {

        while(b[poz1]!=a[i]&&poz1!=0) poz1=lps[poz1-1];

        if(b[poz1]==a[i]) poz1++;

        if(poz1==sizeb) found.push_back(i-sizeb+1) ;

    }

    out<<(int)found.size()<<"\n";

    for(int i=0; i<min(1000, (int)found.size()); i++)

        out<<found[i]<<" ";

    return 0;

}
