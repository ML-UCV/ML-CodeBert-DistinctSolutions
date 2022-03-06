#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


ifstream fin;
ofstream fout;

int n, i, j, m;

int current_sum, last_sum, aux;

vector <int> BITREE(30002 , 0);
vector <int> players(30002);
vector <int> results(30002);

inline int least_significant_bit (int value){
    return ((value ^ (value - 1)) & value);
}

void update (int index, int val){
    for (int ind = index; ind <= n; ind += least_significant_bit(ind))
        BITREE[ind] += val;

}

int get_sum (int index){
    int sum = 0;

    for (int ind = index; ind > 0; ind -= least_significant_bit(ind))
        sum += BITREE[ind];

    return sum;
}

int main (void){
    fin.open("schi.in");
    fin>>n;
    for (i=1; i <= n; i++)
        fin>>players[i];
    fin.close();

    for (i=n; i>0; i--){
        current_sum = get_sum(players[i]);
        last_sum = 0;

        while (current_sum - last_sum) {
            last_sum = current_sum;
            current_sum = get_sum(players[i] + current_sum);
        }
        aux = players[i] + current_sum;

        results[aux] = i;

        update(aux , 1);
        }

    fout.open("schi.out");
    for (i=1; i<=n; i++)
        fout<<results[i]<<"\n";
    fout.close();

    return 0;
}
