#include <fstream>
#include <algorithm>


using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int i, n, m, k, x[100001], aib[100001], sol;

struct meme{

    int value, pos;

}v[100001];

int cmp(meme a, meme b){

    return a.value < b.value;

}

void update(int x){

    while(x <= k){

        aib[x] = (aib[x] + 1) % 9917;

        x = x + (x & (-x));

    }

}

int quary(int x){

    int s = 0;

    while(x >= 1){

        s = (s + aib[x]) % 9917;

        x = x - (x & (-x));

    }

    return s;

}

int main()

{ f >> n;

    for(i = 1; i <= n; i++){

        f >> v[i].value;

        v[i].pos = i;

    }

    sort(v + 1, v + n + 1, cmp);

    k = 1;

    x[v[1].pos] = 1;

    for(i = 2; i <= n; i++){

        if(v[i].value != v[i - 1].value)

            k++;

        x[v[i].pos] = k;

    }

    for(i = 1; i <= n; i++){

        int value = quary(k) - quary(x[i]);

        if(value < 0)

            value += 9917;

        sol = (sol + value) % 9917;

        update(x[i]);

    }

    g << sol;

    return 0;

}
