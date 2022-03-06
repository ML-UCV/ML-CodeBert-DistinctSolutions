#include <fstream>
#include <iostream>
#include <vector>




using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char A[2000001], B[2000001];

int t[2000001];



void init() {

    t[0] = 0;

    int i = 1, j = 0;

    while (A[i] != '\0') {

        if (A[i] == A[j]) {

            t[i] = j + 1;

            ++i, ++j;

        }

        else {

            if (j == 0)

                t[i] = 0, ++i;

            else j = t[j - 1];

        }

    }

}



void KMP() {

    int nr = 0;

    int i = 0, j = 0;

    vector<int> vec;

    while (B[j] != '\0') {

        if (A[i] == B[j]) {

            ++i, ++j;

            if (A[i] == '\0') { ++nr; if(nr<=1000) vec.push_back(j - i); i = t[i - 1]; }

        }

        else

            if (i == 0)

                ++j;

            else i = t[i - 1];

    }

    fout << nr << '\n';

    for (int x : vec)

        fout << x << ' ';

}



int main()

{

    fin >> A >> B;

    init();

    KMP();



    return 0;

}
