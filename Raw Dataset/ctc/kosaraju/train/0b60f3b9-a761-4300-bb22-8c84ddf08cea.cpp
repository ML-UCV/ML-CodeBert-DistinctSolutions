#include <fstream>
#include <vector>
#include <list>


using namespace std;

ifstream cin("ctc.in");

ofstream cout("ctc.out");

int N,M, vis1[100100], vis2[100100], mark;

vector <int> Ginit[100100], G_inv[100100];

inline void scan() {

    int x,y;

    cin>>N>>M;

    for(int i=1; i<=M; ++i) {

        cin>>x>>y;

        Ginit[x].push_back(y);

        G_inv[y].push_back(x);

    }

}

list <int> List;

inline void dfsmth(int x) {



    vis1[x]=1;

    for(auto it:Ginit[x])

        if(!vis1[it])

            dfsmth(it);

    List.push_back(x);

}



void dfmark(int x, int smth) {



    vis2[x]=smth;

    for(auto it: G_inv[x])

        if(!vis2[it])

            dfmark(it, smth);

}



vector <int> compcon[100100];

inline void print() {



    cout<<mark<<'\n';

    for(int i=1; i<=mark; ++i, cout<<'\n')

        for(int j=0; j<compcon[i].size(); ++j)

            cout<<compcon[i][j]<<' ';

}

int main()

{

    scan();



    for(int i=1; i<=N; ++i)

        if(!vis1[i])

            dfsmth(i);



    while(!List.empty()) {

        int el=List.back();

        if(!vis2[el])

            dfmark(el,++mark);

        List.pop_back();

    }



    for(int i=1; i<=N; ++i)

        compcon[vis2[i]].push_back(i);

    print();

    return 0;

}
