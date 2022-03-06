#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <stack>
#include <algorithm>
#include <stdexcept>
#include <map>
#include <cctype>
#include <cmath>



using namespace std;


long doOperation(char op, long left, long right) {

                 switch( op ) {

                        case '+': return left+right;
                        case '-': return left-right;
                        case '*': return left*right;
                        case '/': return (left/right);

                        default: {
                         return 0;
                        }

                 }
}


void computeNextInStack(stack<long> & numberStack, stack<char> & operatorStack) {

                char op = operatorStack.top();
                     operatorStack.pop();

                long right = numberStack.top();
                     numberStack.pop();

                long left = numberStack.top();
                     numberStack.pop();

                long result = doOperation(op, left, right);

                     numberStack.push( result );
}

unsigned int priority(char op) {

             switch( op ) {

                    case '+':
                    case '-':
                            return 1;
                    case '*':
                    case '/':
                            return 2;
                    default:
                            return 0;
             }
}


long parseExpression(string const expression) {

    stack<long> numberStack;
    stack<char> operatorStack;


    string::const_iterator pos = expression.begin();


    while(pos != expression.end()) {

               char current = *pos;

               switch(current) {

                      case '+':
                      case '-':
                      case '*':
                      case '/':

                      {

                        while(
                               !operatorStack.empty() &&

                               priority(operatorStack.top()) >= priority(current)
                             )

                               {
                                  computeNextInStack(numberStack, operatorStack);
                               }

                        operatorStack.push(current);

                        break;
                      }



                      case '(': {

                         operatorStack.push(current);

                         break;
                      }


                      case ')': {

                           if(operatorStack.empty()) {



                                      return 0;
                            }

                            while(operatorStack.top() != '(') {

                                  computeNextInStack(numberStack, operatorStack);


                                  if(operatorStack.empty()) {



                                      return 0;
                                  }
                            }

                             operatorStack.pop();
                         break;
                      }



                      default: {

                               if(isdigit(current)) {


                                    long number = 0;

                                    while( pos != expression.end() && isdigit(*pos)) {

                                     number *= 10;
                                     number += (*pos)-'0';
                                     pos++;

                                    }


                                    numberStack.push(static_cast<long>(number));

                                    pos--;

                               } else {

                               }

                         break;
                      }
               }

          pos++;
    }

    while(!operatorStack.empty()) {

          computeNextInStack(numberStack, operatorStack);
    }

    return numberStack.top();
}


int main(int argc, char const *argv[])
{

             ifstream fin("evaluare.in");
             ofstream fout("evaluare.out");

             string expression;

             getline(fin, expression);

             long result = parseExpression(expression);

             fout<<result<<endl;

             fin.close();
             fout.close();

 return 0;
}
