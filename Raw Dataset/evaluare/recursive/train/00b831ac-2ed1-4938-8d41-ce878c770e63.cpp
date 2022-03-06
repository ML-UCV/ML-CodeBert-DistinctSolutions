#include <bits/stdc++.h>


using namespace std;



const int L_MAX = 100000;



int p[L_MAX];



stack <int> st;



string elimparan (string s)

{

    for(int i = 0; i < s.size(); i++)

    {

        if(s[i] == '(')

            st.push(i);

        if(s[i] == ')')

        {

            p[i] = st.top();

            st.pop();

        }

    }

    int l = 0, r = s.size();

    while(l < r && s[r - 1] == ')' && p[r - 1] == l)

    {

        l++;

        r--;

    }

    return s.substr(l, r - l);

}



int eval (string s);



int term (string s)

{

    if(s.empty())

        return 0;

    int prev = s.size();

    s = elimparan(s);

    if(s.size() != prev)

        return eval(s);

    char op = '*';

    int oppos = -1;

    int paran = 0;

    int answer = 1;

    for(int i = 0; i < s.size(); i++)

    {

        if(s[i] == '(')

            paran++;

        if(paran == 0 && (s[i] == '*' || s[i] == '/'))

        {

            if(op == '*')

                answer *= eval(s.substr(oppos + 1, i - oppos - 1));

            else

                answer /= eval(s.substr(oppos + 1, i - oppos - 1));

            oppos = i;

            op = s[i];

        }

        if(s[i] == ')')

            paran--;

    }

    if(op == '*')

        answer *= eval(s.substr(oppos + 1, s.size() - oppos - 1));

    else

        answer /= eval(s.substr(oppos + 1, s.size() - oppos - 1));

    return answer;

}



int eval (string s)

{

    if(s.empty())

        return 0;

    s = elimparan(s);

    bool num = true;

    for(int i = 0; i < s.size(); i++)

        if(!isdigit(s[i]))

            num = false;

    if(num == true)

    {

        int answer = 0;

        for(int i = 0; i < s.size(); i++)

            answer = answer * 10 + s[i] - '0';

        return answer;

    }

    int sgn = +1;

    int sgnpos = -1;

    int answer = 0;

    int paran = 0;

    for(int i = 0; i < s.size(); i++)

    {

        if(s[i] == '(')

            paran++;

        if(paran == 0 && (s[i] == '+' || s[i] == '-'))

        {

            answer += sgn * term(s.substr(sgnpos + 1, i - sgnpos - 1));

            sgnpos = i;

            if(s[i] == '+')

                sgn = +1;

            else

                sgn = -1;

        }

        if(s[i] == ')')

            paran--;

    }

    answer += sgn * term(s.substr(sgnpos + 1, s.size() - sgnpos - 1));

    return answer;

}



int main()

{

    ifstream fin ("evaluare.in");

    ofstream fout ("evaluare.out");

    string s;

    fin >> s;

    fout << eval(s) << "\n";

    return 0;

}
