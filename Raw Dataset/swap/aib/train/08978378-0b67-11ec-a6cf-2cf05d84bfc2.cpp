#include <fstream>
#include <cstring>






using namespace std;



ifstream f("swap.in");

ofstream g("swap.out");



int mat[30][50005] , aib[50005] , nr[30] , c1[30] , c2[30];

int sol , n;



char sir1[50005] , sir2[50005];



void update(int poz , int val) {

    while(poz <= n) {

        aib[poz] += val;

        poz += poz & (poz ^ (poz - 1));

    }

}



int query(int poz) {

    int sum = 0;

    while(poz >= 1) {

        sum += aib[poz];

        poz -= poz & (poz ^ (poz - 1));

    }



    return sum ;

}



int main() {

    f >> sir1 + 1 >> sir2 + 1;



    n = strlen(sir1 + 1);

    for(int i = 1 ; i <= n ; ++i) {

        mat[sir1[i] - 'a'][++mat[sir1[i] - 'a'][0]] = i;

        ++c1[sir1[i] - 'a'];

        ++c2[sir2[i] - 'a'];

    }



    for(char ch = 'a' ; ch <= 'z' ; ++ch) {

        if(c1[ch - 'a'] != c2[ch - 'a']) {

            g << -1;

            return 0;

        }

    }



    for(int i = 1 ; i <= n ; ++i) {

        sol += mat[sir2[i] - 'a'][++nr[sir2[i] - 'a']] - 1 - query(mat[sir2[i] - 'a'][nr[sir2[i] - 'a']] - 1);

        update(mat[sir2[i] - 'a'][nr[sir2[i] - 'a']] , 1);

    }



    g << sol;

    return 0;

}
