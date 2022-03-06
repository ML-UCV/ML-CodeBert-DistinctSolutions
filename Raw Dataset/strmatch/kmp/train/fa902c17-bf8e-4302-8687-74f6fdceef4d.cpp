#include <bits/stdc++.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



char A[2000002], B[2000002];

char C[2000002 +2000002];

int Z[2000002 +2000002],cnt;



int main()

{

    in.getline(A,2000002);

    in.getline(B,2000002);

    int n=strlen(A),m=strlen(B);

    if(n>m)

    {

        out<<"0";

        return 0;

    }

    strcpy(C,A);

    strcat(C,"+");

    strcat(C,B);

    int L=0,R=0;

    for(int i=1;i<n+m+1;i++)

    {

        if(i>R)

        {

            L=i;

            R=i;

            while(R<n+m+1 && C[R]==C[R-i])

                R++;

            R--;

            Z[i]=R-L+1;

        }

        else

        {

            int k=i-L;

            if(R-i+1>Z[k])

                Z[i]=Z[k];

            else

            {

                L=i;

                while(R<n+m+1 && C[R]==C[R-i])

                    R++;

                R--;

                Z[i]=R-L+1;

            }

        }

        if(Z[i]==n)

            cnt++;

    }

    out<<cnt<<'\n';

    int ok=1;

    for(int i=n+1;i<n+m+1 && ok<=1000;i++)

        if(Z[i]==n){

            out<<i-n-1<<' ';

            ok++;

        }

    return 0;

}
