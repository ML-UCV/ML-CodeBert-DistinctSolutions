#include <fstream>


using namespace std;



ifstream cin("schi.in");

ofstream cout("schi.out");



int v[30005];

int aib[30005];

int r[30005];

int n;



int lsb(int x)

{

    return x&-x;

}



int u(int poz , int val)

{

    while(poz <= n)

    {

        aib[poz] += val;

        poz += lsb(poz);

    }

}



int q(int poz)

{

    int sum = 0;

    while(poz)

    {

        sum += aib[poz];

        poz -= lsb(poz);

    }

}



int main()

{

    int i , x , pas , poz;

    cin >> n;

    for(i = 1; i <= n; i++)

        u(i , 1);

    for(i = 1; i <= n; i++)

    {

        cin >> v[n - i + 1];

    }

    for(i = 1; i <= n; i++)

    {

        x = v[i];

        pas = 1<<16;

        poz = 0;

        while(pas)

        {

            if(poz + pas <= n)

            if(aib[poz + pas] < x)

                {x -= aib[poz + pas];

                poz += pas;}

            pas>>=1;

        }

        poz++;

        r[poz] = n - i + 1;

        u(poz , -1);

    }

    for(i = 1; i <= n ; i++)

        cout << r[i] << '\n';

    return 0;

}
