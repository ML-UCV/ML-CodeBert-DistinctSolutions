#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair< int , int > PII;

int n, m, a[250100][20];
vector < int > V[250100];
bitset < 250100 > B;

int pozr;
char buffer[1010];
FILE *fi, *fo;

char getch(){
    if( pozr == 1010 ){
        fread( buffer, 1010, 1, fi );
        pozr = 0;
    }
    return buffer[ pozr++ ];
}

int scano(){
    int nr = 0, sign = 1;
    char ch = getch();

    while( isdigit(ch) == 0 && ch != '-')
        ch = getch();

 if (ch == '-'){
  sign = -1;
  ch = getch();
 }

    while( isdigit(ch) != 0 ){
        nr = nr * 10 + ch - '0';
        ch = getch();
    }

    return nr * sign;
}

void dfs(int x) {
    B[x] = 1;

    for (int i = 1; i <= 18; i++) {
        a[x][i] = a[a[x][i - 1]][i - 1];
    }

    for (auto it : V[x]) {
        if (B[it]) continue;
        dfs(it);
    }
}

int main(){
    fi = fopen("stramosi.in", "r");
    fo = fopen("stramosi.out", "w");

    n = scano();
    m = scano();
    for (int i = 1; i <= n; i++) {
        a[i][0] = scano();
        V[a[i][0]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i][0] == 0) dfs(i);
    }

    while (m--) {
        int x, y;
        x = scano();
        y = scano();

        while (y) {
            int lg = log2(y);

            x = a[x][lg];

            y -= (1 << lg);
        }

        fprintf(fo, "%d\n", x);
    }
 return 0;
}
