#include <fstream>


using namespace std;



const int N = 100000;



char s[N+1];

int p;



int expresie();

int termen();

int factor();



int expresie(){

    int sum=termen();

    while(s[p]=='+' || s[p]=='-'){

        if(s[p]=='+'){

            p++;

            sum+=termen();

        }else{

            p++;

            sum-=termen();

        }

    }

    return sum;

}



int termen(){

    int prod=factor();

    while(s[p]=='*' || s[p]=='/'){

        if(s[p]=='*'){

            p++;

            prod*=factor();

        }else{

            p++;

            prod /= factor();

        }

    }

    return prod;

}



int factor(){

    int semn=1, val=0;

    while(s[p]=='-'){

        p++;

        semn=-semn;

    }

    if(s[p]=='('){

        p++;

        val=expresie();

        p++;

        return semn*val;

    }

    while (s[p]>='0' && s[p]<='9'){

        val=val*10+(s[p]-'0');

        p++;

    }

    return semn*val;

}



int main()

{

    ifstream cin("evaluare.in");

    ofstream cout("evaluare.out");

    cin>>s;

    cout<<expresie();

    cin.close();

    cout.close();

    return 0;

}
