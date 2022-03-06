#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int MOD=1000000007;

const int baza=597813;



string n,m;

int nrN,nrM;

vector <int> ind;



void read()

{

    fin>>n>>m;

    nrN=n.length();

    nrM=m.length();

}



void solve()

{

    int_fast64_t hashN=0,hashM=0,baseNrN=1;



    for(int i=1;i<nrN;i++)

    {

        baseNrN*=baza;

        baseNrN%=MOD;

    }



    for(int i=0;i<nrN;i++)

    {

        hashN=hashN*baza+n[i];

        hashN%=MOD;

        hashM=hashM*baza+m[i];

        hashM%=MOD;

    }



    int ans=0;



    if(hashN==hashM)

    {

        ind.push_back(0);

        ++ans;

    }



    for(int i=nrN;i<nrM;i++)

    {

        hashM=hashM-m[i-nrN]*baseNrN;

        hashM%=MOD;

        hashM=hashM*baza+m[i];

        hashM%=MOD;



        if(hashM<0)

            hashM+=MOD;



        if(hashM==hashN)

        {

            ind.push_back(i-nrN+1);

            ++ans;

        }

    }



    fout<<ans<<"\n";



    int displayed=0;

    for(int i=0;i<ind.size();i++)

    {

        fout<<ind[i]<<" ";

        ++displayed;



        if(displayed==1000)

            break;

    }

}



int main()

{

    read();



    if(nrN>nrM)

    {

        fout<<0;

        return 0;

    }



    solve();



    return 0;

}
