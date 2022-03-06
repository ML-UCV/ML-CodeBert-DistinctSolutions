#include <bits/stdc++.h>


using namespace std;



ifstream f ("evaluare.in");

ofstream g ("evaluare.out");





char infix[100001],nrCurent[100001];



struct Node

{

    string info;

    Node *left,*right;

    Node(string s) : info(s),left(nullptr),right(nullptr) {}

};





int preced(char x)

{

    if(x == '+' || x == '-')

        return 1;

    if(x == '*' || x == '/')

        return 2;

    if(x == '^')

        return 3;

    return -1;

}
bool cifra(char x)

{

    return x >= '0' && x <= '9';

}



Node* infix_to_postfix(char infix[])

{





    int n = strlen(infix),k;



    stack <char> operatori;

    stack <Node*> noduri;



    for(int i=0; i<n; ++i)

    {

        if( cifra(infix[i]) )

        {

            k = 0;

            while(i < n && cifra(infix[i]) )

            {

                nrCurent[k++] = infix[i];

                i++;

            }

            i--;

            nrCurent[k] = '\0';



            noduri.push( new Node(nrCurent) );



        }

        else if(infix[i] == '(') operatori.push('(');

        else if(infix[i] == ')')

        {

            while(!operatori.empty() && operatori.top() != '(')

            {

                Node *n = new Node( string(1,operatori.top()) );



                Node *t1 = noduri.top();

                noduri.pop();

                Node *t2 = noduri.top();

                noduri.pop();



                n->left = t2;

                n->right = t1;

                noduri.push(n);



                operatori.pop();

            }

            if(operatori.top() == '(')

                operatori.pop();

        }

        else

        {

            while(!operatori.empty() && infix[i] != '^' && preced(infix[i]) <= preced(operatori.top()) )

            {

                Node *n = new Node( string(1,operatori.top()) );



                Node *t1 = noduri.top();

                noduri.pop();

                Node *t2 = noduri.top();

                noduri.pop();



                n->left = t2;

                n->right = t1;

                noduri.push(n);



                operatori.pop();

            }

            operatori.push(infix[i]);

        }

    }



    while(!operatori.empty())

    {

        Node *n = new Node( string(1,operatori.top()) );



        Node *t1 = noduri.top();

        noduri.pop();

        Node *t2 = noduri.top();

        noduri.pop();



        n->left = t2;

        n->right = t1;

        noduri.push(n);



        operatori.pop();

    }



    return noduri.top();

}





int calcul(Node *root)

{

    string s = root->info;



    if(cifra(s[0]))

        return stoi(s);



    int t1 = calcul(root->left);

    int t2 = calcul(root->right);



    if(s[0] == '+')

        return t1 + t2;

    else if(s[0] == '-')

        return t1 - t2;

    else if(s[0] == '*')

        return t1 * t2;

    else if(s[0] == '/')

        return t1 / t2;

    else if(s[0] == '^')

        return pow(t1,t2);

}
int main()

{

    f.getline(infix,100001);

    Node *root = infix_to_postfix(infix);

    g << calcul(root);

    return 0;

}
