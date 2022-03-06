#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const long long A = 1763922631;

const long long B = 1617924853;

const long long C = 666013;



vector<int>sol;



int main()

{

    long long rasp = 0, put, x, y;

    string a, b;

    fin >> a >> b;

    if (a.size() > b.size())

    {

        fout << 0;

        return 0;

    }



    long long n = a.size(), i, j, m = b.size();

    long long valb = 0, vala = 0;

    long long val1a = 0, val1b = 0;

    put = 1;

    long long put1 = 1;



    for (i = 0; i < n; ++i)

    {

        vala = (vala * A + a[i]) % B;

        val1a = (val1a * A + a[i]) % C;

        put = (put * A) % B;

        put1 = (put1 * A) % C;

    }

    for (i = 0; i < n; ++i) {

        valb = (valb * A + b[i]) % B;

        val1b = (val1b * A + b[i]) % C;

    }



    if (vala == valb && val1a == val1b)

        ++rasp, sol.push_back(0);



    for (i = 1; i <= m - n; ++i)

    {

        valb = (valb * A + b[i + n - 1]) % B;

        val1b = (val1b * A + b[i + n - 1]) % C;

        x = put * b[i - 1];

        y = put1 * b[i - 1];

        valb = (((valb - x) % B) + B) % B;

        val1b = (((val1b - y) % C) + C) % C;

        if (vala == valb && val1a == val1b)

        {

            ++rasp;

            sol.push_back(i);

        }

    }



    fout << rasp << endl;

    for (int i = 0; i < min((int)sol.size(), 1000); i++)

        fout << sol[i] << " ";

    fout << "\n";



    return 0;

}
