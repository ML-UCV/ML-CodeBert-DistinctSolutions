#include <fstream>
#include <string>

std::ifstream fin("evaluare.in");
std::ofstream fout("evaluare.out");

class ecuatie {
public:
    ecuatie() {
        this->rezultat = 0;
        this->pozitie = 0;
        this->este_rezolvat = 0;
        this->str_ecuatie.clear();
    }

    ecuatie(const char* str) {
        this->rezultat = 0;
        this->pozitie = 0;
        this->este_rezolvat = 0;
        this->str_ecuatie.clear();
        this->str_ecuatie.append(str);
    }

    ecuatie(std::string str) {
        this->rezultat = 0;
        this->pozitie = 0;
        this->este_rezolvat = 0;
        this->str_ecuatie.clear();
        this->str_ecuatie = str;
    }

    void schimba_ecuatie(const char* str) {
        this->rezultat = 0;
        this->pozitie = 0;
        this->este_rezolvat = 0;
        this->str_ecuatie.clear();
        this->str_ecuatie.append(str);
    }

    void schimba_ecuatie(std::string str) {
        this->rezultat = 0;
        this->pozitie = 0;
        this->este_rezolvat = 0;
        this->str_ecuatie.clear();
        this->str_ecuatie = str;
    }

    long long rezolva() {
        if (this->este_rezolvat == 0) {
            this->este_rezolvat = 1;
            this->pozitie = 0;
            this->rezultat = eval();
        }

        return this->rezultat;
    }

private:
    std::size_t pozitie;
    std::string str_ecuatie;
    bool este_rezolvat;
    long long rezultat;

    long long eval() {
        long long r = termen();

        while (this->str_ecuatie[this->pozitie] == '+' || this->str_ecuatie[this->pozitie] == '-') {
            switch (this->str_ecuatie[this->pozitie]) {
            case '+':
                this->pozitie++;
                r = r + termen();
                break;
            case '-':
                this->pozitie++;
                r = r - termen();
                break;
            }
        }

        return r;
    }

    long long termen()
    {
        long long r = factor();

        while (this->str_ecuatie[this->pozitie] == '*' || this->str_ecuatie[this->pozitie] == '/') {
            switch (this->str_ecuatie[this->pozitie]) {
            case '*':
                this->pozitie++;
                r = r * factor();
                break;

            case '/':
                this->pozitie++;
                r = r / factor();
                break;
            }
        }

        return r;
    }

    long long factor()
    {
        long long r = 0;

        if (this->str_ecuatie[this->pozitie] == '(')
        {
            this->pozitie++;
            r = eval();
            this->pozitie++;
        }
        else {
            while (this->str_ecuatie[this->pozitie] >= '0' && this->str_ecuatie[this->pozitie] <= '9')
            {
                r = r * 10 + (long long)(this->str_ecuatie[this->pozitie]) - (long long)('0');
                this->pozitie++;
            }
        }

        return r;
    }

};

std::string str;

int main() {
    std::getline(fin, str);
    fout << ecuatie(str).rezolva() << '\n';
    return 0;
}
