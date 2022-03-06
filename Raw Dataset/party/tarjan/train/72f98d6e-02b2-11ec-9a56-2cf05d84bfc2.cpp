#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");
int N, M;

bool Friends[102];

struct Relation {int type, x, y;};

Relation R[1002];

void read(){

    fin >> N >>M;

    for(int i = 1; i <= M; i++)

       fin >> R[i].x >> R[i].y >> R[i].type;



}

inline bool verifica(int i, bool a, bool b){



    if(R[i].type == 0) return a || b;



    if(R[i].type == 1) return a || !b;



    if(R[i].type == 2) return b || !a;



    if(R[i].type == 3) return a + b != 2;







}

int main(){

    read();



    srand(time(NULL));



    for(int i = 1; i <= N; i++)

        Friends[i] = true;

    int i;



    for(i = 1; i <= M; i++)

        if(!verifica(i, Friends[R[i].x] , Friends[R[i].y])){

            bool r = rand() % 2;

            if(r) Friends[R[i].y] = !Friends[R[i].y];

            else Friends[R[i].x] = !Friends[R[i].x];



            i = 0;

        }

     int Number_Friends = 0;

    for(int i = 1; i <= N; i++)

        if(Friends[i] == true)

            Number_Friends++;



    fout <<Number_Friends <<'\n';



    for(int i = 1; i <= N; i++)

        if(Friends[i] == true)

            fout << i <<'\n';



    return 0;

}
