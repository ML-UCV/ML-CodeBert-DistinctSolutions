#include <iostream>
#include <fstream>


using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



string s;

int i;



int f1();

int f2();

int f3();





int f1(){

    int raspuns = f2();

    while(s[i] == '+' || s[i] == '-'){

        if(s[i] == '+'){

            i++;

            raspuns += f2();

        }else{

            i++;

            raspuns -= f2();

        }

    }

    return raspuns;

}

int f2(){

    int raspuns = f3();

    while(s[i] == '*' || s[i] == '/'){

        if(s[i] == '*'){

            i++;

            raspuns *= f3();

        }else{

            i++;

            raspuns /= f3();

        }

    }

    return raspuns;

}



int f3(){

    int raspuns = 0;

    if(s[i] == '('){

        i++;

        raspuns = f1();

        i++;

    }else{

        while(isdigit(s[i])){

            raspuns = raspuns * 10 + s[i] - '0';

            i++;

        }

    }

    return raspuns;

}



int main()

{

    in>>s;

    out<<f1();

    return 0;

}
