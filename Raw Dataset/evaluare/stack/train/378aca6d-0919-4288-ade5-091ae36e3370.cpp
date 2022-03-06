#include <bits/stdc++.h>


using namespace std;

ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");

string s;

struct Node

{

    string val;

    Node *left, *right;

} *root;

bool priority (Node* n1, Node* n2)

{

    string val1 = n1 -> val;

    string val2 = n2 -> val;

    if (val2 == "(" || val1 == "(")

        return true;

    if ((val1 == "+" || val1 == "-") && (val2 == "*" || val2 == "/"))

        return true;

    return false;

}

void adjust (stack <Node*> &op, stack <Node*> &num)

{

    Node* n2 = op.top ();

    Node *nr1, *nr2;

    nr1 = num.top ();

    num.pop ();

    nr2 = num.top ();

    num.pop ();

    n2 -> left = nr1;

    n2 -> right = nr2;

    num.push (n2);

    op.pop ();

}

Node* postfix_tree (string s)

{

    stack <Node*> op;

    stack <Node*> num;

    int i = 0;

    int length = s.size ();

    while (i < length)

    {

        if (s[i] == ' ' || s[i] == '\t')

            i++;

        if (isdigit (s[i]))

        {

            string number;

            while (isdigit (s[i]) && i < length)

            {

                number += s[i];

                i++;

            }

            Node* n1 = new Node;

            n1 -> val = number;

            n1 -> left = NULL;

            n1 -> right = NULL;

            num.push (n1);

        }

        else

        {

            Node* n1 = new Node;

            n1 -> val += s[i];

            n1 -> left = NULL;

            n1 -> right = NULL;

            if (op.empty ())

                op.push (n1);

            else

            {

                if (s[i] == ')')

                {

                    while (op.top () -> val != "(")

                        adjust (op, num);

                    op.pop ();

                }

                else if (priority (op.top (), n1))

                    op.push (n1);

                else

                {

                    while ((!op.empty ()) ? (!priority(op.top (), n1)) : 0)

                        adjust (op, num);

                    op.push (n1);

                }

            }

            i++;

        }

    }

    while (!op.empty ())

        adjust (op, num);

    return num.top ();

}

int evaluate (Node* root)

{

    if (root)

        if (root -> val == "+")

            return evaluate (root -> right) + evaluate (root -> left);

        else if (root -> val == "-")

            return evaluate (root -> right) - evaluate (root -> left);

        else if (root -> val == "*")

            return evaluate (root -> right) * evaluate (root -> left);

        else if (root -> val == "/")

            return evaluate (root -> right) / evaluate (root -> left);

        else

        {

            int nr = 0;

            int n = root -> val.size ();

            int i = 0;

            for (int i = 0; i < n; i++)

                nr = nr * 10 + root -> val[i] - '0';

            return nr;

        }

}

void print (Node* root)

{

    if (root)

    {

        cout << root -> val << endl;

        print (root -> left);

        print (root -> right);

    }

}

int main ()

{

    getline (fin, s);

    root = postfix_tree (s);

    fout << evaluate (root);

}
