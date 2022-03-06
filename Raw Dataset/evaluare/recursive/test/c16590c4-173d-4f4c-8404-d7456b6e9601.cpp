#include <fstream>
#include <cstring>




using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



int n, pointer;

char line[100005], curchar;



int suma(int,char);

int factor(int);

int produs(int,char);



void readnextchar()

{

    curchar = line[pointer];

    pointer++;

}



int suma(int answer, char op)

{

    int r = produs(1,'*');

    if(op == '+')

        answer+=r;

    else

        answer-=r;



    if(curchar == '+')

    {

        readnextchar();

        return suma(answer, '+');

    }

    else if(curchar == '-')

    {

        readnextchar();

        return suma(answer, '-');

    }

    else

        return answer;

}



int factor(int result)

{

    if(curchar == '(')

    {

        readnextchar();

        result = suma(0,'+');

        readnextchar();

        return result;

    }

    else if('0' <= curchar && curchar <= '9')

    {

        result = result * 10 + (curchar - '0');

        readnextchar();

        return factor(result);

    }

    else

        return result;

}



int produs(int answer, char op)

{

    int r = factor(0);

    if(op == '*')

        answer *= r;

    else

        answer /= r;



    if(curchar == '*')

    {

        readnextchar();

        return produs(answer, '*');

    }

    else if(curchar == '/')

    {

        readnextchar();

        return produs(answer, '/');

    }

    else

        return answer;

}



int main()

{

    in.getline(line, 100005);



    readnextchar();



    out << suma(0,'+');



    in.close();

    out.close();



    return 0;

}
