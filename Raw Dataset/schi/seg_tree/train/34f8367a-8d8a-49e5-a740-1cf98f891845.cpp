#include <fstream>






using namespace std;



ifstream fin ("schi.in");

ofstream fout("schi.out");



int v[30005], sol[30005], heap[3*30005];

int x, pos;



inline void actualizare(int nod, int st, int dr)

{

    int mij;

    if(st == dr)

        heap[nod] = x;

    else

    {

        mij = (st+dr) / 2;

        if(st <= pos && pos <= mij) actualizare(nod*2, st, mij);

        if(mij+1 <= pos && pos <= dr) actualizare(nod*2+1, mij+1, dr);

        heap[nod] = heap[nod*2] + heap[nod*2+1];

    }

}



inline int DEI(int nod, int st, int dr, int val)

{

    if(st == dr) return st;

    int mij = (st+dr) / 2;

    if(heap[nod*2] < val) return DEI(nod*2 + 1, mij+1, dr, val - heap[nod*2]);

    else return DEI(nod*2, st, mij, val);

}



int main()

{

    int n;

    fin >> n;

    for(int i = 1; i <= n; ++i) fin >> v[i];

    fin.close();



    x = 1;

    for(int i = 1; i <= n; ++i)

    {

        pos = i;

        actualizare(1, 1, n);

    }

    for(int i = n; i; --i)

    {

        pos = DEI(1, 1, n, v[i]);

        sol[pos] = i;

        x = 0;

        actualizare(1, 1, n);

    }



    for(int i = 1; i <= n; ++i) fout << sol[i] << '\n';

    fout.close();

    return 0;

}
