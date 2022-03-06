#include <fstream>
#include <cstring>
#include <vector>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int DIM = 2e6;



int N, M;

char p[DIM + 5], text[DIM + 5];



int pi[DIM + 5];

int ans;

vector <int> kmp;



void Pi()

{

    int j = 0;



    for(int i = 2; i <= N; i++) {



        while(p[i] != p[j + 1] && j != 0)

            j = pi[j];



        if(p[i] == p[j + 1])

            j++;



        pi[i] = j;



    }

}



void Kmp()

{

    int j = 0;



    for(int i = 1; i <= M; i++) {



        while(text[i] != p[j + 1] && j != 0)

            j = pi[j];



        if(text[i] == p[j + 1])

            j++;



        if(j == N) {



            ans++;

            if(kmp.size() < 1000)

                kmp.push_back(i - N);



            j = pi[j];

        }



    }

}



int main()

{

    fin >> (p + 1); N = strlen(p + 1);

    fin >> (text + 1); M = strlen(text + 1);



    Pi();



    Kmp();



    fout << ans << '\n';

    for(auto it : kmp)

        fout << it << ' ';



    return 0;

}
