#include <bits/stdc++.h>


const int MV = 1e5 ;



class Expression {

private:

        char *exp ;

        int point ;

public :

        Expression(char S[]) {

                exp = S ;

                point = 0 ;

        }

        char current() { return exp[point] ; }

        __attribute__ ( (always_inline)) void advance() { point ++ ; }



        int evaluate() {

                int currVal = termen() ;

                for ( ; current() == '+' || current() == '-' ; ) {

                        if (current() == '+') {

                                advance() ;

                                currVal += termen() ;

                        } else {

                                advance() ;

                                currVal -= termen() ;

                        }

                }

                return currVal ;

        }



        int termen() {

                int currVal = factor() ;

                for ( ; current() == '*' || current() == '/' ; ) {

                        if (current() == '*') {

                                advance() ;

                                currVal *= factor() ;

                        } else {

                                advance() ;

                                currVal /= factor() ;

                        }

                }

                return currVal ;

        }



        int factor() {

                int currVal(0) ;

                if (current() == '(') {

                        advance() ;

                        currVal += evaluate() ;

                        advance() ;

                } else {

                        for ( ; isdigit(current()) ; advance()) {

                                currVal = currVal * ((1 << 3) + (1 << 1)) + (current() - '0') ;

                        }

                }

                return currVal ;

        }



};



std::fstream in ("evaluare.in", std::ios::in) ;

std::fstream out ("evaluare.out", std::ios::out) ;



int main() {

        char S[MV + 5] ;

        in >> S ;

        Expression expresie(S) ;

        int answer = expresie.evaluate() ;

        out << answer ;

}
