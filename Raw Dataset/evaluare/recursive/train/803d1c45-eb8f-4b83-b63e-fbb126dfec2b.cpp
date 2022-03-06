    #include <fstream>
    #include <iostream>
using namespace std;
    ifstream in("evaluare" ".in");

    ofstream out("evaluare" ".out");
int col;

char expr[100000];







inline bool numeric_chr(char chr) {return '0' <= chr && chr <= '9';}

inline bool paran_chr(char chr) {return chr == '(';}

inline bool operator_de_grad_1_chr(char chr) {return chr == '*' || chr == '/';}

inline bool operator_de_grad_0_chr(char chr) {return chr == '+' || chr == '-';}







int numar() {



    int rt = 0;



    while (numeric_chr(expr[col])) {



        rt *= 10;

        rt += expr[col] - '0';



        col++;



    }



    return rt;



}







int expresie();



int paran_sau_nr() {



    if (paran_chr(expr[col])) {



        col++;



        int rt = expresie();



        col++;



        return rt;



    } else {



        return numar();



    }



}







int grad_1() {



    int rt = paran_sau_nr();



    while (operator_de_grad_1_chr(expr[col])) {



        col++;



        if (expr[col - 1] == '*') {



            rt *= paran_sau_nr();



        } else {



            rt /= paran_sau_nr();



        }



    }



    return rt;



}







int expresie() {



    int rt = grad_1();



    while (operator_de_grad_0_chr(expr[col])) {



        col++;



        if (expr[col - 1] == '+') {



            rt += grad_1();



        } else {



            rt -= grad_1();



        }



    }



    return rt;



}







int main() {



    in >> expr;



    out << expresie();



}
