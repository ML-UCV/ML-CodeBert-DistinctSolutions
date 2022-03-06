#include <fstream>






using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



int n, v[100005];



int Merge(int st, int dr)

{

    int nrInv = 0;

    int mij = (st+dr)/2, i = st, j = mij+1, k = 0;

    int aux[dr-st+1];

    while(i <= mij && j <= dr)

        if(v[i] <= v[j]) aux[k++] = v[i++];

        else

        {

            aux[k++] = v[j++];

            nrInv += (mij-i+1);

            nrInv %= 9917;

        }

    while(i <= mij) aux[k++] = v[i++];

    while(j <= dr) aux[k++] = v[j++];

    for(int i = 0; i < k; ++i) v[st+i] = aux[i];

    return nrInv;

}



int countInv(int st, int dr)

{

    int nrInv = 0;

    if(st < dr)

    {

        nrInv += countInv(st, (st+dr)/2);

        nrInv += countInv((st+dr)/2 + 1, dr);

        nrInv += Merge(st, dr);

        nrInv %= 9917;

    }

    return nrInv;

}



int main()

{

    fin >> n;

    for(int i = 1; i <= n; ++i) fin >> v[i];

    fin.close();

    fout << countInv(1, n);

    fout.close();

    return 0;

}
