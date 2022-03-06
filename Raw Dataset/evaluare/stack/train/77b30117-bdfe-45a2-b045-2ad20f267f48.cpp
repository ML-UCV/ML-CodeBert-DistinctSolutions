#include <bits/stdc++.h>
using namespace std;

string nume_problema = "evaluare";
ifstream fin(nume_problema + ".in");
ofstream fout(nume_problema + ".out");



enum operand
{
 ADD = '+',
 SUB = '-',
 MUL = '*',
 DIV = '/',
 LPR = '(',
 RPR = ')',
 VAL = '0'
};
struct expr
{
 vector<pair<operand, int>> ops;
 vector<pair<operand, int>> tmp;
 expr()
 {
 }
 void grad2()
 {
  bool lastmult = false;
  for (int i = 1; i < ops.size(); i += 2)
  {
   switch (ops[i].first)
   {
   case MUL:
   case DIV:
   {
    int prod = ops[i - 1].second;
    while (i < ops.size() && (ops[i].first == MUL || ops[i].first == DIV))
    {
     if (ops[i].first == MUL)
      prod *= ops[i + 1].second;
     if (ops[i].first == DIV)
      prod /= ops[i + 1].second;
     i += 2;
    }
    if (i >= ops.size())
     lastmult = true;
    ops[i - 1].second = prod;
   }
   default:
    tmp.push_back(ops[i - 1]);
    if (i < ops.size())
     tmp.push_back(ops[i]);
    break;
   }
  }
  if (!lastmult)
   tmp.push_back(ops.back());
 }
 int grad1()
 {
  int semn = 1, total = 0;
  for (int i = 0; i < tmp.size(); i++)
  {
   if (tmp[i].first == ADD)
    semn = 1;
   else if (tmp[i].first == SUB)
    semn = -1;
   else
    total += tmp[i].second * semn;
  }
  return total;
 }
 int execute()
 {
  grad2();
  return grad1();
 }
 void dbg()
 {
  for (const auto &i : ops)
   cerr << "OPS:" << char(i.first) << " " << i.second << endl;
  for (const auto &i : tmp)
   cerr << "TMP:" << i.first << " " << i.second << endl;
 }
};
stack<expr> st;

int main()
{
 expr blank;
 st.push(blank);
 int val = 0;
 for (char c; fin >> c;)
 {
  if (c == '(')
  {
   expr blank;
   st.push(blank);
  }
  else if (c == ')')
  {
   st.top().ops.push_back(make_pair(VAL, val));
   val = st.top().execute();
   st.pop();
  }
  else if (isdigit(c))
   val = val * 10 + (c - '0');
  else
  {
   st.top().ops.push_back(make_pair(VAL, val));
   val = 0;
   if (c == ADD)
    st.top().ops.push_back(make_pair(ADD, -1));
   if (c == SUB)
    st.top().ops.push_back(make_pair(SUB, -1));
   if (c == MUL)
    st.top().ops.push_back(make_pair(MUL, -1));
   if (c == DIV)
    st.top().ops.push_back(make_pair(DIV, -1));
  }
 }
 st.top().ops.push_back(make_pair(VAL, val));


 fout << st.top().execute();
 return 0;
}
