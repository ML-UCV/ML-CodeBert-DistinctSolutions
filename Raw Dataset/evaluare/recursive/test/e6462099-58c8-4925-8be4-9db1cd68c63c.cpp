#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;
ifstream fin("evaluare.in");
ofstream fout("evaluare.out");
constexpr int NX {100010};
char expresie[NX];

int prioritate(char c)
{
    if(c=='(' || c==')') return 0;
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
}
int semn(int st, int dr)
{
    int np{};
    for(int i=dr; i>=st; --i)
    {
        if(expresie[i]==')')
            np++;
        else if(expresie[i]=='(')
            np--;
        if(np==0 && (expresie[i]=='+' || expresie[i]=='-'))
            return i;
    }
    for(int i=dr; i>=st; --i)
    {
        if(expresie[i]==')')
            np++;
        else if(expresie[i]=='(')
            np--;
        if(np==0 && (expresie[i]=='/' || expresie[i]=='*'))
            return i;
    }
    return -1;
}
int getNum(int st)
{
    int nr{};
    while(isdigit(expresie[st]))
    {
        nr=nr*10+(expresie[st]-'0');
        st++;
    }
    return nr;
}
int solve(int st, int dr)
{
    int poz{semn(st, dr)};
    if(expresie[poz]=='+')
    return solve(st, poz-1)+solve(poz+1, dr);
    else if(expresie[poz]=='-')
    return solve(st, poz-1)-solve(poz+1, dr);
    else if(expresie[poz]=='*')
        return solve(st, poz-1)*solve(poz+1, dr);
    else if(expresie[poz]=='/')
        return solve(st, poz-1)/solve(poz+1, dr);
    else if(expresie[st]=='(' && expresie[dr]==')')
        return solve(st+1, dr-1);
    else return getNum(st);
}
int main()
{
    fin.getline(expresie, NX);
    fout<<solve(0, strlen(expresie)-1);

    return 0;
}
