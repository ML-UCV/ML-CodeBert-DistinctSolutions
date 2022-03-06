#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>


using namespace std;



char exp[100002];



vector<int> postfix_st;

stack<int> op_st;





int get_priority(char op) {

 if (op == '*' || op == '/')

  return 1;

 if (op == '+' || op == '-')

  return 2;

}





int main() {

 freopen("evaluare.in", "r", stdin);

 freopen("evaluare.out", "w", stdout);



 scanf("%s\n", exp);

 int n = strlen(exp);

 if (exp[n-1] == '\n') {

  exp[n-1] = 0;

  --n;

 }





 int current_number = 0, res, a, b;

 for(int i=0; i<n; ++i)

  if (exp[i] >= '0' && exp[i] <='9') {

   current_number = 0;

   while(exp[i] >= '0' && exp[i] <='9' && i <n) {

    current_number = current_number * 10 + exp[i] - '0';

    ++i;

   }

   --i;

   postfix_st.push_back(current_number + '0');

  }

  else {

   if (exp[i] == '(') {

    op_st.push(exp[i]);

    continue;

   }

   if (exp[i] == ')') {

    while(op_st.top() != '(') {

     postfix_st.push_back(op_st.top());

     op_st.pop();

    }

    op_st.pop();

    continue;

   }

   while (op_st.size() && op_st.top() != '(' && get_priority(exp[i]) >= get_priority(op_st.top())) {

    postfix_st.push_back(op_st.top());

    op_st.pop();

   }

   op_st.push(exp[i]);



  }



 while(op_st.size()) {

  postfix_st.push_back(op_st.top());

  op_st.pop();

 }



 for(int i=0; i<postfix_st.size(); ++i) {

  if (postfix_st[i] >= '0')

   op_st.push(postfix_st[i] - '0');

  else {

   a = op_st.top();

   op_st.pop();

   b = op_st.top();

   op_st.pop();



   switch(postfix_st[i]) {

    case '+':

     res = a + b;

     break;

    case '-':

     res = b-a;

     break;

    case '/':

     res = b/a;

     break;

    case '*':

     res = a*b;

     break;

   }



   op_st.push(res);

  }

 }



 printf("%d\n", op_st.top());

 return 0;

}
