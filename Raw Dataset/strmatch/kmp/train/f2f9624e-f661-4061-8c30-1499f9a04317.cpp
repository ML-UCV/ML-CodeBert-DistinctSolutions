#include <bits/stdc++.h>




using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



char A[2000002], B[2000002];

int lps[2000002],cnt;



vector<int>rasp;



int main()

{

    in.getline(A,2000002);

    in.getline(B,2000002);

    int n=strlen(A), m=strlen(B);

    if(n>m)

    {

        out<<'0';

        return 0;

    }

    lps[0]=0;

    int l=0;

    for(int i=1;i<n;i++)

    {

        if(A[l]==A[i])

            lps[i]=++l;

        else

        {

            if(l==0)

                lps[i]=0;

            else

            {

                l=lps[l-1];

                i--;

            }

        }

    }

    int i=0,j=0;

    while(i<m)

    {

        if(A[j]==B[i])

        {

            i++;

            j++;

        }

        else

        {

            if(j==n)

            {

                cnt++;

                if(cnt<=1000)

                    rasp.push_back(i-n);

            }

            if(j==0)

                i++;

            else

                j=lps[j-1];

        }

    }

    if(j==n)

    {

        cnt++;

        if(cnt<=1000)

            rasp.push_back(i-n);

    }

    out<<cnt<<'\n';

    for(int i=0;i<1000 && i<cnt;i++)

        out<<rasp[i]<<' ';

    return 0;

}
