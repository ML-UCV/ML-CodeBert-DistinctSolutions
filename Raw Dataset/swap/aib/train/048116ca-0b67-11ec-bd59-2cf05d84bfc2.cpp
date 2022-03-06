#include <fstream>
#include <string>
#include <vector>

using namespace std;

int N;
string A, B;

vector <int> freq[26];

inline int lsb(int node) {
    return node & (-node);
}

const int NMAX = 50000 + 5;
int aib[NMAX];

void init() {
    for (int i = 1; i <= N; ++ i)
        aib[i] = lsb(i);
}

void update(int where) {
    for (; where <= N; where += lsb(where))
        aib[where] --;
}

int query(int where) {
    int ans = 0;
    for (; where; where -= lsb(where))
        ans += aib[where];
    return ans;
}

int main()
{
    ifstream cin("swap.in");
    ofstream cout("swap.out");

    cin >> A >> B;
    N = A.size();
    A = " " + A;
    B = " " + B;

    for (int i = N; i; -- i)
        freq[B[i] - 'a'].push_back(i);
    init();

    int ans = 0;
    for (int i = 1; i <= N; ++ i)
        if (freq[A[i] - 'a'].empty()) {
            ans = -1;
            break;
        }
        else {
            int pos = freq[A[i] - 'a'].back();
            freq[A[i] - 'a'].pop_back();
            update(pos);
            ans += query(pos);
        }

    if (ans == -1)
        cout << "-1\n";
    else
        cout << ans << '\n';
    return 0;
}
