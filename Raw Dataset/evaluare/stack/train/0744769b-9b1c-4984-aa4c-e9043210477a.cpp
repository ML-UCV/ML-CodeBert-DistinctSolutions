#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
struct my_timer{
 chrono::time_point<chrono::high_resolution_clock> start;
 my_timer():
 start(chrono::high_resolution_clock::now()){}
 ~my_timer(){
  std::chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
  clog<<diff.count()<<"s\n";
 }
};

int main()
{
 freopen("evaluare.in","r",stdin);
 freopen("evaluare.out","w",stdout);
 {
  char ord[128];
  ord['+']=ord['-']=0;
  ord['*']=ord['/']=1;
  ord['('] = 2;
  queue<ll> val;
  stack<ll> op;
  int c=getchar();
  while(c!=EOF && c != '\n'){
   if(isdigit(c)){
    int num = c&15;
    while(isdigit(c=getchar())){
     num = (num << 3) + (num << 1) + (c & 15);
    }
    val.emplace(num);
    if(c==EOF || c=='\n')
     break;
   }
   if(c==')'){
    while(op.top() != '('){
     val.emplace((1ll<<62) | op.top());
     op.pop();
    }
    op.pop();
   }
   else{
    while(!op.empty() && op.top() != '(' && ord[op.top()] >= ord[c]){
     val.emplace((1ll<<62) | op.top());
     op.pop();
    }
    op.emplace(c);
   }
   c=getchar();
  }
  while(!op.empty()){
   val.emplace((1ll<<62) | op.top());
   op.pop();
  }
  while(!val.empty()){
   if(val.front() & (1ll << 62)){
    ll a = op.top();
    op.pop();
    switch(val.front() & (~(1ll<<62))){
     case '+':
      op.top() += a;
      break;
     case '-':
      op.top() -= a;
      break;
     case '*':
      op.top() *= a;
      break;
     case '/':
      op.top() /= a;
      break;
     default :
      return 1;
    }
   }else{
    op.emplace(val.front());
   }
   val.pop();
  }
  printf("%lld",op.top());
 }
}
