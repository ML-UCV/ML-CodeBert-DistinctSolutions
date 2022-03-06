#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;







ifstream f("swap.in");

ofstream g("swap.out");



string a, b;

queue<int> q[200];

int aib[50005], rez;

int ap_a[200], ap_b[200];

typedef struct{

    int val, poz;

}camp;

camp v[50005];



bool cmp(camp a, camp b){



    return a.val > b.val;



}



void citeste(){



    f >> a;

    f >> b;



}



int query(int poz){



    int sum = 0;



    int bit = 0;



    for(; poz; ){

        sum += aib[poz];

        while( (poz & (1<<bit))==0 ) ++bit;

        poz -= (1<<bit);

        ++bit;

    }



    return sum;



}



void udpate(int poz, int val){



    int bit = 0;



    for(; poz<=a.size();){

        aib[poz] += val;

        while( (poz & (1<<bit))==0 ) ++bit;

        poz += (1<<bit);

        ++bit;

    }



}



void rezolva(){



    for(int i=0; i<b.size(); i++){

        ++ap_b[b[i]];



        q[b[i]].push(i);

    }



    for(int i=0; i<a.size(); i++){

        ++ap_a[a[i]];

    }



    for(int i='a'; i<='z'; i++){

        if (ap_a[i] != ap_b[i]){

            g << "-1" << "\n";

            return;

        }

    }



    for(int i=0; i<a.size(); i++){

        v[i+1].val = q[a[i]].front();

        v[i+1].poz = i+1;

        q[a[i]].pop();

    }







    sort(v+1, v+a.size()+1, cmp);



    for(int i=1; i<=a.size(); i++){

        rez += query(v[i].poz) - query(0);

        udpate(v[i].poz, 1);

    }



    g << rez << "\n";

    cout << rez << "\n";



}



int main(){



    citeste();

    rezolva();



    f.close();

    g.close();



    return 0;



}
