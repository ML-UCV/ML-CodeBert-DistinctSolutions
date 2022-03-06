#include <fstream>
#include <cstring>
#include <string>


using namespace std;

ifstream in ("evaluare.in");
ofstream out("evaluare.out");

int n, globalCnt;

char str[100002];

int termen();
int factor();
int evalueaza();
int numar();

int main(int argc, const char * argv[]) {
    in>>str;

    int sol = evalueaza();

    out<<sol;

    return 0;
}

int evalueaza(){
    int x = termen();
    while(str[globalCnt] == '+' || str[globalCnt] == '-'){
        if(str[globalCnt] == '+'){
            ++ globalCnt;
            x += termen();
        }
        else{
            ++ globalCnt;
            x-= termen();
        }
    }
    return x;
}

int termen(){
    int x = factor();
    while(str[globalCnt] == '*' || str[globalCnt] == '/'){
        if(str[globalCnt] == '*'){
            ++ globalCnt;
            x *= factor();
        }
        else{
            ++ globalCnt;
            x /= factor();
        }
    }
    return x;
}

int factor(){
    int x;
    if(str[globalCnt] == '('){
        ++ globalCnt;
        x = evalueaza();
        ++ globalCnt;
    }
    else{
        x = numar();
    }
    return x;

}

int numar(){
    int x = 0;
    while(str[globalCnt] <= '9'&& str[globalCnt] >= '0'){
        x = x * 10 + str[globalCnt] - '0';
        ++ globalCnt;
    }
    return x;
}
