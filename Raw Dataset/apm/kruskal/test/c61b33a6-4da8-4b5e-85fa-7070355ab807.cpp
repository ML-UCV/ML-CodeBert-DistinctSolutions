#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>


using namespace std;



typedef struct PAIR{



    int muchieX, muchieY, costMuchie;



}PAIR;



PAIR P;



ifstream fin("apm.in");

ofstream fout("apm.out");



int nrNoduri, nrMuchii, costArborePartial, nrMuchiiArborePartial, *vectorTati, *rang;

vector <PAIR> muchii;

bool *vizitatMuchii;



int Radacina(int nod){



    int radacinaNod = nod;



    while ( vectorTati[radacinaNod] != radacinaNod )

                radacinaNod = vectorTati[radacinaNod];



    while ( vectorTati[nod] != nod ){

         int aux = vectorTati[nod];

         vectorTati[nod] = radacinaNod;

         nod = aux;

    }



    return radacinaNod;



}



void Unire(int radacinaX, int radacinaY){



    if ( radacinaX != radacinaY ){



            if(rang[radacinaX] > rang[radacinaY])

                        vectorTati[radacinaY] = radacinaX;



            else

                vectorTati[radacinaX] = radacinaY;





            if( rang[radacinaX] == rang[radacinaY] )

                                    rang[radacinaY]++;

    }



}



int cmp(PAIR X, PAIR Y){



    return X.costMuchie < Y.costMuchie;



}



void kruskal(){



    int nrComponenteConexe = nrNoduri;



    for ( int i = 1; i <= nrNoduri; i++){

                    vectorTati[i] = i;

                    rang[i] = 1;

    }



    costArborePartial = 0 , nrMuchiiArborePartial = 0;



    int lim = muchii.size();



    for(int i = 0; i < lim && nrComponenteConexe > 1 ; i++){



        int radacinaX = Radacina(muchii[i].muchieX) , radacinaY = Radacina(muchii[i].muchieY);



  if ( radacinaX != radacinaY ){



   vizitatMuchii[i] = true;



   costArborePartial += muchii[i].costMuchie;

   nrMuchiiArborePartial++;



            Unire(radacinaX,radacinaY);



            nrComponenteConexe--;

  }

    }

}



int main(){



    if ( !fin ){

        cout << "\nEroare la deschiderea fisierului !\n";

        exit(-1);

    }



    fin >> nrNoduri;



    vectorTati = NULL;



    vectorTati = new int[nrNoduri + 5];

    rang = new int[nrNoduri + 5];



    if (!vectorTati || !rang){

        cout << "\nEroare la alocarea dinamica !\n";

        exit(-1);

    }



     fin >> nrMuchii;



     vizitatMuchii = new bool[nrMuchii + 5];



     if (!vizitatMuchii){

         cout << "\nEroare la alocarea dinamica !\n";

         exit(-1);

     }



     for (int i = 0; i < nrMuchii; i++) {



        fin >> P.muchieX >> P.muchieY >> P.costMuchie;



        muchii.push_back(P);



        vizitatMuchii[i] = false;



     }



     sort(muchii.begin(),muchii.end(),cmp);



     kruskal();



     fout << costArborePartial << "\n" << nrMuchiiArborePartial << "\n";



     for ( int i = 0; i < nrMuchii; i++)

           if ( vizitatMuchii[i] )

                    fout << muchii[i].muchieX << " " << muchii[i].muchieY <<"\n";





    return 0;



}
