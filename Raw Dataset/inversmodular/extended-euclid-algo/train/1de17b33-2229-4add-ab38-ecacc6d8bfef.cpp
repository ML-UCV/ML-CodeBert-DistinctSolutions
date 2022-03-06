#include <iostream>
#include <fstream>


using namespace std;



ifstream fin ("inversmodular.in");

ofstream fout ("inversmodular.out");



int euclid (int a, int b, int &x, int &y)

{

    if(b==0)

    {

        x=1;

        y=0;

    }



    else

    {

        int x1, y1;



        euclid(b, a%b, x1, y1);

        x=y1;

        y=x1-a/b*y1;

    }

}





int main()

{

    int a, n, x, y;



    fin>>a>>n;



    euclid (a, n, x, y);



    while(x>0)

    {

        x=x-n;

    }



    while(x<0)

    {

        x=x+n;

    }



    fout<<x;

}
