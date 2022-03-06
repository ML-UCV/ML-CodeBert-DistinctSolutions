#include <fstream>
using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int exp(), term(), fact();



int i;

char s[100010];



int exp(){

    int r=term();



    while(s[i]=='+' || s[i]=='-'){

        i++;

        if(s[i-1]=='+')

            r+=term();

        else

            r-=term();

    }



    return r;

}



int term(){

    int r=fact();



    while(s[i]=='*' || s[i]=='/'){

        i++;

        if(s[i-1]=='*')

            r*=fact();

        else

            r/=fact();

    }



    return r;

}



int fact(){

    int semn=1;



    if(s[i]=='-')

        semn=-1,i++;



    int r;



    if(s[i]=='('){

        i++;

        r=exp();

        i++;

    }else{

        r=0;

        while(s[i]>='0' && s[i]<='9')

            r=r*10+s[i++]-'0';

    }



    return r*semn;

}



int main(){

    fin>>s;

    fout<<exp();



    return 0;

}
