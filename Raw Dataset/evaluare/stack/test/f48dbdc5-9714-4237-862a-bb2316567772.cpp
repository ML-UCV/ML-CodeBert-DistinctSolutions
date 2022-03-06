#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <fstream>


using namespace std;



class ExprEvaluator {

private:



    vector<string> OPERATORS;

    bool isOperator(char);

    int opPriority(char);

    int evaluateSubExpr(int, int, char);



public:



    ExprEvaluator();

    int evaluateExpr(const string &);

};



bool ExprEvaluator::isOperator(char chr) {

    for (int i = 0; i < this->OPERATORS.size(); i++) {

        if (this->OPERATORS[i].find(chr) != string::npos)

            return true;

    }

    return false;

}



int ExprEvaluator::opPriority(char oper) {

    for (int i = 0; i < this->OPERATORS.size(); i++) {

        if (this->OPERATORS[i].find(oper) != string::npos)

            return i;

    }

    return -1;

}



int ExprEvaluator::evaluateSubExpr(int operand1, int operand2, char oper) {

    if (oper == '/') {

        return operand1 / operand2;

    } else if (oper == '*') {

        return operand1 * operand2;

    } else if (oper == '-') {

        return operand1 - operand2;

    } else {

        return operand1 + operand2;

    }

}



ExprEvaluator::ExprEvaluator() {



     this->OPERATORS.push_back("/*");

     this->OPERATORS.push_back("-+");

}



int ExprEvaluator::evaluateExpr(const string & expr) {

    stack<int> operands_stack;

    stack<char> operators_stack;

    int expr_pos = 0;



    while (expr_pos < expr.size()) {



        if (isdigit(expr[expr_pos])) {



            int number = expr[expr_pos] - '0';

            expr_pos += 1;



            while (expr_pos < expr.size() && isdigit(expr[expr_pos])) {

                number = number * 10 + expr[expr_pos] - '0';

                expr_pos += 1;

            }



            operands_stack.push(number);



        } else if (this->isOperator(expr[expr_pos])) {



            if (operators_stack.empty() or operators_stack.top() == '(' or

            this->opPriority(expr[expr_pos]) < this->opPriority(operators_stack.top())) {



                operators_stack.push(expr[expr_pos]);



            } else {

                int priority = this->opPriority(expr[expr_pos]);



                while (!operators_stack.empty() && operators_stack.top() != '(' &&

                priority >= this->opPriority(operators_stack.top())) {



                    char oper = operators_stack.top(); operators_stack.pop();

                    int operand2 = operands_stack.top(); operands_stack.pop();

                    int operand1 = operands_stack.top(); operands_stack.pop();

                    operands_stack.push(

                        this->evaluateSubExpr(operand1, operand2, oper)

                    );

                }

                operators_stack.push(expr[expr_pos]);

            }



            expr_pos += 1;



        } else if (expr[expr_pos] == '(') {



            operators_stack.push('(');

            expr_pos += 1;



        } else {



            while (operators_stack.top() != '(') {

                char oper = operators_stack.top(); operators_stack.pop();

                int operand2 = operands_stack.top(); operands_stack.pop();

                int operand1 = operands_stack.top(); operands_stack.pop();

                operands_stack.push(

                    this->evaluateSubExpr(operand1, operand2, oper)

                );

            }



            operators_stack.pop();

            expr_pos += 1;



        }

    }



    while (!operators_stack.empty()) {

        char oper = operators_stack.top(); operators_stack.pop();

        int operand2 = operands_stack.top(); operands_stack.pop();

        int operand1 = operands_stack.top(); operands_stack.pop();

        operands_stack.push(

            this->evaluateSubExpr(operand1, operand2, oper)

        );

    }



    return operands_stack.top();

}



int main() {

    string expr;



    ifstream inputFile("evaluare.in");

    inputFile >> expr;

    inputFile.close();



    ExprEvaluator evaluator;

    int ans = evaluator.evaluateExpr(expr);



    ofstream outputFile("evaluare.out");

    outputFile << ans;

    outputFile.close();



    return 0;

}
