#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

char A[2000001 +10], B[2000001 +10];

int nA,nB,P1,P2,hashA1,hashA2,hashB1,hashB2, pM1,pM2;

vector <int> match;

int main()

{

    cin.getline(A,2000001);

    cin.getline(B,2000001);

    nA=strlen(A);

    nB=strlen(B);

    if(nA>nB){

        cout<<0<<'\n';

        return 0;

    }



    P1=P2=1;

    for(int i=0; i<nA; ++i)

    {

        hashA1=(hashA1*73 +A[i])%100007;

        hashA2=(hashA2*73 +A[i])%100021;



        hashB1=(hashB1*73 +B[i])%100007;

        hashB2=(hashB2*73 +B[i])%100021;



        if(i>0)

        {

            P1=(P1*73)%100007;

            P2=(P2*73)%100021;

        }

    }

    if(hashA1==hashB1 && hashA2==hashB2)

        match.push_back(0);

    for(int i=nA; i<nB; ++i)

    {

        hashB1=((hashB1+100007 -(P1*B[i-nA])%100007)*73 +B[i])%100007;

        hashB2=((hashB2+100021 -(P2*B[i-nA])%100021)*73 +B[i])%100021;

        if(hashA1==hashB1 && hashB2==hashA2)

            match.push_back(i-nA+1);

    }







    cout<<match.size()<<'\n';

    int dim=match.size();

    for(int i=0; i<min(dim,1000); ++i)

        cout<<match[i]<<' ';

    return 0;

}
