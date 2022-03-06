#include <fstream>
#include <string>


using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



char s[100005];

int p=1;

string c;





int expresie();

int termen();

int fact();

int expresie(){

    int sum=termen();

    while(s[p]=='+'||s[p]=='-'){

        if(s[p]=='+'){

            p++;

            sum+=termen();

        }

        else{

            p++;

            sum-=termen();

        }

    }

    return sum;

}

int termen(){

    int prod=fact();

    while(s[p]=='*'||s[p]=='/'){

        if(s[p]=='*'){

            p++;

            prod*=fact();

        }

        else{

            p++;

            prod/=fact();

        }

    }

    return prod;

}

int fact(){

    int val=0,semn=1;

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

    while(s[p]>='0' && s[p]<='9'){

        val=val*10+(s[p]-'0');

        p++;

    }

    return semn*val;

}



int main()

{

    cin>>c;

    for(int i=0;i<=c.size();i++){

        s[i+1]=c[i];

    }

    cout<<expresie();

    return 0;

}
