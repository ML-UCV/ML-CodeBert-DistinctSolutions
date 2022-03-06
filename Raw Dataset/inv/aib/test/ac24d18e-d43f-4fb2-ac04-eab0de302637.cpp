#include <fstream>
#include <unordered_map>
#include <algorithm>




using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");

int n, v[100010],v2[100010], aib[100010],ans;

unordered_map <int, int> M;

void update(int nr)

{

    for(int i = nr; i <= n; i += (i & (-i)))

    {

        aib[i] ++;

    }



}

int suma(int nod)

{

    int sum = 0;

    for(int i = nod; i; i -= (i & (-i)) )

    {

        sum += aib[i];

        sum %= 9917;

    }

    return sum;

}

int main()

{

    f >> n;

    for(int i = 1; i <= n; ++i)

        f >> v[i], v2[i] = v[i];

    sort(v + 1, v + n + 1);

    int p = 0;

    v[0] = -1;

    for(int i = 1; i <= n; ++i)

    {

        if(v[i] != v[i-1])

            p++;

        M[v[i]] = p;

    }

    for(int i = n; i >= 1; --i)

    {

        ans += suma(M[v2[i]] - 1);

        ans %= 9917;

        update(M[v2[i]]);

    }

    g << ans;

    f.close();

    g.close();

    return 0;

}
