#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



string a, b;

int pi[2000005];

vector<int> aparitii;



int main() {

    fin >> a >> b;

    int l1 = a.length(), l2 = b.length();

    int k = -1;

    pi[0] = -1;

    for(int i = 1; i < l1; i++) {

        while(k != -1 && a[k+1] != a[i])

            k = pi[k];

        if(a[k+1] == a[i])

            k++;

        pi[i] = k;

    }



    k = -1;

    for(int i = 0; i < l2; i++) {

        while(k != -1 && a[k+1] != b[i])

            k = pi[k];

        if(a[k+1] == b[i])

            k++;

        if(k == l1-1)

            aparitii.push_back(i-k);

    }



    fout << aparitii.size() << '\n';

    for(int i = 0; i < min(int(aparitii.size()), 1000); i++)

        fout << aparitii[i] << ' ';

}
