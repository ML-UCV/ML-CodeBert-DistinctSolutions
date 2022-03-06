#include <fstream>
#include <string>

using namespace std;

int DfsAddSub(const string &str, size_t &pos);

int Number(const string &str, size_t &pos)
{
    if (str[pos] == '(') {
        pos += 1;
        auto num = DfsAddSub(str, pos);
        pos += 1;
        return num;
    }

    int num = 0;
    while (pos < str.size() && isdigit(str[pos])) {
        num = num * 10 + (str[pos] - '0');
        pos += 1;
    }
    return num;
}

int DfsMultDiv(const string &str, size_t &pos)
{
    int res = Number(str, pos);
    while (pos < str.size() && (str[pos] == '*' || str[pos] == '/')) {
        char sign = str[pos];
        pos += 1;

        if (sign == '*') {
            res *= Number(str, pos);
        } else {
            res /= Number(str, pos);
        }
    }
    return res;
}

int DfsAddSub(const string &str, size_t &pos)
{
    int res = DfsMultDiv(str, pos);
    while (pos < str.size() && (str[pos] == '+' || str[pos] == '-')) {
        int sign = (str[pos] == '+' ? 1 : -1);
        pos += 1;
        res += sign * DfsMultDiv(str, pos);
    }
    return res;
}

int Evaluate(const string &str)
{
    size_t pos = 0;
    return DfsAddSub(str, pos);
}

int main()
{
    ifstream fin("evaluare.in");
    ofstream fout("evaluare.out");

    string str;
    getline(fin, str);

    auto res = Evaluate(str);
    fout << res << "\n";

    return 0;
}
