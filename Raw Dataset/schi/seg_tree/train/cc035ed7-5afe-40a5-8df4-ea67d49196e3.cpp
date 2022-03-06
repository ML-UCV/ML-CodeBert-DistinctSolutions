#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

ifstream fin("schi.in");
ofstream fout("schi.out");

const int N = 30000;

int arb[4*N];
int ord[N + 1], available[N + 1], sol[N + 1];

void uniteNodes(int parent, int leftChild, int rightChild){
    arb[parent] = arb[leftChild] + arb[rightChild];
}

void build(int node, int left, int right){
    if(left == right){
        arb[node] = available[left] = 1;
        return;
    }
    int mij = (left + right)/2;
    build(2*node, left, mij);
    build(2*node + 1, mij + 1, right);
    uniteNodes(node, 2*node, 2*node + 1);
}

void update(int node, int left, int right, int index, int val){
    if(left == right){
        sol[left] = val;
        available[left] = 0;
        arb[node] = 0;
        return;
    }
    int mij = (left + right)/2;
    if(index <= arb[2*node])
        update(2*node, left, mij, index, val);
    else
        update(2*node + 1, mij + 1, right, index - arb[2*node], val);
    uniteNodes(node, 2*node, 2*node + 1);
}

int main()
{
    int n,i;
    fin >> n;
    for(i=1; i<=n; i++)
        fin >> ord[i];
    build(1, 1, n);
    for(i=n; i>=1; i--)
        update(1, 1, n, ord[i], i);
    for(i=1; i<=n; i++)
        fout << sol[i] << "\n";
    return 0;
}
