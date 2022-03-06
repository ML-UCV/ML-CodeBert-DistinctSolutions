#include <iostream>
#include <fstream>


const int MAX_N = 3e4 + 1;

int arr[MAX_N], final_order[MAX_N], tree[4 * MAX_N];

void build(int node, int left, int right)
{
    if (left == right) {
        tree[node] = 1;
        return;
    }

    int mid = (left + right) >> 1;

    build(node * 2, left, mid);

    build(node * 2 + 1, mid + 1, right);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int left, int right, int position, int value_schior)
{
    if (left == right) {
        tree[node] = 0;
        final_order[left] = value_schior;
        return;
    }

    int mid = (left + right) / 2;

    if (tree[node * 2] >= position) {
        update(node * 2 , left, mid, position, value_schior);
    }
    else {
        update(node * 2 + 1, mid + 1, right, position - tree[node * 2], value_schior);
    }

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}





int main()
{
    std::ifstream fin("schi.in");
    std::ofstream fout("schi.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }

    build(1, 0, n - 1);

    for (int i = n - 1; i >= 0; i--) {
        update(1, 0, n - 1, arr[i], i + 1);
    }

    for (int i = 0; i < n; i++) {
        fout << final_order[i] << '\n';
    }

    return 0;
}
