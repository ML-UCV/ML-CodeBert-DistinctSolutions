#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("strmatch.in");
ofstream fout("strmatch.out");
int z[2 * 2000002], N;
void makeZarr(string str) {
    N = str.length();
    long l, r;
    l = r = 0;
    for (long i = 1; i < N; ++i) {
        if (i > r) {
            long j = 0;
            r = l = i;
            while (r < N && str[j] == str[r]) {
                ++j;
                ++r;
            }
            r--;
            z[i] = r - l + 1;
        }
        else {
            long k = i - l;
            if (z[k] < r - i) {
                z[i] = z[k];
            }
            else {
                long j = r - i;
                l = i;
                while (r < N && str[j] == str[r]) {
                    ++j;
                    ++r;
                }
                r--;
                z[i] = r - l + 1;
            }
        }
    }
}
int main()
{
    string word, s;
    fin >> word >> s;
    long len = word.length(), con = 0, nr = 0;
    makeZarr(word + "?" + s);
    for (long i = len; i < N; ++i) {
        if (z[i] == len) {
            ++con;
        }
    }
    fout << con << "\n";
    for (long i = len; i < N; ++i) {
        if (z[i] == len) {
            fout << i - len - 1 << " ";
            ++nr;
        }
        if (nr >= 1000)
            break;
    }
    return 0;
}
