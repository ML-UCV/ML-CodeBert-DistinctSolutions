#include <fstream>
#include <cstring>
#include <vector>


const int L_MAX = 2000000;



using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char P[L_MAX + 5], T[L_MAX + 5];

int lps[L_MAX + 5];

int cnt;



vector<int> pos;



int main() {

    fin >> (P + 1);

    P[0] = '\0';

    int sizeP = strlen(P + 1);



    lps[0] = lps[1] = 0;

    for (int i = 2; i <= sizeP; i++) {

        int x = lps[i - 1];

        while (x > 0 && P[x + 1] != P[i])

            x = lps[x];

        if(P[x + 1] == P[i])

            lps[i] = x + 1;

        else lps[i] = 0;



    }



    fin >> T;

    int sizeT = strlen(T);

    int x = 0;

    for (int i = 0; i < sizeT; i++) {

        while(x > 0 && P[x + 1] != T[i])

            x = lps[x];

        if (P[x + 1] == T[i])

            x++;

        else x = 0;



        if(x == sizeP) {

            cnt++;

            pos.push_back(i - x + 1);

        }

    }



    fout << cnt << '\n';

    for (int i = 0; i < min(cnt, 1000); i++)

        fout << pos[i] << ' ';

    return 0;

}
