#include <bits/stdc++.h>


using namespace std;



class expressionEvaluation

{

public:

    static const int symbolsTableSize = 128;

private:



    static bool correctExpression;

    static bool acceptedSymbols[symbolsTableSize];

    static bool acceptedSymbolsTableInitialized;

    static int parseDivisionMultiplication(const char *p, int &index)

    {

        int t1 = parseTerm(p, index), t2;

        bool mul;

        if (t1 == -2147483648) return t1;

        while (p[index] == '*' || p[index] == '/')

        {

            mul = (p[index] == '*' ? true : false);

            ++index;

            t2 = parseTerm(p, index);

            if (t2 == -2147483648) return t2;

            if (mul) t1 *= t2;

            else t1 /= t2;

        }

        if (!acceptedSymbols[(int)p[index]])

        {

            correctExpression = false;

            return -2147483648;

        }

        return t1;

    }

    static int parseSubtractionAddition(const char *p, int &index)

    {

        int t1 = parseDivisionMultiplication(p, index), sign, t2;

        if (t1 == -2147483648) return t1;

        while (p[index] == '-' || p[index] == '+')

        {

            sign = (p[index] == '+' ? 1 : -1);

            ++index;

            t2 = parseDivisionMultiplication(p, index);

            if (t2 == -2147483648) return t2;

            t1 = t1 + sign * t2;

        }

        if (!acceptedSymbols[(int)p[index]])

        {

            correctExpression = false;

            return -2147483648;

        }

        return t1;

    }

    static int parseTerm(const char *p, int &index)

    {

        if (!acceptedSymbols[(int)p[index]])

        {

            correctExpression = false;

            return -2147483648;

        }

        if (p[index] == '(')

        {

            ++index;

            int ret = parseSubtractionAddition(p, index);

            ++index;

            return ret;

        }

        else if (p[index] >= '0' && p[index] <= '9')

        {

            int nr = 0;

            while (p[index])

            {

                if (!acceptedSymbols[(int)p[index]])

                {

                    correctExpression = false;

                    return -2147483648;

                }

                if (p[index] >= '0' && p[index] <= '9')

                    nr = nr * 10 + (p[index] - '0');

                else break;

                ++index;

            }

            return nr;

        }

        else

        {

            correctExpression = false;

            return -2147483648;

        }

    }

    static void initializeSymbolsTable()

    {

        if (acceptedSymbolsTableInitialized) return;

        for (int i=0; i< symbolsTableSize; ++i)

            acceptedSymbols[i] = false;

        acceptedSymbols[(int)'+'] = acceptedSymbols[(int)'-'] = acceptedSymbols[(int)'*']

                                    = acceptedSymbols[(int)'/'] = true;

        for (int i=0; i<10; ++i)

            acceptedSymbols[i + '0'] = true;

        acceptedSymbols[(int)'('] = acceptedSymbols[(int)')'] = true;

        acceptedSymbolsTableInitialized = true;

        acceptedSymbols[0] = true;

    }

public:

    static bool evaluate(const char *p, int &result)

    {

        initializeSymbolsTable();

        correctExpression = true;

        int index = 0;

        result = parseSubtractionAddition(p, index);

        return correctExpression;

    }

};

bool expressionEvaluation::acceptedSymbolsTableInitialized = false;

bool expressionEvaluation::correctExpression = true;

bool expressionEvaluation::acceptedSymbols[expressionEvaluation::symbolsTableSize] = {};



char expr[100005];

int main()

{

    freopen("evaluare.in","r",stdin);

    freopen("evaluare.out","w",stdout);

    cin>>expr;

    int ans;

    expressionEvaluation ev;

    ev.evaluate(expr, ans);

    cout<<ans<<'\n';

    return 0;

}
