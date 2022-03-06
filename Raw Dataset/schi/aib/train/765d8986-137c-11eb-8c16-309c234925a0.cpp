#include <fstream>
#include <stack>




using namespace std;



stack < int > st;



int aib[30005], clas[30005], n, a;



void update(int p, int val)

{

    for (int i = p; i <= n; i += i & -i)

        aib[i] += val;

}



int query(int p)

{

    int suma = 0;

    for (int i = p; i >= 1; i -= i & -i)

        suma += aib[i];

    return suma;

}



int bsearch(int p, int s)

{

    int st, dr, pos, mij;

    int suma;

    st = 1;

    dr = p;

    pos = -1;

    while (st <= dr)

    {

        mij =(st + dr) / 2;

        suma = query(mij);

        if (suma == s)

        {

            pos = mij;

            dr = mij - 1;

        }

        else if (suma > s) dr = mij - 1;

        else st = mij + 1;

    }

    return pos;

}



int main()

{

    ifstream fin("schi.in");

    ofstream fout("schi.out");



    fin >> n;



    for (int i = 1; i <= n; ++i)

    {

        fin >> a;

        st.push(a);

        update(i, 1);

    }



    for (int i = n; i >= 1; --i)

    {

        a = st.top();

        st.pop();

        int p = bsearch(n, a);

        clas[p] = i;

        update(p, -1);

    }



    for (int i = 1; i <= n; ++i)

        fout << clas[i] << "\n";



    return 0;

}
