#include<fstream>
#include<iostream>
       







using namespace std;
ifstream fin("schi.in");

ofstream fout("schi.out");





int arbint[120000], v[30001], locuriFinale[30001];



void build(int nod, int st, int dr) {

 if (st == dr) {

  arbint[nod] = 1;

  return;

 }

 int mid = st + (dr - st) / 2;

 build(2 * nod, st, mid);

 build(2 * nod + 1, mid + 1, dr);



 arbint[nod] = arbint[2 * nod] + arbint[2 * nod + 1];

}



void update(int nod, int st, int dr, int poz) {

 if (st == dr) {

  arbint[nod] = 0;

  return;

 }

 int mid = st + (dr - st) / 2;



 if (poz <= mid)

  update(2 * nod, st, mid, poz);

 else

  update(2 * nod + 1, mid + 1, dr, poz);



 arbint[nod] = arbint[2 * nod] + arbint[2 * nod + 1];

}



int queryPozitieFinala(int nod, int st, int dr, int locConcurs) {

 if (st == dr) {

  return st;

 }

 int mid = st + (dr - st) / 2;



 if (arbint[2 * nod] >= locConcurs) {

  return queryPozitieFinala(2 * nod, st, mid, locConcurs);

 }

 else {

  return queryPozitieFinala(2 * nod + 1, mid + 1, dr, locConcurs - arbint[2 * nod]);

 }

}
int main() {

 int nr,locFinal;

 fin >> nr;

 for (int i = 1; i <= nr; i++)

  fin >> v[i];

 build(1, 1, nr);



 for (int i = nr; i >= 1; i--) {

  locFinal = queryPozitieFinala(1, 1, nr, v[i]);

  locuriFinale[locFinal] = i;

  update(1, 1, nr, locFinal);

 }



 for (int i = 1; i <= nr; i++)

  fout << locuriFinale[i] << "\n";

 return 0;

}
