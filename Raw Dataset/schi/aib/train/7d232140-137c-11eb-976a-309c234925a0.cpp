#include<fstream>
using namespace std;

    ifstream f("schi.in");

    ofstream g("schi.out");



const int dim = 30001;

long AIB[dim], n, v[dim], sol[dim];



inline long lowestTwo(long x)

{

    return x & (-x);

}



void update(long poz, long val)

{

    while(poz <= n){

        AIB[poz] += val;

        poz += lowestTwo(poz);

    }

}



long sum(long val)

{

    long result = 0 ;

    for(long i = val ; i >= 1 ; i-= lowestTwo(i)){

        result += AIB[i];

    }

    return result;

}



long binarySearch(long searchVal)

{

    long st = 1, dr = n;

    long val;



    while(st <= dr){

        long mij = (st + dr) / 2;

        long sumMij = sum(mij);



        if(sumMij == searchVal){

            val = mij;

            dr = mij - 1;

        }



        else if( sumMij < searchVal){

            st = mij + 1;

        }



        else{

            dr = mij - 1;

        }

    }



    return val;

}



int main()

{

    f>>n;



    for(long i = 1 ; i <= n ; i++){

        f>>v[i];

        update(i, 1);

    }



    for(long i = n ; i >= 1 ; i--){

        long poz = binarySearch(v[i]);

        sol[poz] = i;

        update(poz, -1);

    }



    for(long i = 1 ; i <= n ; i++){

        g<<sol[i]<<'\n';

    }



    return 0;

}
