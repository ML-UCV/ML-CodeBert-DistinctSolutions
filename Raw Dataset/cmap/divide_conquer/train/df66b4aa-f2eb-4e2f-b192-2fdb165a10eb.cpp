#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;



typedef pair<int, int> Point;

Point A[100000 +1];

Point B[100000 +1];

Point C[100000 +1];

int N;



bool cmp(const Point A, const Point B)

{

    if(A.second == B.second) return A.first < B.first;

    return A.second < B.second;

}



long long dist(Point A, Point B)

{

    return 1LL * (A.first - B.first) * (A.first - B.first) + 1LL * (A.second - B.second) * (A.second - B.second);

}



long long Solve(int st, int dr)

{

    if(st >= dr) return 1LL<<62;

    else if(dr - st == 1){

        if(B[st] > B[dr]) swap(B[st], B[dr]);

        return dist(A[st], A[dr]);

    }



    int i, j, k = 0, mid = (st + dr) / 2;

    long long res;



    res = min(Solve(st, mid), Solve(mid+1, dr));

    merge(B + st, B + mid + 1, B + mid + 1, B + dr + 1, C, cmp);

    for(i = st; i <= dr; ++i) B[i] = C[i-st];

    for(i = st; i <= dr; ++i)

        if((B[i].first - A[mid].first) * (B[i].first - A[mid].first) <= res) C[++k] = B[i];



    for(i = 1; i < k; ++i)

        for(j = i+1; j <= k && j - i <= 8; ++j)

        res = min(res, dist(C[i], C[j]));



    return res;

}



int main(){

    FILE* fin = fopen("cmap.in","r");

    FILE* fout = fopen("cmap.out","w");



    int i;



    fscanf(fin,"%d",&N);

    for(i = 1; i <= N; ++i) fscanf(fin,"%d %d",&A[i].first,&A[i].second);



    sort(A+1,A+N+1);

    for(i = 1; i <= N; ++i) B[i] = A[i];

    fprintf(fout,"%f\n",sqrt(Solve(1,N)));





return 0;

}
