#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



class StackException

{

private:

    std::string m_error;



public:

    StackException(std::string error)

        : m_error(error)

    {

    }



    const char* getError()

    {

        return m_error.c_str();

    }

};

template <typename T>

struct Element

{

    Element<T>* next;

    T data;

};

template <typename T>

class Stack

{

private:

    Element<T> *top;

public:

    Stack();

    Stack(vector<T> newElements);

    Stack(const Stack<T> &S);

    void Push(T newElement);

    T Pop();

    T Top() const;

    bool isEmpty() const;

    void printStack();

};

template <class T>

Stack<T>::Stack()

{

    top=NULL;

}

template <class T>

Stack<T>::Stack(vector<T> newElements)

{

    top=NULL;

    for(auto &currentElement:newElements)

        Push(currentElement);

}

template <class T>

Stack<T>::Stack(const Stack<T> &S)

{

    top=NULL;

    vector<T> stackElements;

    int numberStackElements=0;

    Element<T> *currentElement=S.top;

    while(currentElement!=NULL)

    {

        stackElements.push_back(currentElement->data);

        currentElement=currentElement->next;

        numberStackElements++;

    }

    for(int i=numberStackElements-1;i>=0;--i)

        Push(stackElements[i]);

}

template <class T>

void Stack<T>::Push(T newElement)

{

    Element<T> *newTop=new Element<T>;

    if(!newTop)

        throw StackException("Stack Overflow");

    newTop->data=newElement;

    newTop->next=top;

    top=newTop;

}

template <class T>

T Stack<T>::Top() const

{

    if(isEmpty())

        throw StackException("Stack has no elements");

    return top->data;

}

template <class T>

T Stack<T>::Pop()

{

    if(isEmpty())

        throw StackException("Stack has no elements");

    Element<T> *temp=top;

    T topData=top->data;

    top=top->next;

    temp->next=NULL;

    free(temp);

    return topData;

}

template <class T>

bool Stack<T>::isEmpty() const

{

    return (top==NULL);

}

template <class T>

void Stack<T>::printStack()

{

    if(top==NULL)

        throw StackException("Stack has no elements");

    Element<T> *currentElement=top;

    while(currentElement!=NULL)

    {

        cout<<currentElement->data<<" ";

        currentElement=currentElement->next;

    }

}

int applyOperator(int x, int y, char Operator)

{

    switch(Operator)

    {

        case '+': return x+y;

        case '-': return x-y;

        case '*': return x*y;

        case '/': return x/y;

    }

}

int priority(char Operator)

{

    switch(Operator)

    {

        case '+': return 1;

        case '-': return 1;

        case '*': return 2;

        case '/': return 2;

    }

    return 0;

}

int DijkstraAlgorithm(string expression)

{

    Stack <int> Values;

    Stack <char> Operators;

    for(std::string::iterator it=expression.begin(); it!=expression.end(); ++it)

    {

        char currentCharacter=*it;

        if(currentCharacter==' ')

            continue;

        if(isdigit(currentCharacter))

        {

            int value=0;

            for(;it!=expression.end()&&isdigit(*it); ++it)

                value=value*10+(*it-'0');

            --it;

            Values.Push(value);

            continue;

        }

        if(currentCharacter=='(')

        {

            Operators.Push(currentCharacter);

            continue;

        }

        if(currentCharacter==')')

        {

            while(!Operators.isEmpty()&&Operators.Top()!='(')

            {

                char currentOperator=Operators.Pop();

                int operand1=Values.Pop(), operand2=Values.Pop();

                Values.Push(applyOperator(operand2,operand1,currentOperator));

            }

            if(!Operators.isEmpty())

                Operators.Pop();

            continue;

        }

        int Operator=*it;

        while(!Operators.isEmpty()&&priority(Operator)<=priority(Operators.Top()))

        {

            char currentOperator=Operators.Pop();

            int operand1=Values.Pop(), operand2=Values.Pop();

            Values.Push(applyOperator(operand2,operand1,currentOperator));

        }

        Operators.Push(Operator);

    }

    while(!Operators.isEmpty())

    {

        char currentOperator=Operators.Pop();

        int operand1=Values.Pop(), operand2=Values.Pop();

        Values.Push(applyOperator(operand2,operand1,currentOperator));

    }

    return Values.Top();

}

void evaluateExpression()

{

    string expression;

    getline(fin,expression);

    fout<<DijkstraAlgorithm(expression);

}

int main()

{

    evaluateExpression();

    return 0;

}
