#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int P = 62;

const int NMAX = 2e6 + 7;

const int m1 = 1e5 + 7;

const int m2 = 1e5 + 21;



int N,M,P1,P2,hashA1,hashA2,hash1,hash2;

vector <int> a;

char A[NMAX],B[NMAX];



int main()

{



    fin >> A >> B;

    N=strlen(A), M=strlen(B);



    P1=1, P2=1;

    for(int i=0;i<N;i++)

    {

        hashA1=(hashA1*P+A[i])%m1;

        hashA2=(hashA2*P+A[i])%m2;

        hash1=(hash1*P+B[i])%m1;

        hash2=(hash2*P+B[i])%m2;

        if(i!=0)

            P1=(P1*P)%m1,

            P2=(P2*P)%m2;

    }



    if(hashA1==hash1 and hashA2==hash2)

        a.push_back(0);



    for(int i=N;i<M;i++)

    {

        hash1=((hash1-(P1*B[i-N])%m1+m1)*P+B[i])%m1;

        hash2=((hash2-(P2*B[i-N])%m2+m2)*P+B[i])%m2;

        if(hash1==hashA1 and hash2==hashA2)

            a.push_back(i-N+1);

    }



    fout << a.size() << "\n";



    for(int i=0;i<a.size();i++)

    {

        if(i==1000)

            break;

        fout << a[i] << " ";

    }



    return 0;



}
