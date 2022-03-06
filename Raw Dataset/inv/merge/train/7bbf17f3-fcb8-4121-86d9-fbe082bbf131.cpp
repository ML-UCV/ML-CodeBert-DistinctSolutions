#include <iostream>
#include <fstream>


using namespace std;



int nr ;

const int N = 100005;

const int M = 9917;



void interclasare (int s[], int st, int m, int dr)

{

    int i,l, j, k = 0,aux[N];
    i = st;

    j = m+1;

    while ( i <= m && j <= dr)

    {

        if ( s[i] <= s[j])

            aux[k++] = s[i++];

        else

        {

            aux[k++] = s[j++];

            nr += m-i+1;

            nr = nr%M;

        }

    }

    while (i <= m)

        aux[k++] = s[i++];

    while ( j <= dr)

        aux[k++] = s[j++];

    for (i = st,k = 0; i <= dr ; i++,k++)

        s[i] = aux[k];

}



void MergeSort (int s[], int st, int dr)

{

    if ( st < dr)

    {

        int m = (st + dr) / 2;

        MergeSort (s, st, m);

        MergeSort (s, m+1, dr);

        interclasare (s, st, m, dr);

    }

}



int main()

{

    int n, s[N], i, j;



    ifstream in ("inv.in");

    in >> n;



    for (i = 0; i < n; i++)

        in >> s[i];

    in.close();



    MergeSort (s, 0, n-1);



    ofstream out("inv.out");

    out << nr%M;

    out.close();



    return 0;

}
