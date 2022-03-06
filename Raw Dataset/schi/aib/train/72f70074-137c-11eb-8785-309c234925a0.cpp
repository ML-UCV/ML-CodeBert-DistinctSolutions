#include <fstream>
#include <algorithm>


using namespace std;



ifstream cin("schi.in");

ofstream cout("schi.out");



int aib[30005];

int v[30005];

int r[30005];



int n;



int len(int x)

{

    return x & -x;

}



int q(int poz)

{

    int sum = 0;

    while(poz)

    {

        sum += aib[poz];

        poz -= len(poz);

    }

    return sum;

}



void u(int poz , int val)

{

    while(poz <= n)

    {

        aib[poz] += val;

        poz += len(poz);

    }

}



int main()

{

    int i , mij , ac , pas;



    cin >> n;



    for(i = 1; i <= n; i++)

        u(i , 1);

    for(i = 1; i <= n; i++)

        cin >> v[i];

    reverse (v + 1, v + n + 1);

    for(i = 1; i <= n; i++)

    {

        mij = v[i];

        ac = 0;

        pas = 1 << 20;

        while(pas)

        {

            if(ac + pas <= n)

            if(aib[ac + pas] < mij)

            mij -= aib[ac + pas] , ac += pas;

            pas >>= 1;

        }

        ac++;

        r[ac] = n - i + 1;

        u(ac , -1);

    }

    for(i = 1; i <= n; i++)

        cout << r[i] <<'\n';



    return 0;

}
