#include <iostream>
#include <fstream>
using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



int n, arr[100005];

long long cnt;



void interclasare(int st1, int dr1, int st2, int dr2){



    int i = st1;

    int j = st2;



    int k = 0;



    int * auxarr = new int[dr1 - st1 + dr2 - st2 + 5];



    while(i <= dr1 && j <= dr2){



        if(arr[i] <= arr[j]){



            auxarr[k] = arr[i];

            i += 1;

        }

        else{



            cnt+= dr1 - i + 1;

            cnt %= 9917;



            auxarr[k] = arr[j];

            j += 1;

        }

        k += 1;

    }



    while(i <= dr1){



        auxarr[k] = arr[i];

        i += 1;

        k += 1;

    }



    while(j <= dr2){



        auxarr[k] = arr[j];

        j += 1;

        k += 1;

    }



    for(int i = 0; i < k; i++)

        arr[st1 + i] = auxarr[i];



    delete[] auxarr;

}



void mergesort(int st, int dr){



    if(st >= dr)

        return;



    int m = (st + dr) / 2;



    mergesort(st, m);

    mergesort(m + 1, dr);



    interclasare(st, m, m + 1, dr);

}





int main(){



    f>>n;



    for(int i = 0; i < n; i++)

        f>>arr[i];



    mergesort(0, n - 1);



    g<<cnt % 9917;



    return 0;

}
