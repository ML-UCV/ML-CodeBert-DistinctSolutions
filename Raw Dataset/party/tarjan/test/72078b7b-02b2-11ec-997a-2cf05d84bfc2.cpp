#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>


using namespace std;

const int CONST = 20;
const int MAXN = 101;

bool assign[MAXN];

bool eval(const pair<int, int>& p)
{
    bool a = assign[abs(p.first)];
    bool b = assign[abs(p.second)];

    if (p.first < 0)
        a ^= 1;
    if (p.second < 0)
        b ^= 1;

    return a | b;
}

void print(int N)
{
    vector<int> res;
    for (int i = 1; i <= N; ++i)
        if (assign[i]) res.push_back(i);

    printf("%d\n", static_cast<int>(res.size()));
    for (vector<int>::iterator it = res.begin(); it != res.end(); ++it)
        printf("%d\n", *it);
}

bool check(int N)
{
    for (int i = 1; i <= N; ++i)
        if (assign[i]) return true;

    return false;
}

int main()
{
    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);

    int N, M;
    scanf("%d %d", &N, &M);

    vector<pair<int, int> > vec;
    for (int i = 0; i < M; ++i) {
        int x, y, op;
        scanf("%d %d %d", &x, &y, &op);

        if (op == 1) {
            y = -y;
        } else if (op == 2) {
            x = -x;
        } else if (op == 3) {
            x = -x;
            y = -y;
        }
        vec.push_back(make_pair(x, y));
    }

    srand(time(NULL));

    for (int i = 1; i <= N; ++i)
        assign[i] = static_cast<bool>(rand() % 2);

    while (true) {
        typedef vector<pair<int, int> >::iterator iter;

        bool result = true;
        iter pos;
        for (iter it = vec.begin(); it != vec.end(); ++it) {
            result &= eval(*it);
            if (!result) {
                pos = it;
                break;
            }
        }

        if (result && check(N)) {
            print(N);
            return 0;
        } else {
            if (rand() % 2 == 0)
                assign[abs(pos->first)] ^= 1;
            else
                assign[abs(pos->second)] ^= 1;
        }
    }

    return 0;
}
