#include <bits/stdc++.h>


using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

const int NMAX=30003;

int tree[4*NMAX],v[NMAX],ans[NMAX];

int n,poz,r;

void build_tree(int node,int left,int right){

    if(left==right){

        tree[node]=1;

        return ;

    }

    int mid=left+(right-left)/2;

    build_tree(node<<1,left,mid);

    build_tree(node<<1|1,mid+1,right);

    tree[node]=tree[node<<1]+tree[node<<1|1];

}

void querry(int node,int left,int right){

    if(left==right){

        ans[left]=r;

        tree[node]=0;

        return;

    }

    int mid=left+(right-left)/2;

    if(tree[node<<1]>=poz)

        querry(node<<1,left,mid);

    else

        poz-=tree[node<<1],querry(node<<1|1,mid+1,right);

    tree[node]=tree[node<<1]+tree[node<<1|1];

}

int main()

{

    in>>n;

    for(int i=1;i<=n;i++)

        in>>v[i];

    build_tree(1,1,n);

    for(int i=n;i>=1;i--){

        r=i;

        poz=v[i];

        querry(1,1,n);

    }

    for(int i=1;i<=n;i++)

        out<<ans[i]<<'\n';

    return 0;

}
