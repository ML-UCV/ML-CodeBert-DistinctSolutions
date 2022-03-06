#include <iostream>
#include <fstream>


using namespace std;



int main()

{

    int a,b;

    ifstream fin("cmmdc.in");

    ofstream fout("cmmdc.out");



    fin >> a >> b;

    for(int i = min(a,b);i > 0;i--){

        if(a % i == 0 && b % i == 0){

            if(i == 1){

                fout << 0;

                break;

            }

            else{

                fout << i;

                break;

            }

        }

    }

    return 0;

}
