#include <fstream>
#include <iostream>
#include <cstring>


using namespace std;







ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



long long n,a,x,tot,aa,d=2,k,i,sol=1,nr;



int main()

{

    ios_base::sync_with_stdio(false);

    fin >> a >> n;

    aa=n;

    tot=n;

    while(d*d<=aa)

    {

        if(aa%d==0)

        {

            while(aa%d==0)

                aa/=d;

            tot/=d;

            tot*=d-1;

        }

        d++;

    }

    if(aa>1)

        tot/=aa,

        tot*=aa-1;

    tot--;

    nr=a;

    for(long long p=1;p<=tot;p<<=1)

    {

   if(p&tot)sol=(sol*nr)%n;

    nr=(nr*nr)%n;

 }

 fout << sol;

    return 0;

}
