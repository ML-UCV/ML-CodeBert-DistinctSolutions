#include <bits/stdc++.h>


FILE *in = fopen("schi.in", "r"), *out = fopen("schi.out", "w") ;



const int MV = 3e4 ;

const int SIZE = 1 << 12 ;



int n ;

int v[MV + 5] ;

int aint[(MV << 2) + 5] ;

int ans[MV + 5] ;

char Buffer[SIZE], ch ;

int point(SIZE) ;



void advance() {

        if (point == SIZE) {

                fread(Buffer, 1, SIZE, in) ;

                point = 0 ;

        }

        ch = Buffer[point ++] ;

}



int read() {

        int ret(0) ;

        while (!isdigit(ch)) { advance() ; }

        for ( ; isdigit(ch) ; advance()) { ret = ret * 10 + (ch - '0') ; }

        return ret ;

}



void Build(int node, int st, int dr) {

        if (st == dr) {

                aint[node] = 1 ;

                return ;

        }

        int mij((st + dr) >> 1) ;

        Build(node << 1, st, mij) ;

        Build((node << 1) + 1, mij + 1, dr) ;

        aint[node] = aint[node << 1] + aint[(node << 1) + 1] ;

}



void update(int node, int st, int dr, int x) {

        if (st == dr) {

                aint[node] = 0 ;

                return ;

        }

        int mij((st + dr) >> 1) ;

        if (mij >= x) {

                update(node << 1, st, mij, x) ;

        } else update((node << 1) + 1, mij + 1, dr, x) ;

        aint[node] = aint[node << 1] + aint[(node << 1) + 1] ;

}



int querry(int node, int st, int dr, int x) {

        if(st == dr) {

                return st ;

        }

        int mij((st + dr) >> 1) ;

        if (aint[node << 1] < x) {

                return querry((node << 1) + 1, mij + 1, dr, x - aint[node << 1]) ;

        } else return querry(node << 1, st, mij, x) ;

}



int main() {

        n = read() ;

        int poz ;

        for (int i = 1 ; i <= n ; ++ i) {

                v[i] = read() ;

        }

        Build(1, 1, n) ;

        for (int i = n ; i > 0 ; -- i) {

                poz = querry(1, 1, n, v[i]) ;

                ans[poz] = i ;

                update(1, 1, n, poz) ;

        }

        for (int i = 1 ; i <= n ; ++ i) {

                fprintf(out, "%d\n", ans[i]) ;

        }

}
