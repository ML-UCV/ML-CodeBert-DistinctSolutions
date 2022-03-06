#include <iostream>
#include <fstream>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



long long inv = 0;



void interclasare(int s[], int st, int mij, int dr)

{

    int i,j,k,rasp = 0,nr = 0;

    int n1 = mij-st+1;

    int n2 = dr - mij;



    int S[n1],D[n2];



    for(i = 0; i<n1; i++)

    {

        S[i] = s[st+i];

    }

    for(i = 0; i<n2; i++)

    {

        D[i] = s[mij+1+i];

    }



    i = j = 0;

    k = st;



    while(i<n1 && j<n2)

    {

        if(S[i]<=D[j])

        {

            s[k] = S[i];

            i++;

            rasp = rasp + nr;

        }

        else

        {

            s[k] = D[j];

            j++;

            nr++;

        }

        k++;

    }



    while(i<n1)

    {

        s[k] = S[i];

        i++;

        k++;

        rasp = rasp +nr;



    }



    while(j<n2)

    {

        s[k] = D[j];

        j++;

        k++;

    }



    inv = inv + rasp;

    inv = inv % 9917;

}



void mergesort(int s[], int st, int dr)

{

    if(st<dr)

    {

        int mij = st + (dr - st) / 2;

        mergesort(s,st,mij);

        mergesort(s,mij+1,dr);

        interclasare(s,st,mij,dr);

    }

}



int main()

{



    int n,i;



    fin>>n;



    int s[100001];



    for(i=1; i<=n; i++)

    {

        fin>>s[i];

    }



    mergesort(s,1,n);



    fout<<inv;





    return 0;

}
