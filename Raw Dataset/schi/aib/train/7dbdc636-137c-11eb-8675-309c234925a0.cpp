#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int N;

vector<int> input, output;



struct FenwickTree {

    vector<int> ft;

    int ft_size;



    FenwickTree(int n) {

        ft.resize(n, 0);

        ft_size = n;

    }



    int rsq(int x) {

        int sum = 0;

        for (; x; x -= (x & (-x))) sum += ft[x];

        return sum;

    }



    void adjust(int k, int v) {

        for (; k < ft_size; k += (k & (-k))) ft[k] += v;

    }

};



void Read() {

    fin >> N;

    input.resize(N + 1);

    output.resize(N + 1);

    for (int i = 1; i <= N; ++i)

        fin >> input[i];

}



int lower_bound(FenwickTree &ft, int v) {

    int left = 1, right = ft.ft_size;



    while (left <= right) {

        int middle = (left + right) / 2;



        int middle_rsq = ft.rsq(middle);



        if (middle_rsq < v)

            left = middle + 1;

        else right = middle - 1;

    }



    return left;

}



void Solve() {

    FenwickTree ft(N + 1);



    for (int i = 1; i <= N; ++i) {

        ft.adjust(i, 1);

    }



    for (int i = N; i >= 1; --i) {

        int current_place = lower_bound(ft, input[i]);

        output[current_place] = i;

        ft.adjust(current_place, -1);

    }

}



void Print() {

    for (int i = 1; i <= N; ++i)

        fout << output[i] << "\n";

}



int main()

{

    Read();

    Solve();

    Print();

    return 0;

}
