#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>




using namespace std;



ifstream cin("ctc.in");

ofstream cout("ctc.out");



vector<int> G[100002] , GT[100002] , CTC[100002];

int member_of_CTC[100002] , nr_CTC = 0;

int viz[100002];

stack <int> s;



int n , m;

void dfs1(int nod){

    viz[nod] = 1;

    int size_ = G[nod].size();

    int vecin ;



    for(int i = 0 ; i<size_ ; i++){

        vecin = G[nod][i];

        if(viz[vecin] == 0){

            dfs1(vecin);

        }

    }

    s.push(nod);

}

void dfs2(int nod){

    int vecin , size_ = GT[nod].size();

    CTC[nr_CTC].push_back(nod);

    member_of_CTC[nod] = nr_CTC;

    viz[nod] = 2;

    for(int i=0 ; i<size_ ; i++){

        vecin = GT[nod][i];

        if(viz[vecin] == 1)

            dfs2(vecin);

    }

}

int main()

{

    cin>>n>>m;

    int x , y , nod;

    while(m--){

        cin>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

    for(int i = 1 ; i<=n ; i++){

        if(!viz[i]) dfs1(i);

    }



    while(!s.empty()){

        nod = s.top();



       if(viz[nod]==1){

            nr_CTC ++;

            dfs2(nod);

        }

        s.pop();

    }

    cout<<nr_CTC<<'\n';

    for(int i = 1 ; i<=nr_CTC ; i++){

        for(int j = 0 ; j< CTC[i].size() ; j++){

            cout<<CTC[i][j]<<' ';

        }

        cout<<'\n';

    }

    return 0;

}
