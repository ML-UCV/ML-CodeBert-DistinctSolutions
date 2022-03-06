#include <fstream>
#include <stack>
#include <cctype>
#include <deque>

using namespace std;

ifstream in ("evaluare.in");
ofstream out ("evaluare.out");

stack <short int> s;
deque < pair <long long,bool> > fin;
stack <long long> r;







int main()
{
  char c,aux='a';
  long long cnt=0,nr=0,x1,x2,rez;
  while (in.get(c)&&c!='\n')
  {
    if (isdigit(c)&&isdigit(aux))
      nr=nr*10+c-48;
    else if (isdigit(c)&&!isdigit(aux))
      nr=c-48;
    else if (!isdigit(c)&&isdigit(aux))
      fin.push_back({nr,0});
    if (!isdigit(c))
    {
      if (c=='+'||c=='-')
      {
        while (!s.empty()&&s.top())
          fin.push_back({s.top(),1}),s.pop();
        if (c=='+')
          s.push(2);
        else
          s.push(1);
      }
      else if (c=='*'||c=='/')
      {
        while (!s.empty()&&s.top()>=3)
          fin.push_back({s.top(),1}),s.pop();
        if (c=='*')
          s.push(3);
        else
          s.push(4);
      }
      else if (c=='(')
        s.push(0);
      else
      {
        while (!s.empty()&&s.top()!=0)
          fin.push_back({s.top(),1}),s.pop();
        s.pop();
      }
    }
    aux=c;
  }
  if (isdigit(aux))
    fin.push_back({nr,0});
  while (!s.empty())
    fin.push_back({s.top(),1}),s.pop();
  for (int i=0;i<fin.size();i++)
  {
    if (fin[i].second==0)
      r.push(fin[i].first);
    else
    {
      x1=r.top(),r.pop(),x2=r.top(),r.pop();
      if (fin[i].first==1)
        rez=x2-x1;
      else if (fin[i].first==2)
        rez=x2+x1;
      else if (fin[i].first==3)
        rez=x2*x1;
      else
        rez=x2/x1;
      r.push(rez);
    }
  }
  out<<r.top();
  return 0;
}
