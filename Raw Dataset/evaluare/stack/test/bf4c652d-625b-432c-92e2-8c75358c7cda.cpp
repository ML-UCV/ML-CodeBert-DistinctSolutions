#include <fstream>
#include <string>
#include <stack>
using namespace std;



struct operation{

    char operation;

    int priority;

};



int main(){



    iostream::sync_with_stdio(false);

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");



    int result = 0, currentOperandPriority, currentExpressionPriority = 0, currentNumber = 0;

    operation currentOp;

    string input;



    getline(fin, input);



    stack <int> stackNumbers;

    stack <char> stackDigits;

    stack <operation> stackOperators;



    bool newNumber;



    for(int i = input.length() - 1; i >= 0; i--)



        if(input[i] <= '9' && input[i] >= '0')

            stackDigits.push(input[i]);



        else{



            currentNumber = 0;

            newNumber = false;



            while(!stackDigits.empty()){

                newNumber = true;

                currentNumber = currentNumber*10 + stackDigits.top() - '0';

                stackDigits.pop();

            }

            if(newNumber)

                stackNumbers.push(currentNumber);





            if(input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '+'){



                if(input[i] == '*' || input[i] == '/')

                    currentOperandPriority = currentExpressionPriority + 1;

                else

                    currentOperandPriority = currentExpressionPriority;



                if(stackOperators.empty() || stackOperators.top().priority <= currentOperandPriority){



                    currentOp.operation = input[i];

                    currentOp.priority = currentOperandPriority;

                    stackOperators.push(currentOp);



                } else {

                        while(!stackOperators.empty() && (currentOp = stackOperators.top()).priority > currentOperandPriority) {



                        stackOperators.pop();



                        int operand1 = stackNumbers.top();

                        stackNumbers.pop();

                        int operand2 = stackNumbers.top();

                        stackNumbers.pop();



                        int res;



                        if(currentOp.operation == '+')

                            res = operand1 + operand2;

                        else if (currentOp.operation == '-')

                            res = operand1 - operand2;

                        else if (currentOp.operation == '/')

                            res = operand1 / operand2;

                        else if (currentOp.operation == '*')

                            res = operand1 * operand2;



                        stackNumbers.push(res);

                    }



                    currentOp.operation = input[i];

                    currentOp.priority = currentOperandPriority;

                    stackOperators.push(currentOp);

                }

            }



            else if(input[i] == '('){

                currentExpressionPriority -= 2;

            }



            else if(input[i] == ')'){

                currentExpressionPriority += 2;

            }



        }





    currentNumber = 0;

    newNumber = false;



    while(!stackDigits.empty()){

        newNumber = true;

        currentNumber = currentNumber*10 + stackDigits.top() - '0';

        stackDigits.pop();

    }

    if(newNumber)

        stackNumbers.push(currentNumber);



    while(!stackOperators.empty()){

        currentOp = stackOperators.top();

        stackOperators.pop();

        int operand1 = stackNumbers.top();

        stackNumbers.pop();

        int operand2 = stackNumbers.top();

        stackNumbers.pop();



        int res;



        if(currentOp.operation == '+')

            res = operand1 + operand2;

        else if (currentOp.operation == '-')

            res = operand1 - operand2;

        else if (currentOp.operation == '/')

            res = operand1 / operand2;

        else if (currentOp.operation == '*')

            res = operand1 * operand2;



        stackNumbers.push(res);

    }



    fout<<stackNumbers.top() << "\n";

}
