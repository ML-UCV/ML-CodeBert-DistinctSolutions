#include <bits/stdc++.h>


using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");



const int MAX = 3 * 1e4 + 5;



int n, pas = 1;

int tree[MAX], v[MAX], ans[MAX];



int Query(int idx)

{

    int sum = 0;

    for(; idx; idx -= (idx & (-idx)))

        sum += tree[idx];

    return sum;

}



void Update(int idx, int val)

{

    for(; idx <= n; idx += (idx & (-idx)))

        tree[idx] += val;

}



int main()

{

    f >> n;



    for(; pas <= n; pas <<= 1);

    for(int i = 1; i <= n; ++i)

    {

        f >> v[i];

        Update(i, 1);

    }



    for(int i = n; i >= 1; --i)

    {

        int k = 0, step = pas;

        for(; step; step >>= 1)

            if(k + step <= n && Query(k + step) < v[i])

                k += step;

        ans[k + 1] = i;

        Update(k + 1, -1);

    }



    for(int i = 1; i <= n; ++i)

        g << ans[i] << "\n";



    return 0;

}
