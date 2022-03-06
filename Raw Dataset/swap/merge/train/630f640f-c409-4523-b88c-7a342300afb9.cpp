#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;



vector <pair <int, int> > w;



int H[3*50005], v[50005], freq[2][200];

int n, inv = 0, sol = 0;



string a, b;



void query(int node, int lo, int hi, int a, int b) {

    if(a > b) return;

    if(a <= lo && hi <= b) {

        inv += H[node];

        return;

    }



    int mid = (lo + hi) >> 1;

    if(a <= mid) query(2*node, lo, mid, a, b);

    if(b > mid) query(2*node+1, mid+1, hi, a, b);

}



void update(int node, int lo, int hi, int pos) {

    if(lo == hi) {

        H[node]++;

        return;

    }



    int mid = (lo + hi) >> 1;

    if(pos <= mid) update(2*node, lo, mid, pos);

    else update(2*node+1, mid+1, hi, pos);



    H[node] = H[2*node] + H[2*node+1];

}





int main() {

    ifstream f("swap.in");

    ofstream g("swap.out");



    getline(f, a);

    getline(f, b);

    n = a.size();



    for(int i=0; i<n; i++)

        freq[0][a[i]]++, freq[1][b[i]]++;



    for(int i='a'; i<='z'; i++)

        if(freq[0][i] != freq[1][i]) {

            g<<"-1\n";

            return 0;

        }



    for(int letter='a'; letter<='z'; letter++) {

        for(int j=0, i=0; j<n; j++) {

            if(b[j] != letter) continue;

            while(a[i] != b[j]) i++;

            v[i++] = j;

        }

    }



    for(int i=0; i<n; i++)

        w.push_back(make_pair(v[i], i));



    sort(w.begin(), w.end());



    for(int i=0; i<n; i++) {

        inv = 0;

        query(1, 0, n-1, w[i].second, n-1);

        update(1, 0, n-1, w[i].second);

        sol += inv;

    }



    g<<sol<<"\n";





    return 0;

}
