#include <iostream>
#include <fstream>


using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");

string s;





struct Node

{

    Node *left{nullptr}, *right{nullptr};

    int value{0};

    char op{'#'};

};







Node* build(int i, int j)

{

    int b = 0;



    for(int k = j; k >= i; k--)

    {

        if(s[k] == ')') ++b;

        else if(s[k] == '(') --b;

        else if(b == 0 && (s[k] == '+' || s[k] == '-'))

        {

            Node *n = new Node;

            n -> op = s[k];

            n -> left = build(i, k-1);

            n -> right = build(k+1, j);

            return n;

        }

    }



    b = 0;



    for(int k = j; k >= i; k--)

    {

        if(s[k] == ')') ++b;

        else if(s[k] == '(') --b;

        else if(b == 0 && (s[k] == '*' || s[k] == '/'))

        {

            Node *n = new Node;

            n -> op = s[k];

            n -> left = build(i, k-1);

            n -> right = build(k+1, j);

            return n;

        }

    }



    if(s[i] == '(')

        return build(i+1, j-1);



    Node *n = new Node;

    n -> value;



    for(int k = i; k <= j; k++)

        n -> value = n -> value * 10 + s[k] - '0';



    return n;

}



int eval(Node*& node)

{

    if(node -> op == '#')

        return node->value;



    int left = eval(node->left);

    int right = eval(node->right);



    switch(node->op)

    {

    case '+':

        return left + right;

    case '-':

        return left - right;

    case '*':

        return left * right;

    case '/':

        return left / right;

    }

}



int main()

{

    fin >> s;

    int l = s.size();

    Node *arb = build(0, l-1);

    fout << eval(arb);



    return 0;

}
