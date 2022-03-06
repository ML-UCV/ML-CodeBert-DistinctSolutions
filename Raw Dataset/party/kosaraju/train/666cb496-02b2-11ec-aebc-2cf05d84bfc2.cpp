#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>


using namespace std;



class P2SAT {

public:

    P2SAT(const int N) {

        Size = 2 * N + 2;

        Offset = N;

        G = vector< vector<int> >(Size);

        Gt = G;

        values = vector<int>(Size, 0);

        used = vector<bool>(Size, false);

    }



    void addRel(int x, int y) {

        addEdge(Offset - x, Offset + y);

        addEdge(Offset - y, Offset + x);

    }



    void addMust(int x) {

        addEdge(Size - 1, Offset + x);

        addEdge(Offset - x, Offset);

    }



    vector<int> getValues() {

        stk.reserve(Size);

        for (int i = 0; i < Size; ++i)

            if (!used[i])

                Dfs1(i);



        fill(used.begin(), used.end(), false);

        Dfs2(Offset);

        for (int i = Size - 1; i >= 0; --i)

            if (!values[stk[i]] && !values[Non(stk[i])])

                Dfs2(stk[i]);



        stk.clear();

        if (values[Offset] == -1) return vector<int>(1, -1);

        for (int i = 0; i <= Offset; ++i)

            if (values[i] == values[Non(i)]) return vector<int>(1, -1);



        vector<int> ret(Offset + 1);

        for (int i = 1; i <= Offset; ++i)

            ret[i] = values[Offset + i];



        return ret;

    }



private:

    vector< vector<int> > G, Gt;

    vector<int> values, stk;

    vector<bool> used;

    int Offset, Size;



    void addEdge(int x, int y) {

        G[x].push_back(y);

        Gt[y].push_back(x);

    }



    void Dfs1(const int node) {

        used[node] = 1;

        for (int p: G[node])

            if (!used[p]) Dfs1(p);



        stk.push_back(node);

    }



    void Dfs2(const int node) {

        used[node] = 1;

        if (values[node])

            values[Offset] = -1;



        values[Non(node)] = 1;

        for (int p: Gt[node])

            if (!used[p]) Dfs2(p);

    }



    int Non(const int n) const {

        if (n == Offset) return Size - 1;

        if (n == Size - 1) return Offset;

        return 2 * Offset - n;

    }

};



vector<int> getNonZero(const vector<int>& A) {

    vector<int> ret;

    for (int i = 1; i < int(A.size()); ++i)

        if (A[i])

            ret.push_back(i);

    return ret;

}



int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    int N, M;

    scanf("%d%d", &N, &M);



    P2SAT S(N);

    while (M--)

    {

        int x, y, op;

        scanf("%d%d%d", &x, &y, &op);



        if (op == 1) y = -y;

        else if (op == 2) x = -x;

        else if (op == 3)

        {

            x = -x;

            y = -y;

        }



        S.addRel(x, y);

    }



    vector<int> Ans = getNonZero(S.getValues());



    printf("%u\n", Ans.size());

    for (const int p: Ans) printf("%d\n", p);

}
