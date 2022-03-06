#include <fstream>


using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



int main()

{

    long long a = 0;

    int n = 0, nn;

    in >> a >> n;

    nn = n;

    int d = 2;

    long long p = 1;

    int fi = n;

    while(d*d<=n){

        if(n%d==0){

            fi = fi/d*(d-1);

            while(n%d==0){

                n/=d;

            }

        }

        d++;

    }

    if(n > 1){

        fi = fi/n*(n-1);

    }



    n = nn;

    fi--;

    p = 1;

    while(fi!=0){

        if(fi%2!=0){

            p = p * a % n;

        }

        fi/=2;

        a = a * a % n;

    }

    out << p;

}
