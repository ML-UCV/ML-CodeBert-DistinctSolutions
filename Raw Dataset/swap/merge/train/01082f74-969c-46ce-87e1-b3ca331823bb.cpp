#include <fstream>
using namespace std;



ifstream f("swap.in");



ofstream g("swap.out");







char a[50005], b[50005];



int u1[27], u2[27], fr[27], p[50005], H[3*50005], sol;



void update(int n, int l, int r, int p, int v) {



    if (l >= r) {H[n] += v; return;}



    int m = (l + r) >> 1;



    if (m >= p) update(n<<1,l,m,p,v);



    else update((n<<1)|1,m+1,r,p,v);



    H[n] = H[n<<1] + H[(n<<1)|1];



}



void query(int n, int l, int r, int a, int b) {



    if (a <= l && r <= b) {sol += H[n]; return;}



    int m = (l + r) >> 1;



    if (a <= m) query(n<<1,l,m,a,b);



    if (b > m) query((n<<1)|1,m+1,r,a,b);



}







int main()



{



    for (int i = 0; i < 27; ++i) fr[i] = -1;



    f >> a >> b;



    int i;



    for (i = 0; a[i]; ++i) ++u1[a[i] - 'a'];



    int n = i;



    for (i = 0; b[i]; ++i) {++u2[b[i] - 'a']; if (fr[b[i]-'a'] == -1) fr[b[i]-'a'] = i;}



    for (i = 0; i < 27; ++i) if (u1[i] != u2[i]) {g << "-1\n"; return 0;}



    for (i = 0; a[i]; ++i) {



        p[i + 1] = fr[a[i]-'a'] + 1;



        ++fr[a[i]-'a'];



        while (b[fr[a[i]-'a']] != a[i]) {



            ++fr[a[i]-'a'];



            if (!b[fr[a[i]-'a']]) fr[a[i]-'a'] = 0;



        }



    }



    for (i = 1; i <= n; ++i) update(1,1,n,p[i],1);



    for (i = 1; i <= n; ++i) {



        if (p[i] > 1) query(1,1,n,1,p[i] - 1);



        update(1,1,n,p[i],-1);



    }



    g << sol << '\n';



    return 0;



}
