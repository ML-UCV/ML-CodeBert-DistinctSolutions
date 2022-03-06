#include <iostream>
#include <fstream>
using namespace std;

int locuri[30000];

int tree[120100];

int podium[30000];



void buildTree(int index, int left, int right) {



    if (left == right) {

        tree[index] = 1;

        return;

    }

    int mid = (left + right) / 2;

    buildTree(2 * index + 1, left, mid);

    buildTree(2 * index + 2, mid + 1, right);



    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];

}



void query(int index, int left, int right, int loc, int nr_concurent) {

    if (left == right) {

        tree[index] --;

        podium[left] = nr_concurent+1;

        return;

    }



    int mid = (left + right) / 2;



    if (tree[index * 2 + 1] >= loc)

        query(2 * index + 1, left, mid, loc, nr_concurent);

    else

        query(2 * index + 2, mid+1, right, loc - tree[index *2 +1] , nr_concurent);



    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];

}
int main()

{

    ifstream in("schi.in");

    ofstream out("schi.out");

    int n, x;

    in >> n;



    for (int i = 0; i < n; i++) {

        in >> x;

        locuri[i] = x;

    }



    buildTree(0, 0, n-1);



    for (int i = n - 1; i >= 0; i--) {

        query(0, 0, n - 1, locuri[i], i);

    }



    for (int i = 0; i < n; i++) {

        out << podium[i] << '\n';

    }





}
