#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;




int n, m, h[400004], s, tata[200003], sol[200003];

typedef struct muchii{int x, y, z;} muc;
muc a[400004];

void citire();

bool cmp ( int b, int c){
    return ( a[b].z < a[c].z);
}

int main(){
    freopen("apm.in","r",stdin);
    freopen("apm.out","w",stdout);
    citire();

    int cn, i, j, k, u = 0, r, w;
    char rezidual[100];

    for (cn = 1; cn <= m; cn++){
        r = h[cn];
        for (i = a[r].x; tata[i] != 0; i = tata[i]);
        for (j = a[r].y; tata[j] != 0; j = tata[j]);

        if (i != j){
            s += a[r].z;
            sol[++u] = r;
            tata[i] = j;
            if ( tata[a[r].x] > 0)
                for (k = a[r].x; tata[k] != 0; k = w){
                    w = tata[k];
                    tata[k] = j;
                }

            if (tata[a[r].y] > 0)
                for (k = a[r].y; tata[k] != 0; k = w){
                    w = tata[k];
                    tata[k] = j;
                }

        }
    }
    printf("%d\n%d\n", s, u);
    for (i = 1; i <= u; i++)
        printf("%d %d\n", a[sol[i]].x, a[sol[i]].y);

    return 0;
}

void citire(){
    int i;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= m; i++){
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
        h[i] = i;
    }
    sort(h+1, h+m+1, cmp );
}
