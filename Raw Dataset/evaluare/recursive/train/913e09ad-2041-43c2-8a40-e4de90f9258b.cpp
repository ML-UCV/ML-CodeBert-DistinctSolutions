#include<cstdio>
const int LMAX = 100000;
char s[LMAX + 1];
int expresie();
int termen();
int factor();
int p = 0;
int expresie()
{
    int sum = termen();
    while(s[p] == '+' || s[p] == '-')
    {
        if(s[p] == '+')
        {
            p ++;
            sum += termen();
        }
        else
        {
            p ++;
            sum -= termen();
        }
    }
    return sum;
}
int termen()
{
    int prod = factor();
    while(s[p] == '*' || s[p] == '/')
    {
        if(s[p] == '*')
        {
            ++p;
            prod *= factor();
        }
        else
        {
            ++p;
            prod /= factor();
        }

    }
    return prod;
}
int factor()
{
    int r = 0;
    if(s[p] == '(')
    {
        ++p;
        r = expresie();
        ++p;
    }
    else
        while(s[p] >='0' && s[p] <= '9')
        {
            r = r * 10 + s[p] - '0';
            p ++;
        }

    return r;
}
int main()
{
    freopen("evaluare.in", "r", stdin);
    freopen("evaluare.out", "w", stdout);
    scanf("%s", s);
    printf("%d", expresie());
}
