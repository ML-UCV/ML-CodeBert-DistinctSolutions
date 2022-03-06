#include <fstream>
#include <stdlib.h>
using namespace std;

ifstream cin ("schi.in");

ofstream cout ("schi.out");

struct treap

{

    int value;

    int size;

    long long priority;



    treap* left;

    treap* right;

};

treap* emptytreap=new treap

{

    0,0,-1,NULL,NULL

};

bool find (treap* root, int value)

{

    if(root==emptytreap)

        return 0;

    else

    if(root->value == value)

        return 1;

    else

    if(root->value < value)

        return find(root->right,value);

    else

        return find(root->left,value);

}

treap* recomputetree (treap* root, treap* left, treap* right)

{

    root->left=left;

    root->right=right;

    root->size=1+left->size+right->size;

    return root;

}

pair <treap*,treap*> split (treap* root, int value)

{

    if(root == emptytreap)

        return make_pair(emptytreap,emptytreap);

    if(value < root->value)

    {

        pair<treap*,treap*> p=split(root->left,value);

        return make_pair(p.first,recomputetree(root,p.second,root->right));

    }

    else

    {

        pair<treap*,treap*>p=split(root->right,value);

        return make_pair(recomputetree(root,root->left,p.first),p.second);

    }

}

treap* join (treap* first, treap* second)

{

    if(first==emptytreap)

        return second;

    if(second==emptytreap)

        return first;

    if(first->priority > second->priority)

        return recomputetree(first,first->left,join(first->right,second));

    else

        return recomputetree(second,join(first,second->left),second->right);

}

treap* Insert (treap* root, treap* value)

{

    if(root == emptytreap)

        return value;

    if(root->priority<value->priority)

    {

        pair <treap*,treap*> p=split(root,value->value);

        return recomputetree(value,p.first,p.second);

    }

    if(root->value<value->value)

        return recomputetree(root,root->left,Insert(root->right,value));

    return recomputetree(root,Insert(root->left,value),root->right);

}

void insert (treap* &root, int val)

{

    treap* value = new treap

    {

        val,1,(rand()%10000000LL*(rand()%rand())%12346234LL+rand())%1000000000001LL,emptytreap,emptytreap

    };

    if(!find(root,val))

        root=Insert(root,value);

}

treap* Del (treap* root, int value)

{

    if(root==emptytreap)

        return emptytreap;

    if(root->value==value)

        return join(root->left,root->right);

    if(root->value<value)

        return recomputetree(root,root->left,Del(root->right,value));

    if(value<root->value)

        return recomputetree(root,Del(root->left,value),root->right);

}

void del (treap* & root, int val)

{

    if(find(root,val))

    root=Del(root,val);

}

int kth (treap* root, int k)

{

    if(root->left->size+1==k)

        return root->value;

    if(root->left->size+1>k)

        return kth(root->left,k);

    if(root->left->size+1<k)

        return kth(root->right,k-root->left->size-1);

}

int v[30003];

int rez[30003];

int main()

{

    treap* mytreap = emptytreap;

    int n,m,i,j;

    cin>>n;

    for(i=1;i<=n;++i)

    {

        cin>>v[i];

        insert(mytreap,i);

    }

    for(i=n;i>=1;--i)

    {

        int pz=kth(mytreap,v[i]);

        rez[pz]=i;

        del(mytreap,pz);

    }

    for(i=1;i<=n;++i)

        cout<<rez[i]<<'\n';

    return 0;

}
