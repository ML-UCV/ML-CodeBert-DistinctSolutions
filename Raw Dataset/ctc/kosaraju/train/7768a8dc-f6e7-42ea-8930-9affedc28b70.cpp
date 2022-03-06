#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector<int> A[100005],TA[100005],CTC[100005];

stack<int> S;



int N,M,cate_conexe;



int VIZ[100005],TVIZ[100005];



void df (int x)

{

    VIZ[x]=1;

    vector<int> :: iterator it;

    for (it=A[x].begin();it!=A[x].end();++it)

    {

        int val=(*it);

        if (VIZ[val]==0)

        {

            df(val);

        }

    }

    S.push(x);

}



void tdf (int x)

{

    TVIZ[x]=1;

    CTC[cate_conexe].push_back(x);

    vector<int> :: iterator it;

    for (it=TA[x].begin();it!=TA[x].end();++it)

    {

        int val=(*it);

        if (TVIZ[val]==0)

        {

            tdf(val);

        }

    }

}



int main()

{

    fin >> N >> M;

    int a,b,i;

    for (i=1;i<=M;++i)

    {

        fin >> a >> b;

        A[a].push_back(b);

        TA[b].push_back(a);

    }

    for (i=1;i<=N;++i)

    {

        if (VIZ[i]==0)

        {

            df(i);

        }

    }
    while (!S.empty())

    {

        i=S.top();

        S.pop();

        if (TVIZ[i]==0)

        {

            ++cate_conexe;

            tdf(i);

        }

    }

    fout << cate_conexe << '\n';

    for (i=1;i<=cate_conexe;++i)

    {

        vector<int> :: iterator it;

        for (it=CTC[i].begin();it!=CTC[i].end();++it)

        {

            int val=(*it);

            fout << val << " ";

        }

        fout << '\n';

    }

    fin.close();

    fout.close();

    return 0;

}
