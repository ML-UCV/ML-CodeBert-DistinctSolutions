#include <iostream>
#include <fstream>
using namespace std;



int v[100001], c[100001];

int n;

long long inv;



void interclasare(int st,int mij,int dr)

{

    int k=1,i=st,j=mij+1;

    while(i<=mij&&j<=dr)

      if(v[i]<=v[j])

        c[k++]=v[i++];

        else

        {

            inv += mij - i + 1 ;

            c[k++]=v[j++];



        }

    while(i<=mij)

        c[k++]=v[i++];

    while(j<=dr)

        c[k++]=v[j++];

    k--;

    for(i=1;i<=k;i++)

        v[st+i-1]=c[i];



}



void divide(int st,int dr)

{

    if(st<dr)

    {

        divide(st,(st+dr)/2);

        divide((st+dr)/2+1,dr);

        interclasare(st,(st+dr)/2,dr);

    }

}



int main()

{

    ifstream fin("inv.in");

    ofstream fout("inv.out");



    int i;

    fin>>n;

    for(i=1;i<=n;i++)

        fin>>v[i];



   divide(1,n);



   fout << inv % 9917;



    fin.close();

    fout.close();

    return 0;

}
