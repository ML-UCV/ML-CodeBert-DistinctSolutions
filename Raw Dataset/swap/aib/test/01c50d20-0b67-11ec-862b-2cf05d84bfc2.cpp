#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

ifstream in("swap.in");

ofstream out("swap.out");

char sir1[50001], sir2[50001];

unsigned short hz[50001],hz2[50001],aib[50001];

unsigned int hashuri[27][50001];

int n;

void update_aib (int pozitie) {

    for (int i = pozitie; i <= n; i += (i&(-i))) {

        aib[i] ++;

    }

    return;

}

int query_aib(int pozitie) {

    int rezultat = 0;

    for (int i = n; i >= 1; i -=(i&(-i))) {

        rezultat += aib[i];

    }

    for (int i = pozitie; i >= 1; i -= (i&(-i))) {

        rezultat -= aib[i];

    }

    return rezultat;

}

int rezultat;

int main(void) {

    in >> sir1 + 1;

    in >> sir2 + 1;

    n = strlen(sir1+1);

    for (int i = 1; i <= n; i ++) {

        hz[sir1[i]-'a'+1] ++;

        hz2[sir2[i]-'a'+1]++;

        hashuri[sir1[i]-'a'+1][hz[sir1[i]-'a'+1]] = i;

    }

    for (int i = 1; i <= 26; i ++) {

        if (hz[i] != hz2[i]) {

            out<<-1;

            return 0;

        }

        hz2[i] = 0;

    }

    for (int i = 1; i <= n; i ++) {

        hz2[sir2[i]-'a'+1] ++;

        int x = hashuri[sir2[i]-'a'+1][hz2[sir2[i]-'a'+1]];

        update_aib (x);

        rezultat += query_aib(x);

    }

    out << rezultat;

    return 0;

}
