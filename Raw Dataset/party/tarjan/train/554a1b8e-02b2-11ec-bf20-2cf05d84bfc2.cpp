#include <fstream>
#include <vector>


using namespace std;

ifstream fin("party.in");
ofstream fout("party.out");

int N, M, i, j, A, B, neg[205], CVAL[205];
int comp[205], SortTOP[205], K, grad[205];
int top, st[205], op, NR, CNEG[205];
bool ok[205];
vector <int> G[205], Ginv[205], CG[205], SOL;
vector <int> :: iterator it;

void VISIT(int nod)
{
    vector <int> :: iterator it;
    ok[nod]=true;
    for (it=G[nod].begin(); it!=G[nod].end(); it++)
        if (ok[*it]==false)
            VISIT(*it);
    st[++top]=nod;
}

void ASSIGN_NODE(int nod)
{
    vector <int> :: iterator it;
    comp[nod]=K;
    for (it=Ginv[nod].begin(); it!=Ginv[nod].end(); it++)
        if (comp[*it]==0)
            ASSIGN_NODE(*it);
}

int main()
{
    fin >> N >> M;
    for (i=1; i<=2*N; i++)
    {
        if (i<=N)
            neg[i]=i+N;
        else
            neg[i]=i-N;
    }
    for (i=1; i<=M; i++)
    {
        fin >> A >> B >> op;
        if (op>1)
            A=neg[A];
        if (op % 2==1)
            B=neg[B];
        G[neg[A]].push_back(B);
        G[neg[B]].push_back(A);
        Ginv[A].push_back(neg[B]);
        Ginv[B].push_back(neg[A]);
    }
    for (i=1; i<=2*N; i++)
        if (ok[i]==false)
            VISIT(i);
    while (top>0)
    {
        if (comp[st[top]]==0)
        {
            K++;
            ASSIGN_NODE(st[top]);
        }
        top--;
    }
    for (i=1; i<=2*N; i++)
    {
        CNEG[comp[i]]=comp[neg[i]];
        for (it=G[i].begin(); it!=G[i].end(); it++)
        {
            if (comp[i]!=comp[*it])
            {
                CG[comp[i]].push_back(comp[*it]);
                grad[comp[*it]]++;
            }
        }
    }
    for (i=1; i<=K; i++)
        if (grad[i]==0)
            SortTOP[++NR]=i;
    for (i=1; i<=K; i++)
    {
        A=SortTOP[i];
        CVAL[i]=-1;
        for (it=CG[A].begin(); it!=CG[A].end(); it++)
        {
            grad[*it]--;
            if (grad[*it]==0)
                SortTOP[++NR]=*it;
        }
    }
    for (i=1; i<=K; i++)
    {
        if (CVAL[i]==-1)
        {
            CVAL[i]=0;
            CVAL[CNEG[i]]=1;
        }
    }
    for (i=1; i<=N; i++)
        if (CVAL[comp[i]]==1)
            SOL.push_back(i);
    fout << SOL.size() << '\n';
    for (it=SOL.begin(); it!=SOL.end(); it++)
        fout << *it << '\n';
    fin.close();
    fout.close();
    return 0;
}
