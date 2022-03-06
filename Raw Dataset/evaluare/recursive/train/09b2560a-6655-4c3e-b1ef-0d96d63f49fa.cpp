#include <cctype>
#include <fstream>
#include <string>
#include <vector>


struct expression

{

    int i;

    std::string e;



    expression(std::string e) : i(0), e(e) {}



    int E()

    {

        int r = P();



        while (i < e.size() && e[i] == '+' || e[i] == '-')

        {

            if (e[i] == '+')

            {

                i++;

                r += P();

            }

            else

            {

                i++;

                r -= P();

            }

        }



        return r;

    }



    int P()

    {

        int r = T();



        while (i < e.size() && e[i] == '*' || e[i] == '/')

        {

            if (e[i] == '*')

            {

                i++;

                r *= T();

            }

            else

            {

                i++;

                r /= T();

            }

        }



        return r;

    }



    int T()

    {

        if (e[i] == '(')

        {

            i++;

            int r = E();

            i++;



            return r;

        }



        return C();

    }



    int C()

    {

        std::string number;



        while (i < e.size() && std::isdigit(e[i]))

        {

            number += e[i];

            i++;

        }



        return std::stoi(number);

    }



    int eval()

    {

        i = 0;

        return E();

    }

};



int solve(const std::string &e)

{

    return expression(e).eval();

}



std::string read();

void write(int results);



int main()

{

    auto e = read();

    auto result = solve(e);

    write(result);



    return 0;

}



std::string read()

{

    std::ifstream fin("evaluare.in");



    std::string s;

    fin >> s;



    return s;

}



void write(int result)

{

    std::ofstream fout("evaluare.out");



    fout << result << '\n';

}
