#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
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
#include <assert.h>
#include <fstream>






using namespace std;

using ll = long long;





ifstream cin("ctc.in"); ofstream cout("ctc.out");







const int maxn = 100005;



vector <int> gr[maxn], gr2[maxn];



int used[maxn];



vector <int> ord, comp;

vector <vector <int>> ans;







void dfs1(int nod){

    used[nod] = 1;



    for (auto& x : gr[nod]){

        if (!used[x]) dfs1(x);

    }

    ord.push_back(nod);

}



void dfs2 (int nod){

    used[nod] = 1;

    comp.push_back(nod);



    for (auto & x : gr2[nod]){

        if (!used[x]) dfs2(x);

    }

}







int main() {



    int n, m; cin >> n >> m;



    for (int i = 1; i <= m; i++){

        int a, b; cin >> a >> b;



        gr[a].push_back(b);

        gr2[b].push_back(a);

    }



    for (int i = 1; i <= n; i++){

        if (!used[i]) dfs1(i);

    }



    for (int i = 1; i <= n; i++) used[i] = 0;



    reverse (ord.begin(), ord.end());



    for (auto & i : ord){

        if (!used[i]) dfs2(i);

        if (!comp.empty()) ans.push_back(comp);

        comp.clear();

    }



    cout << ans.size() << '\n';

    for (auto& vec : ans){

        for (auto& elem : vec){

            cout << elem << ' ';

        }

        cout << '\n';

    }



    return 0;

}
