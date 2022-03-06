#include <bits/stdc++.h>


using namespace std;



ifstream f ("evaluare.in");

ofstream g ("evaluare.out");



struct Node{

    bool operand;

    union {

        char op;

        int nr;

    };

    Node *left,*right;



    Node(char x) : operand(false), op(x), left(nullptr), right(nullptr){}

    Node(int x) : operand(true), nr(x), left(nullptr), right(nullptr){}

    Node(){}

};





int precedence(char x)

{

    if(x == '^')return 3;

    else if(x == '*' || x == '/')return 3;

    else if(x == '+' || x == '-')return 1;

    return -1;

}



void delete_spaces(string &s)

{

    int n = s.size(),j=0;

    for(int i=0;i<n;++i)

        if(s[i] != ' ')s[j++] = s[i];

    s[j] = '\0';

    s.resize(j);

    s.shrink_to_fit();

}



Node* infix_to_prefix(string in)

{

    delete_spaces(in);



    in = '(' + in + ')';



    int n = in.size();



    stack <char> st;

    stack <Node*> noduri;



    for(int i=0;i<n;++i)

    {

        if(isdigit(in[i]))

        {

            string nr;

            while(i < n && isdigit(in[i]) )

            {

                nr += in[i];

                i++;

            }

            i--;

            noduri.push(new Node( stoi(nr) ) );

        }

        else

        if(in[i] == '(') st.push('(');

        else

        if(in[i] == ')')

        {

            while(!st.empty() && st.top() != '(')

            {

                Node *t = new Node(st.top());

                Node *t1 = nullptr, *t2 = nullptr;



                if(!noduri.empty())

                {

                    t1 = noduri.top();

                    noduri.pop();

                }





                if(!noduri.empty())

                {

                    t2 = noduri.top();

                    noduri.pop();

                }



                t->left = t2;

                t->right = t1;

                noduri.push(t);



                st.pop();

            }

            if(st.top() == '(')st.pop();

        }

        else

        {

            while(!st.empty() && in[i] != '^' && precedence(in[i]) <= precedence(st.top()))

            {

                Node *t = new Node(st.top());

                Node *t1 = nullptr, *t2 = nullptr;



                if(!noduri.empty())

                {

                    t1 = noduri.top();

                    noduri.pop();

                }

                if(!noduri.empty())

                {

                    t2 = noduri.top();

                    noduri.pop();

                }



                t->left = t2;

                t->right = t1;

                noduri.push(t);



                st.pop();

            }

            st.push(in[i]);

        }



    }

    return noduri.top();

}
int calcul(Node *&root)

{

    if(root->operand == true)

        return root->nr;

    else

    {

        int t1 = calcul(root->left);

        int t2 = calcul(root->right);

        switch(root->op)

        {

            case '+' : return t1 + t2;

                break;

            case '-' : return t1 - t2;

                break;

            case '*' : return t1 * t2;

                break;

            case '/' : return t1 / t2;

                break;

            case '^' : return pow(t1,t2);

                break;

        }

    }

}



int main()

{

    string in;

    getline(f,in);

    Node *root = infix_to_prefix(in);

    g << calcul(root);

    return 0;

}
