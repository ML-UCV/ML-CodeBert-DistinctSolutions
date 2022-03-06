#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <climits>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



const int NMAX = 100000;



struct pct

{

    long long x, y;

};



int N;

pct v[NMAX + 5], aux[NMAX + 5];

long long DMIN = LLONG_MAX;



inline bool cmp(pct A, pct B)

{

    if(A.x == B.x)

        return A.y < B.y;



    return A.x < B.x;

}



long long GetDist(pct A, pct B)

{

    return 1LL * (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);

}



void Merge(int l1, int r1, int l2, int r2)

{

    int k = 0;



    while(l1 <= r1 && l2 <= r2)

    {

        k++;



        if(v[l1].y < v[l2].y)

        {

            aux[k] = v[l1];

            l1++;

        }

        else

        {

            aux[k] = v[l2];

            l2++;

        }

    }



    while(l1 <= r1)

    {

        aux[++k] = v[l1];

        l1++;

    }



    while(l2 <= r2)

    {

        aux[++k] = v[l2];

        l2++;

    }



    for(int i = r2; k > 0; k--, i--)

        v[i] = aux[k];

}



void DivideAndConquer(int l, int r)

{

    if(l >= r)

        return ;



    int mid = (l + r) >> 1;

    int d = v[mid].x;



    DivideAndConquer(l, mid);

    DivideAndConquer(mid + 1, r);



    Merge(l, mid, mid + 1, r);



    int k = 0;



    for(int i = l; i <= r; i++)

        if(1LL * (v[i].x - d) * (v[i].x - d) < DMIN)

            aux[++k] = v[i];



    for(int i = 1; i < k; i++)

        for(int j = i + 1; j <= i + 8 && j <= k; j++)

            DMIN = min(DMIN, GetDist(aux[i], aux[j]));

}



int main()

{

    fin >> N;



    for(int i = 1; i <= N; i++)

        fin >> v[i].x >> v[i].y;



    sort(v + 1, v + N + 1, cmp);



    DivideAndConquer(1, N);



    fout << fixed << setprecision(12) << sqrtl(DMIN) << '\n';



    return 0;

}
