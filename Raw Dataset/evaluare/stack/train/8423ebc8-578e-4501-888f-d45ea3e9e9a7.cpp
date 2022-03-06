#include<fstream>
#include<iostream>
#include<stack>
using namespace std;

ifstream in("evaluare.in");
ofstream out("evaluare.out");

bool isOperator(char op){
 return op=='+' || op=='-' || op=='*' || op=='/';
}
bool isDigit(char ch){
 return ch>='0' && ch<='9';
}

int precedence(char op){
 switch(op){
  case '+':
   return 1;
  case '-':
   return 1;
  case '*':
   return 2;
  case '/':
   return 2;
 }
 return 0;
}

int applyOperator(char op,int a,int b){
 switch(op){
  case '+':
   return a+b;
  case '-':
   return a-b;
  case '*':
   return a*b;
  case '/':
   return a/b;
 }
 return 0;
}

int peek_integer(const string&expression,int&cursor){
 int result=0;
 while(cursor<expression.length() && isDigit(expression[cursor])){
  result=result*10+(expression[cursor]-'0');
  cursor++;
 }
 cursor--;
 return result;
}

string get_postfix(const string&expression){
 int cursor=0;
 string result;
 stack<char> ops;


 while(cursor<expression.length()){

  char here=expression[cursor];


  if(isDigit(here)){
   int newint=peek_integer(expression,cursor);
   result+=to_string(newint)+' ';
  }
  else if(here=='('){
   ops.push(here);
  }
  else if(here==')'){

   while(ops.size() && ops.top()!='('){
    result+=ops.top();
    ops.pop();
   }
   if(ops.size())
    ops.pop();
  }
  else if(isOperator(here)){
   int prec=precedence(here);

   while(ops.size() && precedence(ops.top())>= prec){

    result+=ops.top();
    ops.pop();
   }

   ops.push(here);
  }
  cursor++;
 }


 while(ops.size()){
  result+=ops.top();
  ops.pop();
 }
 return result;
}

int evaluate_postfix(const std::string&postfix){
 stack<int> values;
 int cursor=0;

 while(cursor<postfix.length()){
  char here=postfix[cursor];

  if(isDigit(here)){
   int newint=peek_integer(postfix,cursor);
   values.push(newint);
  }
  else if(isOperator(here)){
   int a=values.top();
   values.pop();
   int b=values.top();
   values.pop();

   int result=applyOperator(here,b,a);

   values.push(result);
  }
  cursor++;
 }
 return values.top();
}



int main(){
 string eval;
 in>>eval;

 out<<evaluate_postfix(get_postfix(eval));

 return 0;
}
