#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <stack>
#include <deque>
#include <iomanip>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <list>
#include <iomanip>


using namespace std;



ifstream cin("party.in");

ofstream cout("party.out");



const int MAXN = 105;

const int oo = (1<<31)-1;



typedef vector<int> Graph[MAXN<<1];

typedef vector<int> :: iterator It;



const inline int min(const int &a, const int &b) { if( a > b ) return b; return a; }

const inline int max(const int &a, const int &b) { if( a < b ) return b; return a; }

const inline void Get_min(int &a, const int b) { if( a > b ) a = b; }

const inline void Get_max(int &a, const int b) { if( a < b ) a = b; }



Graph G;

int N, M, ans, Idx[MAXN<<1], LowLink[MAXN<<1], Deep, Ans[MAXN<<1];

vector< set<int> > SCComponent;

stack<int> Stack;

bitset<MAXN<<1> inStack;





struct ClassComp {

    inline bool operator () (const int &a, const int &b) const {

        return a > b;

    }

};



inline int Non(int x) {

    return x <= N ? x + N : x - N;

}



inline void Relation(int x, int y) {

    G[Non(x)].push_back(y);

    G[Non(y)].push_back(x);

}



inline void Tarjan(int Node) {

    Idx[Node] = LowLink[Node] = ++ Deep;

    Stack.push(Node);

    inStack[Node] = true;

    for(It it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it)

        if(!Idx[*it]) {

            Tarjan(*it);

            Get_min(LowLink[Node], LowLink[*it]);

        }

        else if(inStack[*it])

            Get_min(LowLink[Node], LowLink[*it]);

    if(Idx[Node] == LowLink[Node]) {

        int nod;

        set<int> ActSCC;

        do {

            ActSCC.insert(nod = Stack.top());

            Stack.pop();

            inStack[nod] = false;

        } while(nod != Node);

        SCComponent.push_back(ActSCC);

    }

}



int main() {
    cin >> N >> M;

    for(int i = 1 ; i <= M ; ++ i) {

        int x, y, z;

        cin >> x >> y >> z;

        if( 2 & z ) x = Non(x);

        if( 1 & z ) y = Non(y);

        G[Non(x)].push_back(y);

        G[Non(y)].push_back(x);



    }

    for(int i = 1 ; i <= 2 * N ; ++ i)

        if(!Idx[i])

            Tarjan(i);

    for(vector< set<int> > :: reverse_iterator it = SCComponent.rbegin() , fin = SCComponent.rend() ; it != fin ; ++ it)

    for(set<int> :: iterator i = it->begin(), fi = it->end(); i != fi ; ++ i) {

        int actNode = *i <= N ? *i : Non(*i);

        if(!Ans[actNode]) {

            Ans[actNode] = (*i > N) + 1;

            ans += (*i > N);

        }

        else break;

    }

    cout << ans << "\n";

    for(int i = 1 ; i <= N ; ++ i)

        if(Ans[i] == 2)

            cout << i << "\n";

    cin.close();

    cout.close();

    return 0;

}
