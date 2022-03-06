#include <fstream>




using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");



int N, C[30005], aib[30005], place[30005];



void Add(int x, int val){

    for(int i = x; i <= N; i+=(i&(-i)))

        aib[i]+=val;

}



int Sum(int x){

    int s = 0;

    for(int i = x; i > 0; i-=(i&(-i)))

        s+=aib[i];

    return s;

}



int Search(int l, int r, int val){

    if(l > r)

        return N+1;

    int m = l + (r-l)/2;

    int p = Sum(m);

    if(p == val) return min(m, Search(l, m-1, val));

    else if(p > val) return Search(l, m-1, val);

    else return Search(m+1, r, val);

}



void Read(){

    fin>>N;

    for(int i = 1; i <= N; i++){

        fin>>C[i];

        Add(i, 1);

    }

}



void Solve(){

    for(int i = N; i > 0; i--){

        int a = Search(1, N, C[i]);

        place[a] = i;

        Add(a, -1);

    }

    for(int i = 1; i <= N; i++)

        fout<<place[i]<<'\n';

}



int main()

{

    Read();

    Solve();

    return 0;

}
