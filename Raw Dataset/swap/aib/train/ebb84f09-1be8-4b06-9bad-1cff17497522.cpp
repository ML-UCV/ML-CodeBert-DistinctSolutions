#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");



using VI = vector<int>;

using VVI = vector<VI>;

using VB = vector<bool>;



const int NrLit = 26;



int N;

string a, b;

VI p[NrLit];

VI aib;



void Read();

void Solve();

void Update(int pos, int val);

int Query(int pos);



int main()

{

    Read();

    Solve();



    fin.close();

    fout.close();

    return 0;

}



void Read()

{

    fin >> a >> b;

    N = (int)a.size();



}



void Solve()

{

    for (int i = N - 1; i >= 0; --i)

        p[a[i] - 'a'].push_back(i);



    aib = VI(N + 1);



    int ans{0};

    for (int i = 0; i < N; ++i)

    {

        if (p[b[i] - 'a'].empty())

        {

            fout << "-1\n";

            return;

        }



        int pos = p[b[i] - 'a'].back();

        Update(pos + 1, +1);

        p[b[i] - 'a'].pop_back();



        pos = pos + (Query(N) - Query(pos + 1));



        ans += pos - i;

    }



    fout << ans << '\n';

}



void Update(int pos, int val)

{

    for (int i = pos; i <= N; i += i & -i)

        aib[i] += val;

}



int Query(int pos)

{

    int sum{0};



    for (int i = pos; i > 0; i -= i & -i)

        sum += aib[i];



    return sum;

}
