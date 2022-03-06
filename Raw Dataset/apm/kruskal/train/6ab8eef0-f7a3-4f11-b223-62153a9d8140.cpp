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







ifstream fin("apm.in"); ofstream fout("apm.out");





struct node {

    int x, y, dist;

} mat [400005];



bool cmp(node a, node b) {

    return a.dist < b.dist;

}



int dad[200005];



vector <node> anss;



int ans = 0;



int finddad(int nod) {

    if(dad[nod] != nod) dad[nod] = finddad(dad[nod]);

    return dad[nod];

}



void unite(int a, int b) {

    finddad(a);

    finddad(b);

    dad[dad[b]] = dad[a];

}
int main() {

    int n, m;

    fin >> n >> m;



    for (int i = 1; i <= m; i++) {

        int x, y, dist;

        fin >> mat[i].x >> mat[i].y >> mat[i].dist;

    }



    for (int i = 1; i <= n; i++) {

        dad[i] = i;

    }



    sort(mat + 1, mat + m + 1, cmp);

    for (int i = 1; i <= m; i++) {

        node now = mat[i];



        int x, y;



        x = finddad(now.x);

        y = finddad(now.y);



        if (x != y) {

            unite(x, y);

            anss.push_back(now);

            ans += now.dist;

        }

    }



    fout << ans << '\n' << anss.size() << '\n';

    for (auto& x : anss) {

        fout << x.x << " " << x.y << '\n';

    }



    return 0;

}
