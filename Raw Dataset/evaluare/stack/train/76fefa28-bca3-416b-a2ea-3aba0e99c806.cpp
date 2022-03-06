#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char infix[100000 + 1];



int evaluate_basic(int A, int B, char c)

{

    if(c == '*') return A * B;

    if(c == '/') return A / B;

    if(c == '+') return A + B;

    if(c == '-') return A - B;



    return -1;

}





int operator_priority(char c)

{

    if(c == '+' || c == '-') return 1;

    if(c == '*' || c == '/') return 2;



    return -1;

}



int get_operand(int &i)

{

    int operand = 0;



    while(infix[i] >= '0' && infix[i] <= '9' && infix[i] != '\0')

    {

        operand = operand * 10 + (infix[i] - '0');

        ++i;

    }



    i--;





    return operand;

}



int evaluate()

{

    stack<char> operators;

    vector<int> operands;







    for(int i = 0; infix[i] != '\0'; i++)

    {

        if(infix[i] >= '0' && infix[i] <= '9') operands.push_back(get_operand(i));

        else if(infix[i] == '(') operators.push(infix[i]);

        else

        {

            while(!operators.empty()

                  && operators.top() != '('

                  && operator_priority(infix[i]) <= operator_priority(operators.top()))

            {

                size_t len = operands.size();



                operands[len - 2] = evaluate_basic(operands[len - 2], operands[len - 1], operators.top());



                operands.pop_back();



                operators.pop();

            }



            if(infix[i]==')') operators.pop();

            else operators.push(infix[i]);

        }





    }



    while(!operators.empty())

    {

        size_t len = operands.size();



        operands[len - 2] = evaluate_basic(operands[len - 2], operands[len - 1], operators.top());



        operands.pop_back();



        operators.pop();

    }
    return operands[0];

}





int main()

{

    fin.getline(infix, 100000 + 1, '\n');

    fout << evaluate();



}
