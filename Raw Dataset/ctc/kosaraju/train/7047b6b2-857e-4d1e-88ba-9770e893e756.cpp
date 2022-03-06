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







void dfs(int nod){

    used[nod] = 1;



    for (auto& x : gr[nod]){

        if (!used[x]) dfs(x);

    }



    comp.push_back(nod);

}







int main() {



    int n, m; cin >> n >> m;



    for (int i = 1; i <= m; i++){

        int a, b; cin >> a >> b;



        gr[a].push_back(b);

        gr2[b].push_back(a);

    }



    for (int i = 1; i <= n; i++){

        if (!used[i]) dfs(i);

        for (auto& el : comp) ord.push_back(el);

        comp.clear();

    }



    for (int i = 1; i <= n; i++){

        used[i] = 0;

        gr[i] = gr2[i];

    }



    reverse (ord.begin(), ord.end());



    for (auto & i : ord){

        if (!used[i]) dfs(i);

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
