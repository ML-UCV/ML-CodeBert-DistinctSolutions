#include <fstream>
#include <vector>
#include <string>


using namespace std;







ifstream cin("strmatch.in");

ofstream cout("strmatch.out");



int n,m,p[20000005],i,q,db;

vector<int>megold;

string A,B;



void prefix()

{

    int i=0,q=0;

    p[1]=0;



    for(i=2;i<A.length();++i)

    {

        while(q>0 && A[q+1]!=A[i])

            q=p[q];



        if(A[q+1]==A[i]) ++q;

        p[i]=q;

    }

}



int main()

{

    cin>>A>>B;

    A=" "+A;

    B=" "+B;



    prefix();



    for(i=1;i<B.length();++i)

    {

        while(q && A[q+1]!=B[i])

            q=p[q];

        if(A[q+1]==B[i]) ++q;

        if(q==A.length()-1)

        {

            ++db;

            if(db<=1000) megold.push_back(i-A.length()+1);

            q=p[q];

        }

    }



    cout<<db<<"\n";

    for(auto e : megold) cout<<e<<" ";



    return 0;

}
