#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <fstream>






using namespace std;



const double PI = acos(-1);

const double eps = 1e-6;



inline long long lgput(long long a , long long b , long long mod) {

    long long ret = 1;

    while( b ){

        if(b & 1) ret = (ret * a) % mod;

        a = (a * a) % mod;

        b >>= 1;

    }



    return (ret%mod);

}



inline long long inv(long long x , long long MOD) {

    return lgput(x, MOD - 2, MOD);

}



inline bool exist (double nr){

    return (nr < -eps) || (nr > eps);

}



long long big_rand(){

    return rand () * RAND_MAX + rand();

}
ifstream cin ("cmap.in");ofstream cout ("cmap.out");



struct nod{long long x , y;};

bool cmpx (nod a , nod b){return a.x < b.x;}

bool cmpy (nod a , nod b){return a.y < b.y;}

nod v[100100] , ord[100100];



double dist (nod a , nod b){

    double now = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);

    return sqrt(now);

}



double solve (int st , int dr){



    double ans = 1e18;

    if (dr-st+1 <= 3){

        for (int i=st; i<=dr; i++){

            for (int j=i+1; j<=dr; j++){

                ans = min(ans , dist(v[i] , v[j]));

            }

        }

        sort (v+st , v+dr+1 , cmpy);

        return ans;

    }



    int mij = st + dr;

    mij /= 2;

    long long middle = v[mij].x;

    double low = min(solve(st , mij) , solve(mij+1 , dr));



    int ST = st , DR = mij+1 , pnt = st;

    while (ST <= mij && DR <= dr){



        if (v[ST].y < v[DR].y){

            ord[pnt++] = v[ST++];

        }

        else{

            ord[pnt++] = v[DR++];

        }

    }

    for (; ST<=mij; ST++)ord[pnt++]=v[ST];

    for (; DR<=dr; DR++)ord[pnt++]=v[DR];



    for (int i=st; i<=dr; i++){



        v[i] = ord[i];

        if (i > st){

            if (v[i].y < v[i-1].y){

                cout<<"MUIE"<<'\n';

            }

        }

    }



    pnt = 0;

    for (int i=st; i<=dr; i++){

        if (abs(v[i].x - middle) <= (long long)low){

            ord[++pnt]= v[i];

        }

    }



    ans = low;

    for (int i=1; i<=pnt; i++){

        for (int j=i+1; j<=pnt; j++){

            if (ord[j].y - ord[i].y > (long long)low){

                break;

            }

            ans = min(ans , dist(ord[i] , ord[j]));

        }

    }



    return ans;

}





int main() {







    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    cout << setprecision(10) << fixed;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    srand(time(nullptr));



    int n;

    cin>>n;



    for (int i=1; i<=n; i++){

        int a , b;

        cin>>a>>b;

        v[i].x = a;

        v[i].y = b;

    }

    sort(v+1 , v+n+1 , cmpx);

    cout<<solve (1 , n)<<'\n';



    return 0;

}
