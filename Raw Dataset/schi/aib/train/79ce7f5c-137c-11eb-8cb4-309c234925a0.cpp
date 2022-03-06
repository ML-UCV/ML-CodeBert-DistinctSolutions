#include <iostream>
#include <fstream>
#include <stack>


using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



const int NMAX = 300001;



int N;

int tree[NMAX];

int C[NMAX];



stack <int> S;



void Update(int pos, int val)

{

    while( pos <= N )

    {

        tree[pos] += val;

        pos += (pos & -pos);

    }

}



int Query(int pos)

{

    int sum = 0;



    while( pos > 0 )

    {

        sum += tree[pos];

        pos -= (pos & - pos);

    }



    return sum;

}



int BinSearch(int lf, int rg, int val)

{

    if(lf > rg) return 2000000000;



    int mid = (lf + rg) / 2;



    int m = Query( mid );



    if(m < val) return BinSearch(mid + 1, rg, val);

    if(m == val) return min(mid, BinSearch(lf, mid - 1, val));

    if(m > val) return BinSearch(lf, mid - 1, val);

}

void Read()

{

    fin >> N;



    int x;

    for(int i = 1; i <= N; ++i)

        {

            fin >> x;

            S.push(x);

            Update(i, 1);

        }

    int y = N;

    while(!S.empty())

    {

        x = S.top();

        S.pop();

        int pos = BinSearch(1, N, x);

        C[pos] = y;

        Update(pos, -1);

        y--;

    }



    for(int i = 1; i <= N; ++i)

        fout << C[i] << '\n';

}

int main()

{

    Read();

    return 0;

}
