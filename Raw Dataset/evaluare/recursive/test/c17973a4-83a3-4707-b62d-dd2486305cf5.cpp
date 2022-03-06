#include <fstream>

std::ifstream f("evaluare.in");
std::ofstream g("evaluare.out");

std::string s;
int i,expresie(),termen(),factor();

int expresie(){

    int r = termen();

    while(s[i] == '+' || s[i] == '-'){

        if(s[i] == '+'){
            i++;
            r += termen();
        }else{
            i++;
            r -= termen();
        }
    }

    return r;
}

int termen(){

    int r = factor();

    while(s[i] == '*' || s[i] == '/'){

        if(s[i] == '*'){
            i++;
            r *= factor();
        }else{
            i++;
            r /= factor();
        }
    }

    return r;
}

int factor(){

    int r = 0;

    if(s[i] == '('){

        i++;
        r = expresie();
        i++;

        return r;
    }else{

        while(s[i] >= '0' && s[i] <= '9')
            r = r * 10 + (s[i++] - '0');

        return r;
    }

    return r;
}

int main(){

    f >> s;

    g << expresie();

    return 0;
}
