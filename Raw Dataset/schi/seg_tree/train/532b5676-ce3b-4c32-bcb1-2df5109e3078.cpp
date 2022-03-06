#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <fstream>






using namespace std;







ifstream fin("schi.in"); ofstream fout("schi.out");







int v[300005];

int ans[300005];

int gr[1200005];



int n;







void update(int nod, int st, int dr, int pos, int val) {

    if (st == dr) {

        gr[nod] = val;

        return;

    }



    int mid = st + dr;

    mid /= 2;



    if (pos <= mid) update(nod * 2, st, mid, pos, val);

    else update(nod * 2 + 1, mid + 1, dr, pos, val);



    gr[nod] = gr[nod * 2] + gr[nod * 2 + 1];

}



void query(int nod, int st, int dr, int pos, int val) {

    if (st == dr) {

        ans[st] = val;

        update(1, 1, n, st, 0);

        return;

    }



    int mid = st + dr;

    mid /= 2;



    if (gr[nod * 2] >= pos) query(nod * 2, st, mid, pos, val);

    else query(nod * 2 + 1, mid + 1, dr, pos - gr[nod * 2] , val);



}





int main() {



    fin >> n;



    for (int i = 1; i <= n; i++) {

        update(1, 1, n, i, 1);

        fin >> v[i];

    }



    for (int i = n; i >= 1; i--) query(1, 1, n, v[i], i);



    for (int i = 1; i <= n; i++) {

        fout << ans[i] << '\n';

    }



    return 0;

}
