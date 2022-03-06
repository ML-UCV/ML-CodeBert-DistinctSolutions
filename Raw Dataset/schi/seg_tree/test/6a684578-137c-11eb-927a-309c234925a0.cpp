#include <bits/stdc++.h>
std::ifstream fin("schi.in");
std::ofstream fout("schi.out");

const int N = 30001;
int n, tree[4 * N], v[N], res[N];



void build(int node, int left, int right)
{
    if(left == right)
    {
        tree[node] = 1;
        return;
    }
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


void update(int node, int left, int right, int index, int val)
{
    if(left == right)
    {
        tree[node] = 0;
        res[right] = val;
        return;
    }
    int mid = (left + right) / 2;

    if(tree[node * 2] >= index)
        update(node * 2 , left, mid, index, val);
    else
        update(node * 2 + 1, mid + 1, right, index - tree[node * 2], val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}


int main()
{
    int i;
    fin >> n;
    for(i = 0; i < n; i++)
        fin >> v[i];
    build(1, 0, n - 1);

    for(i = n - 1; i >= 0; i--)
        update(1, 0, n - 1, v[i], i + 1);

    for(i = 0; i < n; i++)
        fout << res[i] << '\n';




    return 0;
}
