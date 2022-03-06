#include <bits/stdc++.h>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



const int nmax = 100005;



int n, auxSize;



struct Point{

    long long x, y;

}v[nmax], aux[nmax];



bool cmp(Point a, Point b){

    return a.x < b.x;

}



void Merge(int st, int dr){

    int mid = (st + dr) / 2;

    int i = st, j = mid + 1;

    auxSize = 0;

    while (i <= mid && j <= dr){

        if (v[i].y < v[j].y){

            aux[++auxSize] = v[i++];

        }

        else if (v[j].y < v[i].y){

            aux[++auxSize] = v[j++];

        }

        else{

            if (v[i].x < v[j].x){

                aux[++auxSize] = v[i++];

            }

            else{

                aux[++auxSize] = v[j++];

            }

        }

    }

    while (i <= mid){

        aux[++auxSize] = v[i++];

    }

    while (j <= dr){

        aux[++auxSize] = v[j++];

    }

    for (i = st, j = 1; i <= dr; ++i, ++j){

        v[i] = aux[j];

    }

}



long long GetDist(Point a, Point b){

    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);

}



long long GetMinDist(int st, int dr){

    if (dr - st + 1 <= 3){

        if (dr - st + 1 == 3){

            Merge(st + 1, dr);

            Merge(st, dr);

            return min(GetDist(v[st], v[st + 1]), min(GetDist(v[st], v[dr]), GetDist(v[st + 1], v[dr])));

        }

        else if (dr - st + 1 == 2){

            Merge(st, dr);

            return GetDist(v[st], v[dr]);

        }

    }

    int mid = (st + dr) / 2;

    int midX = v[mid].x;

    long long left = GetMinDist(st, mid);

    long long right = GetMinDist(mid + 1, dr);

    long long minim = min(left, right);

    Merge(st, dr);

    auxSize = 0;

    for (int i = st; i <= dr; ++i){

        if (1LL * (midX - v[i].x) * (midX - v[i].x) <= minim){

            aux[++auxSize] = v[i];

        }

    }

    for (int i = 1; i <= auxSize; ++i){

        for (int j = i + 1; j - i + 1 <= 9 && j <= auxSize; ++j){

            minim = min(1LL * minim, 1LL * GetDist(aux[i], aux[j]));

        }

    }

    return minim;

}



int main(){

    fin >> n;

    for (int i = 1; i <= n; ++i){

        fin >> v[i].x >> v[i].y;

    }

    sort(v + 1, v + n + 1, cmp);

    for (int i = 1; i < n; ++i){

        if (v[i].x == v[i + 1].x && v[i].y == v[i + 1].y){

            fout << 0;

            return 0;

        }

    }

    long long ans = GetMinDist(1, n);

    fout<<setprecision(6)<<fixed<<(double)sqrt(ans);

    fin.close();

    fout.close();

    return 0;

}
