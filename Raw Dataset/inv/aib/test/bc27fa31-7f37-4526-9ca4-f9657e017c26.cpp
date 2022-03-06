#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>




using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");



const int MOD = 9917;



int tree[100001];

pair<int, int> v[100001];

int n;



void update(int poz)

{

    for(int i = poz; i <= n; i += i&-i)

        tree[i]++;

}



int64_t query(int poz)

{

    int s = 0;



    for(int i = poz; i; i -= i&-i)

        s += tree[i]%MOD;



    return s%MOD;

}



int main()

{

    in >> n;



    for(int i = 1; i <= n; i++)

    {

        in >> v[i].first;

        v[i].second = i;

    }



    sort(v+1, v+n+1);



    if(!1)

    {

        for(int i = 1; i <= n; i++)

            cout << v[i].first << ' ' << v[i].second << '\n';

    }



     if(!1)

     {

            for(int i = 1; i <= n; i++)

                cout << i << ' ' << tree[i] << '\n';

            cout << '\n';





            for(int i = 1; i <= n; i++)

                cout << i << ' ' << tree[i] << '\n';

            cout << '\n';

            cout << query(2) << ' ' << query(4);

     }



    int64_t rez = 0;

    for(int i = n; i; i--)

    {

        if(!1)

        {

            if(query(v[i].second))

                cout << query(v[i].second) << ' ' << v[i].first << ' ' << v[i].second << '\n';

        }

        rez += query(v[i].second)%MOD;

        update(v[i].second);



    }

    out << rez%MOD;



    return 0;

}
