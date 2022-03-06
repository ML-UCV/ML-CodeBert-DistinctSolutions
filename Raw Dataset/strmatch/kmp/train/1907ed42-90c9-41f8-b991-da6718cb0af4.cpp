#include <fstream>
#include <cstring>
using namespace std;



char subsir[2000003], sir[2000003];

int nextState[2000003], matchPos[2000003];



void build_finite_automata(char *s, int n)

{

    nextState[0] = nextState[1] = 0;



    for (int i = 1, state = 0; i < n; ++i) {

        while (0 < state && s[state] != s[i]) {

            state = nextState[state];

        }



        if (s[state] == s[i]) {

            state++;

        }



        nextState[i+1] = state;

    }

}



int kmp_match(char *subsir, int n, char *sir, int m)

{

    int numMatch = 0;



    for (int i = 0, state = 0; i < m; ++i) {

        while (0 < state && subsir[state] != sir[i]) {

            state = nextState[state];

        }



        if (subsir[state] == sir[i]) {

            state++;

        }



        if (state == n) {

            if (numMatch < 1000) {

                matchPos[numMatch] = i-n+1;

            }

            numMatch++;

            state = nextState[state];

        }

    }



    return numMatch;

}



int main()

{

    ifstream f("strmatch.in");

    ofstream g("strmatch.out");



    f.getline(subsir, 2000003);

    f.getline(sir, 2000003);



    int n = strlen(subsir);

    int m = strlen(sir);



    build_finite_automata(subsir, n);

    int numMatch = kmp_match(subsir, n, sir, m);



    g << numMatch << "\n";



    numMatch = (1000 < numMatch) ? 1000 : numMatch;

    for (int i = 0; i < numMatch; ++i) {

        g << matchPos[i] << " ";

    }



    f.close();

    g.close();



    return 0;

}
