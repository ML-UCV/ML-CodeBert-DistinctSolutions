#include <fstream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;



const int N = 101;

const int a[] = {1, 1, -1, -1};

const int b[] = {1, -1, 1, -1};



class Sat{

    vector<int> etc1[2 * N], *graph;

    vector<int> etc2[2 * N], *trans;

    int etc3[2 * N], *ctc, size;

    bool etc4[2 * N], *use;

    stack<int> S;



    void reset(){

        memset(etc4, false, sizeof(etc4));

    }



    void unalloc(vector<int>& v){

        vector<int> a;

        a.swap(v);

    }



    void dfs(int x){

        use[x] = true;



        for (vector<int> :: iterator it = trans[x].begin() ; it != trans[x].end() ; it++)

            if (!use[*it])

                dfs(*it);



        S.push(x);

    }



    void dfs(int x, int C){

        ctc[x] = C;

        use[x] = true;



        for (vector<int> :: iterator it = graph[x].begin() ; it != graph[x].end() ; it++)

            if (!use[*it])

                dfs(*it, C);

    }



    void get_ctc(){

        int nr = 0;



        reset();



        for (int i = -size ; i <= size ; i++)

            if (!use[i])

                dfs(i);



        reset();



        while (!S.empty()){

            if (!use[S.top()])

                dfs(S.top(), ++nr);



            S.pop();

        }

    }

public:

    Sat(){

        graph = etc1 + N;

        trans = etc2 + N;

        ctc = etc3 + N;

        use = etc4 + N;

    }



    void push(int x, int y){

        graph[-x].push_back(y);

        graph[-y].push_back(x);



        trans[x].push_back(-y);

        trans[y].push_back(-x);

    }



    vector<int> get_sat(int n){

        size = n;



        get_ctc();



        vector<int> v;



        for (int i = 1 ; i <= size ; i++)

            if (ctc[i] == ctc[-i]){

                v.clear();

                v.push_back(-1);

                return v;

            } else

                v.push_back(ctc[i] < ctc[-i]);

        return v;

    }

};



Sat S;

int ans[N];

vector<int> v;



ifstream in("party.in");

ofstream out("party.out");



int main(){

    int n, m, x, y, z;



    in >> n >> m;



    while (m--){

        in >> x >> y >> z;



        S.push(x * a[z], y * b[z]);

    }



    v = S.get_sat(n);



    for (int i = 0 ; i < v.size() ; i++)

        if (v[i])

            ans[++ans[0]] = i + 1;



    for (int i = 0 ; i <= ans[0] ; i++)

        out << ans[i] << "\n";



    return 0;

}
