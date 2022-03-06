#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int NO_LIT = 'z' - 'a' + 1;
const int LMAX = 50001;
vector<int>litere[NO_LIT + 1];
int left[NO_LIT + 1], aib[LMAX], l;

char a[LMAX],b[LMAX];

int askAIB(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += aib[pos];
        pos -= pos ^ (pos & (pos - 1));
    }
    return ret;
}

void incrAIB(int pos) {
    while (pos <= l) {
        aib[pos]++;
        pos += pos ^ (pos & (pos - 1));
    }
}

int solve() {
    FILE *fin = fopen("swap.in", "r");
    fscanf (fin, "%s\n", &a);
    fscanf (fin, "%s\n", &b);
    l = strlen(a);
    if (strlen(b) != l) return -1;

    int i;
    for (i = 0; i < l; ++i) {
        litere[a[i]-'a'].push_back(i);
    }
    int ret = 0;
    for (i = 0; i < l; ++i) {
        int litera = b[i] - 'a';
        if (left[litera] == litere[litera].size()) {
            return -1;
        }
        int pos = litere[litera][left[litera]++];
        ret += pos - askAIB(pos);
        incrAIB(pos + 1);
    }
    return ret;
}

int main() {
    fprintf (fopen("swap.out", "w"), "%d", solve());
    return 0;
}
