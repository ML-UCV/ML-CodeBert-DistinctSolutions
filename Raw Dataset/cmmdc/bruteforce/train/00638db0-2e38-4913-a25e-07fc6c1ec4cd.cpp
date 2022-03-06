	#include <iostream>
#include <fstream>


using namespace std;



int main()

{

ifstream fisier_in("cmmdc.in");

ofstream fisier_out("cmmdc.out");

long a,b,maxim = 0;

fisier_in >> a;

fisier_in >> b;

fisier_in.close();

if(a < b){

    for(int i = 2 ; i <=a ;i++){

        if((a % i) == 0 && (b%i) == 0){

            maxim = i;

            }

        }

    }else{

        for(int i = 2 ; i <= b; i++){

                if((a % i) == 0 && (b%i)== 0){

                   maxim = i;

            }

        }

    }

fisier_out << maxim;

fisier_out.close();

    return 0;

}
