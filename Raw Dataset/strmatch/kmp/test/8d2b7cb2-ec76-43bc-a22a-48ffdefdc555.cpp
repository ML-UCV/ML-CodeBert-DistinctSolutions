#include <bits/stdc++.h>






using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



queue<int> answers;

int nr=0;

const int maxSize=2000005;



char A[maxSize],B[maxSize];



void read()

{

    fin>>A>>B;

}



void LPSarray(char* pat,int M,int* lps)

{

    int len=0,i=1;



    lps[0]=0;



    while(i<M)

    {

        if(pat[i]==pat[len])

        {

            len++;

            lps[i]=len;

        }

        else

        {

            if(len!=0)

            {

                len=lps[len-1];

                i--;

            }

            else

            {

                lps[i]=0;

            }

        }

        i++;

    }

}



void KMP(char* pat,char* txt)

{

    int M=strlen(pat);

    int N=strlen(txt);



    int lps[M];



    LPSarray(pat,M,lps);



    int i=0,j=0;



    while(i<N)

    {

        if(pat[j]==txt[i])

        {

            i++;

            j++;

        }

        if(j==M)

        {

            nr++;

            answers.push(i-j);

            j=lps[j-1];

        }

        else if(i<N && pat[j]!=txt[i])

        {

            if(j!=0)

                j=lps[j-1];

            else

                i++;

        }

    }

}



void print()

{

    int n=1000;

    fout<<nr<<"\n";

    while(!answers.empty() && n>0)

    {

        fout<<answers.front()<<" ";

        answers.pop();

        n--;

    }

}



int main()

{

    read();

    KMP(A,B);

    print();

    return 0;

}
