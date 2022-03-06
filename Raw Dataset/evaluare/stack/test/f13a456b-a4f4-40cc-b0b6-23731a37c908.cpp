#include <fstream>
#include <stack>




int evaluate(int op1, int op2, char op)

{

    auto res = 0;

    switch(op)

    {

        case '+':

            res = op1 + op2;

        break;

        case '-':

            res = op1 - op2;

        break;

        case '*':

            res = op1 * op2;

        break;

        case '/':

            res = op1 / op2;

        break;

    }



    return res;

}



void evaluate(std::stack<int>& st, std::stack<char>& op)

{

    auto op2 = st.top();

    st.pop();

    auto op1 = st.top();

    st.pop();



    st.push(evaluate(op1, op2, op.top()));

    op.pop();

}



int extractValue(const std::string& input, unsigned long long& i)

{

    auto value = 0;

    while((input[i] >= '0' && input[i] <= '9') && i < input.size())

    {

        value = value*10 + input[i] - '0';

        ++i;

    }

    --i;



    return value;

}
int main()

{

    std::ifstream fin("evaluare.in");

    std::ofstream fout("evaluare.out");

    std::string input;

    fin>>input;



    std::stack<int> st;

    std::stack<char> op;

    for(auto i=0ULL; i < input.size(); ++i)

    {

        auto ch = input[i];

        if(ch == '(' || ch == '*' || ch == '/')

        {

            op.push(ch);

        }

        if(ch >= '0' && ch <= '9')

        {

            st.push(extractValue(input, i));

            if(!op.empty() && (op.top() == '*' || op.top() =='/'))

            {

                evaluate(st, op);

            }

        }

        if(ch == '+' || ch == '-')

        {

            if(!op.empty() && op.top() != '(')

            {

                evaluate(st, op);

            }

            op.push(ch);

        }

        if(ch == ')')

        {

            while(op.top() != '(')

            {

                evaluate(st, op);

            }

            op.pop();

            if(!op.empty() && (op.top() == '*' || op.top() =='/'))

            {

                evaluate(st, op);

            }

        }



    }



    while(!op.empty())

    {

        evaluate(st, op);



    }



    fout<<st.top();



    return 0;

}
