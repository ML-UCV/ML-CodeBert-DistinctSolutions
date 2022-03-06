#include <fstream>
#include <iostream>
#include <algorithm>


using namespace std;



int aib[100005], n, k;



const int mod = 9917;



struct Element

{

    int val, pos, new_val;

} v[100005];



bool ByValue (Element a, Element b)

{

    return a.val < b.val;

}



bool ByIndex (Element a, Element b)

{

    return a.pos < b.pos;

}



void Read_Normalize ()

{

    ifstream fin ("inv.in");

    fin >> n;

    int i, x;

    for (i = 1; i <= n; i++)

    {

        fin >> x;

        v[i].val = x;

        v[i].pos = i;

    }

    sort (v + 1, v + n + 1, ByValue);

    v[1].new_val = 1;

    k = 1;

    for (i = 2; i <= n; i++)

        if (v[i].val == v[i - 1].val)

            v[i].new_val = k;

        else k++, v[i].new_val = k;

    sort (v + 1, v + n + 1, ByIndex);

}





void Update (int p, int x)

{

    for (; p <= n; p += (p & - p))

        aib[p] += x;

}



int Sum (int p)

{

    int s;

    for (s = 0; p > 0; p -= (p & - p))

        s += aib[p];

    return s;

}



void Solve ()

{

    int ans = 0, i;

    Update(v[n].new_val, 1);

    for (i = n - 1; i >= 1; i--)

    {

        ans = (ans + Sum(v[i].new_val - 1)) % mod;

        Update(v[i].new_val, 1);

    }

    ofstream fout ("inv.out");

    fout << ans << "\n";

    fout.close();

}



int main()

{

    Read_Normalize();

    Solve();

    return 0;

}
