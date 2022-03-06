#include <bits/stdc++.h>


using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");



namespace Treap{

    struct Node{

        Node *l=0,*r=0;

        int x=0;

        int y=0;

        int sz=0;

        Node(int _x=0): x(_x), y(rand()), sz(1) {}

        void recalc();

    };

    int cnt(Node* t){

        if(!t)return 0;

        return (t->sz);

    }

    void Node::recalc(){

        sz=cnt(l)+cnt(r)+1;

    }

    pair<Node*,Node*> split(Node* t,int k){

        if(!t)return {};

        t->recalc();

        if(cnt(t->l)>=k){

            auto pa=split(t->l,k);

            t->l=pa.second;

            t->recalc();

            return {pa.first,t};

        }else{

            auto pa=split(t->r,k-cnt(t->l)-1);

            t->r=pa.first;

            t->recalc();

            return {t,pa.second};

        }

        return {};

    }

    Node* join(Node *l,Node *r){

        if(!l)return r;

        if(!r)return l;

        l->recalc();

        r->recalc();

        if(l->y > r->y){

            l->r=join(l->r,r);

            l->recalc();

            return l;

        }else{

            r->l=join(l,r->l);

            r->recalc();

            return r;

        }

    }

    Node* insert(Node* t,int k,int e){

        auto pa=split(t,k-1);

        return join(pa.first,join(new Node(e),pa.second));

    }

    void output(Node *t){

        if(!t)return ;

        output(t->l);

        g<<(t->x)<<'\n';

        output(t->r);

        return ;

    }

}



int main()

{

    int n;f>>n;

    srand(time(0));

    Treap::Node *root=0;

    for(int i=1;i<=n;i++)

    {

        int x;f>>x;

        root=Treap::insert(root,x,i);

    }

    Treap::output(root);

    return 0;

}
