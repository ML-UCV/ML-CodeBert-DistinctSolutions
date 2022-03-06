#include <fstream>
#include <deque>
#include <cstring>


using namespace std;

int len,h,n;

char ch[50005];

int a[50005];

deque <int> dq[28];







void add(int pos,int val){

    for(;pos<=len;pos+=pos&-pos) a[pos] += val;

}

int query(int pos){

    int sum = 0;

    for(;pos;pos-=pos&-pos) sum += a[pos];

    return sum;

}





int main()

{

    ifstream f("swap.in");

    ofstream g("swap.out");



    f >> ch;

    len = strlen(ch), h = 0;

    for(int i=0; i < len; ++i){

        dq[ ch[i] - 'a' ] . push_back( ++h );

        add( h , 1 );

    }

    int sum = 0;

    n = len;

    f >> ch;

    len = strlen(ch);



    if( len != n ){

        g << "-1";

        return 0;

    }



    for(int i=0;i<len;++i){

        if( dq[ ch[i]- 'a' ].empty() ) {

            g << "-1";

            return 0;

        }

        n = dq[ ch[i] - 'a' ].front();

            dq[ ch[i] - 'a' ].pop_front();

        sum += query(n) -1;

        add(n,-1);

    }

    g << sum;



    return 0;

}
