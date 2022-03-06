#include <fstream>
#include <cstring>

using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");



char text[2000001], pattern[2000001];
int t, p;
int n, result[2000001], lps[2000001];


void calculateLPSArray() {
    int lenght = 0;
    lps[0] = 0;
    for (int i = 1; i < p; ++i) {
        if (pattern[lenght] == pattern[i])
            lps[i] = ++lenght;
        else if (lenght)
            lenght = lps[lenght - 1], i--;
        else
            lps[i] = 0;
    }
}

void printLPSArray() {
    for (int i = 0; i < p; i++)
        g << lps[i] << " ";
    g << endl;
}

void findPatternMatches() {
    calculateLPSArray();
    int j = 0;
    for (int i = 0; i < t;) {
        if (pattern[j] == text[i])
            j++, i++;
        else if (j == p)
            result[n++] = i - p, j = lps[j - 1];
        else if (j)
            j = lps[j - 1];
        else
            i++;
    }
    if (j == p)
        result[n++] = t - p;
}

void printResult() {
    g << n << endl;
    if (n > 1000)
        n = 1000;
    for (int i = 0; i < n; i++)
        g << result[i] << " ";
}

int main() {
    f.getline(pattern, 2000001);
    f.getline(text, 2000001);
    p = strlen(pattern);
    t = strlen(text);

    findPatternMatches();
    printResult();

    return 0;
}
