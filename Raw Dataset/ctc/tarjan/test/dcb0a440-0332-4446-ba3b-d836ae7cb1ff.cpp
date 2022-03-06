#include <bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector<vector<int>> rez;

stack<int> s;



void CTC(int nod, int low[], int disc[],int onS[], vector<int> graf[])

{

    static int i=1;

    disc[nod]=i;

    low[nod]=i;

    i++;

    onS[nod]=1;

    s.push(nod);



    for(int it : graf[nod])

    {

        if(disc[it] == 0)

        {

            CTC(it, low, disc,onS,graf);

            low[nod]=min(low[nod],low[it]);

        }

        else if(onS[it] == 1)

        {

            low[nod]=min(low[nod],disc[it]);

        }

    }



    if(low[nod] == disc[nod])

    {

        vector<int> v;

        while(s.top()!=nod)

        {

            int x=s.top();

            cout<<x<<" ok ";

            s.pop();

            onS[x]=0;

            v.push_back(x);



        }



        s.pop();

        cout<<nod<<"\n";

        onS[nod]=0;

        v.push_back(nod);



        rez.push_back(v);

    }



}





int main()

{

    int n,m;

    fin>>n>>m;

    vector<int> graf[n+1];

    int low[n+1]= {0};

    int disc[n+1]= {0};

    for(auto i: disc) cout<<i<<" ";



    int onS[n+1]={0};





    while(m--)

    {

        int x,y;

        fin>>x>>y;

        graf[x].push_back(y);



    }



    for(int i=1; i<=n; i++)

    {

        if(disc[i] == 0)

            CTC(i,low,disc,onS,graf);

    }



    fout<<rez.size()<<"\n";

    for(auto comp:rez)

    {

        for(auto nod:comp)

            fout<<nod<<" ";

        fout<<"\n";

    }

    return 0;

}
