#include <iostream>
#include <fstream>
#include <queue>




using namespace std;



ifstream in("swap.in");

ofstream out("swap.out");



char s1[50003];

char s2[50003];

int pr[50003];

long long aib[50003];

queue<int> cr[30];

int i;

int ln;



inline void update(int val) {

    for(int i = val; i <= ln; i += i&-i)

        aib[i]++;

}



inline long long query(int val) {

    long long rez = 0;

    for(int i = val; i > 0; i -= i&-i) {

        rez += aib[i];

    }

    return rez;

}



int main() {



    in.getline(s1, 50003);

    in.getline(s2, 50003);



    for(i = 0; s2[i]; i++)

        cr[s2[i]-'a'].push(i);



    for(i = 0; s1[i]; i++) {

        if(cr[s1[i]-'a'].empty()) {

            out << "-1";

            return 0;

        }

        pr[i] = cr[s1[i]-'a'].front()+1;

        cr[s1[i]-'a'].pop();

    }



    ln = i;



    for(i = 0; i < 30; i++) {

        if(!cr[i].empty()) {

            out << "-1";

            return 0;

        }

    }



    long long rez = 0;



    for(i = ln-1; i >= 0; i--) {

        rez += query(pr[i]);

        update(pr[i]);

    }



    out << rez;



    return 0;

}
