#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;

std::ifstream fin("evaluare.in");
std::ofstream fout("evaluare.out");

int main() {
    string str;
    fin >> str; str += '?';

    char prev = '?';
    vector<int> stVal;
    vector<char> stOpr;

    auto pop = [&]() {
        int nr = stVal.back();
        stVal.pop_back();
        if (stOpr.back() == '+') stVal.back() += nr; else
        if (stOpr.back() == '-') stVal.back() -= nr; else
        if (stOpr.back() == '*') stVal.back() *= nr; else
        if (stOpr.back() == '/') stVal.back() /= nr;
        stOpr.pop_back();
    };

    for (char chr : str) {
        if ('0' <= chr && chr <= '9') {
            if ('0' <= prev && prev <= '9')
                stVal.back() = stVal.back() * 10 + chr - '0';
            else
                stVal.push_back(chr - '0');
        }
        else {
            if ((('0' <= prev && prev <= '9') || prev == ')') && !stOpr.empty()) {
                if (stOpr.back() == '*' || stOpr.back() == '/')
                    pop();
                if ((stOpr.back() == '+' || stOpr.back() == '-') && chr != '*' && chr != '/')
                    pop();
            }
            if (chr == ')')
                stOpr.pop_back();
            else
                stOpr.push_back(chr);
        }
        prev = chr;
    }
    fout << stVal[0] << '\n';

    fout.close();
    return 0;
}
