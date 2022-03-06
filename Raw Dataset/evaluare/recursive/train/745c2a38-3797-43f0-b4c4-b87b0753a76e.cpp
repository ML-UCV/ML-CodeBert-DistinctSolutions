#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



    char e[100000];



void show(int start, int ending)

{

    for(int i=start; i<=ending; i++)

        cout<<e[i];

    cout<<'\n';

}



int stringtoint(int start, int ending)

{

    int x=0;

    for(int i=start; i<=ending; i++)

    {

        x*=10;

        x+=e[i]-'0';

    }

    return x;

}



int calc(int left, int right)

{

    int paranteza=0;

    for(int i=right; i>=left; i--)

        {

            if(e[i]==')')

                paranteza++;

            if(e[i]=='(')

                paranteza--;

            if((e[i]=='+' || e[i]=='-') && paranteza==0)

        {

            if(e[i]=='+')

                return calc(left, i-1)+calc(i+1, right);

            return calc(left, i-1)-calc(i+1, right);

        }

        }

    paranteza=0;

    for(int i=right; i>=left; i--)

        {

            if(e[i]==')')

                paranteza++;

            if(e[i]=='(')

                paranteza--;

            if((e[i]=='*' || e[i]=='/') && paranteza==0)

        {

            if(e[i]=='*')

                return calc(left, i-1)*calc(i+1, right);

            return calc(left, i-1)/calc(i+1, right);

        }

        }

    if(e[left]=='(' && e[right]==')')

        return calc(left+1, right-1);

    return stringtoint(left, right);

}



int main()

{

    fin>>e;

    int n=strlen(e);

    fout<<calc(0, n-1)<<'\n';

    return 0;

}
