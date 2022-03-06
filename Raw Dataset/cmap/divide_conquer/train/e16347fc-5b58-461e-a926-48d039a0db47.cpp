#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;



ifstream fin ("cmap.in");

ofstream fout ("cmap.out");

int n,i;

pair <long long,long long> v[100010],w[100010],d[100010];

long long dist (pair<long long,long long> a, pair<long long, long long> b){

    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);

}

inline long long modul (long long n){

    if (n < 0)

        return -n;

    return n;

}

void interclasare (int st,int mid,int dr){

    int i = st, j = mid+1, el = st-1;

    while (i <= mid && j <= dr){

        if (v[i].second <= v[j].second){

            d[++el] = v[i];

            i++;

        }

        else{

            d[++el] = v[j];

            j++;

        }

    }

    for (;i<=mid;i++)

        d[++el] = v[i];

    for (;j<=dr;j++)

        d[++el] = v[j];

    for (int i=st;i<=dr;i++)

        v[i] = d[i];

}



long long solve (int st, int dr){

    long long rez;

    if (dr - st == 1){

        rez = dist (v[st],v[dr]);

        interclasare (st,st,dr);

        return rez;

    }

    if (dr - st == 2){

        rez = min (dist(v[st],v[st+1]),min(dist(v[st],v[st+2]),dist(v[st+1],v[st+2])));

        interclasare (st,st,st+1);

        interclasare (st,st+1,dr);

        return rez;

    }



    int mid = (st+dr)/2;

    long long rezs = solve (st,mid);

    long long rezd = solve (mid+1,dr);



    interclasare (st,mid,dr);



    long long sol = min (rezs,rezd);



    int el = 0;

    for (int i=st;i<=dr;i++){

        if (modul(v[mid].first - v[i].first) <= sol)

            w[++el] = v[i];

    }



    for (int i=1;i<el;i++)

        for (int j=i+1;j<=el && j<=i+7;j++)

            sol = min (sol,dist(w[i],w[j]));



    return sol;





}

int main (){



    fin>>n;

    for (i=1;i<=n;i++)

        fin>>v[i].first>>v[i].second;

    sort (v+1,v+n+1);



    fout<<setprecision(7)<<fixed<<(double)sqrt(solve(1,n));



    return 0;

}
