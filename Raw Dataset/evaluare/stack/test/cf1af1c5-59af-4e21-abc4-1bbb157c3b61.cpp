#include <bits/stdc++.h>

using namespace std;

void update(vector<int>&num,char c)
{
  int b=num.back(); num.pop_back();
  int a=num.back(); num.pop_back();
  if(c=='+') num.push_back(a+b);
  if(c=='-') num.push_back(a-b);
  if(c=='*') num.push_back(a*b);
  if(c=='/') num.push_back(a/b);
}

int pr(char c)
{
  if(c=='(') return 0; else
  if(c=='+' || c=='-') return 1; else
  if(c=='*' || c=='/') return 2;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("evaluare.in","r",stdin);
    freopen("evaluare.out","w",stdout);

    vector<int>num,op;
    set<char>h={'+','-','/','*'};
    set<char>nr={'0','1','2','3','4','5','6','7','8','9'};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='(') op.push_back('('); else
      if(s[i]==')')
      {
        while(op.back()!='(') update(num,op.back()),op.pop_back();
        op.pop_back();
      } else
      if(h.find(s[i])!=h.end())
      {
        while(!op.empty() && pr(op.back())>=pr(s[i]))
        update(num,op.back()),op.pop_back();
        op.push_back(s[i]);
      } else
      {
        int val=0;
        while(i<s.size() && nr.find(s[i])!=nr.end()) val=val*10+(s[i++]-'0');
        i--;
        num.push_back(val);
      }
    }
    while(!op.empty()) update(num,op.back()),op.pop_back();
    cout<<num[0];

}
