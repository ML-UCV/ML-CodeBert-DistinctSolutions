#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>




using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



char s[100010], ch[4][4]{"+-", "*/", "^", ""}, *p=s;



int eval(int);

int getNr();

int rez(int, char, int);



int rez(int a, int b, char c)

{

    switch(c)

    {

    case '+':

        return a+b;

    case '-':

        return a-b;

    case '*':

        return a*b;

    case '/':

        return a/b;

    }

    return 0;

}



int eval(int h)

{

    int r;

    if(h==2) r=getNr();

    else r=eval(h+1);

    while(strchr(ch[h], *p))

        r=rez(r, eval(h+1), *(++p-1));

    return r;

}



int getNr()

{

    int r=0;

    if(*p=='(') ++p, r=eval(0), ++p;

    else

    {

        while(*p>='0' && *p<='9')

            r=r*10+*(++p-1)-'0';

    }

    return r;

}



int main()

{

    in>>s;

    s[strlen(s)]='\n';

    out<<eval(0);

    return 0;

}
