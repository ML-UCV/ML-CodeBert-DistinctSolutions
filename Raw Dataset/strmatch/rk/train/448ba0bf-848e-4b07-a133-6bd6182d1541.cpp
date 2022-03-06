#include <bits/stdc++.h>




using namespace std;







const long long p1=999727999, b1=137;

const long long p2=999686999, b2=139;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



char A[5+2000000], B[5+2000000];



vector<int>rasp;



int main()

{

    int n,m;

    in.getline(A,2000000 +2);

    in.getline(B,2000000 +2);

    n=strlen(A);

    m=strlen(B);

    if(n>m)

    {

        out<<"0";

        return 0;

    }

    long long exp1=1,exp2=1,hash1B=0,hash2B=0,hash1A=0,hash2A=0,cnt=0;

    for(int i=0;i<n;i++)

    {

        hash1A=((hash1A*b1)%p1+(A[i]-'0'))%p1;

        hash2A=((hash2A*b2)%p2+(A[i]-'0'))%p2;

        hash1B=((hash1B*b1)%p1+(B[i]-'0'))%p1;

        hash2B=((hash2B*b2)%p2+(B[i]-'0'))%p2;

        if(i!=0)

        {

            exp1=(exp1*b1)%p1;

            exp2=(exp2*b2)%p2;

        }

    }





    if(hash1A==hash1B && hash2A==hash2B)

    {

        cnt++;

        rasp.push_back(0);

    }

    for(int i=1; i<m-n+1; i++)

    {

        hash1B=(hash1B-((B[i-1]-'0')*exp1)%p1+p1)%p1;

        hash2B=(hash2B-((B[i-1]-'0')*exp2)%p2+p2)%p2;

        hash1B=(hash1B*b1)%p1;

        hash2B=(hash2B*b2)%p2;

        hash1B=(hash1B+(B[i+n-1]-'0'))%p1;

        hash2B=(hash2B+(B[i+n-1]-'0'))%p2;

        if(hash1A==hash1B && hash2A==hash2B)

        {

            cnt++;

            if(rasp.size()<1000)

                rasp.push_back(i);

        }

    }

    out<<cnt<<'\n';

    for(int i=0; i<1000 && i<rasp.size();i++)

        out<<rasp[i]<<' ';

    return 0;

}
