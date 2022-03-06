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

        while(k > -1 && a[i] != a[k+1])

            k = pi[k];

        if(a[i] == a[k+1]) k++;

        pi[i] = k;

    }

    k = -1;

    for(int i = 0; i < l2; i++) {

        while(k > -1 && b[i] != a[k+1])

            k = pi[k];

        if(b[i] == a[k+1]) k++;

        if(k == l1-1)

            aparitii.push_back(i-l1+1);

    }

    fout << aparitii.size() << '\n';

    int z = min(1000, int(aparitii.size()));

    for(int i = 0; i < z; i++)

        fout << aparitii[i] << ' ';

}
