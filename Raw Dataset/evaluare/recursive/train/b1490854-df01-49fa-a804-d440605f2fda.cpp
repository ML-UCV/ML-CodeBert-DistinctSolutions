#include <fstream>
#include <vector>
#include <string>


using namespace std;





string const inFile = "evaluare.in";

string const outFile = "evaluare.out";





ifstream Read(inFile);

ofstream Write(outFile);





int GetNumber(string const &expr, unsigned &index) {

    int number = 0;



    for (; expr[index] >= '0' && expr[index] <= '9'; ++index) {

        number = number * 10 + expr[index] - '0';

    }



    --index;



    return number;

}





int EvalPriority(vector<int> const &operands, string const &operators, unsigned &index) {

    int result = operands[index];



    for (; index < operators.size(); ++index) {

        if (operators[index] == '*') {

            result *= operands[index + 1];

        }

        else if (operators[index] == '/') {

            result /= operands[index + 1];

        }

        else {

            break;

        }

    }



    return result;

}





int EvalSimple(vector<int> const &operands, string const &operators) {

    vector<int> _operands;

    string _operators;

    unsigned index = 0;



    if (operators[0] == '*' || operators[0] == '/') {

        _operands.push_back(EvalPriority(operands, operators, index));

    }

    else {

        _operands.push_back(operands[0]);

    }



    for (; index < operators.size(); ++index) {

        if (operators[index] == '*' || operators[index] == '/') {

            _operands.push_back(EvalPriority(operands, operators, index));

            --index;

        }

        else {

            if (index == operators.size() - 1) {

                _operands.push_back(operands[index + 1]);

            }

            else if (operators[index + 1] == '+' || operators[index + 1] == '-') {

                _operands.push_back(operands[index + 1]);

            }



            _operators.push_back(operators[index]);

        }

    }



    int result = _operands[0];



    for (unsigned i = 0; i < _operators.size(); ++i) {

        if (_operators[i] == '+') {

            result += _operands[i + 1];

        }

        else if (_operators[i] == '-') {

            result -= _operands[i + 1];

        }

    }



    return result;

}





int Eval(string const &expr, unsigned &index) {

    vector<int> operands;

    string operators;



    for (; index < expr.size(); ++index) {

        if (expr[index] == '(') {

            operands.push_back(Eval(expr, ++index));

        }

        else if (expr[index] == ')') {

            break;

        }

        else if (expr[index] == '-') {

            operators.push_back('-');

        }

        else if (expr[index] == '+') {

            operators.push_back('+');

        }

        else if (expr[index] == '*') {

            operators.push_back('*');

        }

        else if (expr[index] == '/') {

            operators.push_back('/');

        }

        else if (expr[index] >= '0' && expr[index] <= '9') {

            operands.push_back(GetNumber(expr, index));

        }

    }



    return EvalSimple(operands, operators);

}





int main() {

    string expr;

    unsigned index = 0;



    Read >> expr;



    Write << Eval(expr, index);



    return 0;

}
