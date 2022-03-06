#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAX_N = 50100;

char fst[MAX_N];
char lst[MAX_N];

int n;

int pos['z' + 5][MAX_N];

int ap['z' + 10];

int AIB[MAX_N];

inline int lsb(const int x){return x & (-x);}

void update(const int pos, const int delta){
    for(int i = pos ; i <= n ; i += lsb(i))
        AIB[i] += delta;
}

int query(const int pos){
    int ret = 0;
    for(int i = pos ; i > 0 ; i -= lsb(i))
        ret += AIB[i];
    return ret;
}

int organize() {

    int total = 0;

    for(int i = n ; i >= 1 ; --i) {

        const int next = pos[lst[i]][pos[lst[i]][0]--];

        const int shift = query(next);
        const int actual = next - shift;

        total += i - actual;

        update(next, 1);
    }

    return total;
}

int operations() {
    int i;

    for(i = 1 ; fst[i] && lst[i] ; ++i){

        pos[fst[i]][++pos[fst[i]][0]] = i;

        ap[fst[i]]++;
        ap[lst[i]]--;
    }

    n = i - 1;

    bool bad = 0;

    if(fst[i] || lst[i])
        bad = 1;

    for(char it = 'a' ; it <= 'z' && !bad ; ++it)
        if( ap[it] != 0 )
            bad = 1;


    if(bad)
        return -1;

    return organize();
}

int main() {
    ifstream in("swap.in");
    freopen("swap.out", "w", stdout);

    in >> (fst+1) >> (lst+1);

    printf("%d\n", operations());

    return 0;
}
