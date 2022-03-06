#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



string a, b, c;

int l1, l2;

vector<int> aparitii;

int pi[2000005];



int main() {

    a = b = " ";

    fin >> c;

    a += c;

    fin >> c;

    b += c;

    l1 = a.length()-1, l2 = b.length()-1;



    int k = 0;

    for(int i = 2; i <= l1; i++) {

        while(k > 0 && a[k+1] != a[i])

            k = pi[k];

        if(a[k+1] == a[i])

            k++;

        pi[i] = k;

    }



    int q = 0;

    for(int i = 1; i <= l2; i++) {

        while(q > 0 && (a[q+1] != b[i]))

            q = pi[q];

        if(a[q+1] == b[i])

            q++;

        if(q == l1)

            aparitii.push_back(i-l1);

    }



    fout << aparitii.size() << '\n';

    if(aparitii.size() > 1000)

        for(int i = 0; i < 1000; i++)

            fout << aparitii[i] << ' ';

    else

        for(auto nr: aparitii)

            fout << nr << ' ';

}
