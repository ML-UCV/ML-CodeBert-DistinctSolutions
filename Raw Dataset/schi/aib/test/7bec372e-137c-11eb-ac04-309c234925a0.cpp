#include <iostream>
#include <fstream>
using namespace std;





inline int zeros (int x){

    return x & (-x);

}



int aib[30300],i,n,v[30300],ans[30300],k;



void update (int poz, int x){

    for (int i = poz; i < n; i += zeros(i))

        aib[i] += x;

}



int compute (int poz) {

    int ans = 0;

    for (int i = poz; i > 0; i -= zeros(i))

        ans += aib[i];

    return ans;

}



int bs (int val) {

    int poz = 0;

    for (int i = n - 1; i > 0; i >>=1)

        while (poz + i < n && compute(poz + i) < val)

        poz += i;

    return poz + 1;

}

int main()

{

    ifstream fin("schi.in");

    ofstream fout("schi.out");

    fin >> n;

    ++n;

    for (i = 1; i < n; ++i){

        fin >> v[i];

        aib[i] = zeros(i);

    }

    for (i = n - 1; i > 0; --i){

        k = bs(v[i]);

        ans[k] = i;

        update(k, -1);

    }

    for (i = 1; i < n; ++i)

        fout << ans[i] << '\n';

    fin.close();

    fout.close();

    return 0;

}
