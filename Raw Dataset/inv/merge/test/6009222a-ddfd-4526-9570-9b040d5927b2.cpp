#include <fstream>


const int MOD = 9917;



using namespace std;



int Merge(int* v, int* aux, int left, int middle, int right)

{

    int index = left;

    int i1 = left;

    int i2 = middle + 1;



    int r = 0;

    while (i1 <= middle && i2 <= right)

    {

        if (v[i1] <= v[i2])

            aux[index++] = v[i1++];

        else

        {

            aux[index++] = v[i2++];

            r += middle - i1 + 1;

            r %= MOD;

        }

    }



    while (i1 <= middle)

        aux[index++] = v[i1++];



    while (i2 <= right)

        aux[index++] = v[i2++];



    for (int i = left; i <= right; i++)

        v[i] = aux[i];



    return r;

}



int MergeSort(int* v, int* aux, int left, int right)

{

    if (left >= right)

        return 0;



    int result = 0;

    int middle = (left + right) / 2;



    result += MergeSort(v, aux, left, middle);

    result %= MOD;

    result += MergeSort(v, aux, middle + 1, right);

    result %= MOD;

    result += Merge(v, aux, left, middle, right);

    result %= MOD;



    return result;

}



int main()

{

    int n;

    int* v;

    int* aux;

    ifstream fin("inv.in");

    fin >> n;



    v = new int[n];

    aux = new int[n];



    for (int i = 0; i < n; i++)

        fin >> v[i];

    fin.close();



    ofstream fout("inv.out");

    fout << MergeSort(v, aux, 0, n - 1);

    fout.close();



    delete[] aux;

    aux = NULL;

    delete[] v;

    v = NULL;



    return 0;

}
