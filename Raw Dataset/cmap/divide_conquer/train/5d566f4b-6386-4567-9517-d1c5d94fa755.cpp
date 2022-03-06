#include <bits/stdc++.h>






FILE *fin = freopen("cmap.in", "r", stdin);

FILE *fout = freopen("cmap.out", "w", stdout);



using namespace std;



const int MAX = 1e5 + 2;

const int INF = 2e9 + 2;

int n;

pair< double, double > p[MAX];

struct comp{

    bool operator () (const int &a, const int &b) const{

        return p[a].second < p[b].second;

    }

};



void Read(){

    scanf("%d", &n);

    for(int i = 0; i < n; ++ i)

        scanf("%lf%lf", &p[i].first, &p[i].second);

}



double Dist(pair< double, double > p1, pair< double, double > p2){

    return sqrt(1LL * (p1.second - p2.second) * (p1.second - p2.second) +

                1LL * (p1.first - p2.first) * (p1.first - p2.first));

}



double StripClosest(int strip[], int len, double d){

    double ans = d;

    sort(strip, strip + len, comp());



    for(int i = 0; i < len; ++ i){

        pair< double, double > p1 = p[strip[i]];

        for(int j = i + 1; j < len; ++ j){

            pair< double, double > p2 = p[strip[j]];

            if((p2.second - p1.second) >= d) break;

            ans = min(ans, Dist(p1, p2));

        }

    }

    return ans;

}



double BruteForce(int left, int right){

    double ans = INF;

    for(int i = left; i < right; ++ i)

        for(int j = left + 1; j <= right; ++ j)

            ans = min(ans, Dist(p[i], p[j]));

    return ans;

}



double Divide(int left, int right){

    if(right - left < 2)

        return BruteForce(left, right);



    int mid = (left + right) >> 1;

    double d = Divide(left, mid);

    d = min(d, Divide(mid + 1, right));



    int strip[n];

    int j = 0;



    for(int i = left; i <= right; ++ i)

        if(abs(p[mid].first - p[i].first) < d)

            strip[j ++] = i;



    return min(d, StripClosest(strip, j, d));

}



int main(){

    Read();

    sort(p, p + n);

    printf("%.10f\n", Divide(0, n - 1));

    return 0;

}
