#include <fstream>
#include <cstring>
#include <deque>




using namespace std;



ifstream f("swap.in");

ofstream g("swap.out");



int n, v[50002], viz1[30], viz2[30], n2;



deque <int> viz[30];



long long s;



char sir1[50002], sir2[50002];



int aib[50002];



int query(int nod){

    int s = 0;

    for( ; nod >= 1; nod -= (nod & -nod))

        s += v[nod];

    return s;

}



void update(int nod){

    for( ; nod <= n; nod += (nod & -nod))

        ++ v[nod];

}



int main(){



    f>>sir1 + 1>>sir2 + 1;
    for(int i = 1; sir1[i] != 0; ++ i, ++ n)

        viz[sir1[i] - 'a' + 1].push_back(i);



    for(int i = 1; i <= n; ++ i){

        if(viz[sir2[i] - 'a' + 1].empty()){

            g<<-1;

            return 0;

        }

        int nod = viz[sir2[i] - 'a' + 1].front();

        viz[sir2[i] - 'a' + 1].pop_front();

        s += nod - query(nod) - 1;

        update(nod);

    }



    g<<s;



    return 0;

}
