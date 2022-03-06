#include <fstream>
#include <iostream>
const int MOD = 9917;



using namespace std;



void merge_sort(int *v, int stg, int dr, int &sol) {

    if (stg < dr) {

        int mid = (stg + dr) / 2;

        merge_sort(v, stg, mid, sol);

        merge_sort(v, mid + 1, dr, sol);

        int stg_index = stg;

        int dr_index = mid + 1;

        int *aux = new int[dr - stg + 1];

        int aux_index = 0;

        while (stg_index <= mid && dr_index <= dr) {

            if (v[stg_index] <= v[dr_index]) {

                aux[aux_index++] = v[stg_index];

                stg_index++;

            } else {

                sol += mid - stg_index + 1;

                sol %= MOD;

                aux[aux_index++] = v[dr_index];

                dr_index++;

            }

        }

        while (stg_index <= mid) {

            aux[aux_index++] = v[stg_index];

            stg_index++;

        }

        while (dr_index <= dr) {

            aux[aux_index++] = v[dr_index];

            dr_index++;

        }

        for (int i = stg; i <= dr; ++i) {

            v[i] = aux[i - stg];

        }







        delete[] aux;

    }

}



int main() {

    int n;

    ifstream fin("inv.in");

    ofstream fout("inv.out");

    fin >> n;

    int *v = new int[n];

    for (int i = 0; i < n; ++i) {

        fin >> v[i];

    }

    int sol = 0;

    merge_sort(v, 0, n - 1, sol);

    fout << sol;



    return 0;

}
