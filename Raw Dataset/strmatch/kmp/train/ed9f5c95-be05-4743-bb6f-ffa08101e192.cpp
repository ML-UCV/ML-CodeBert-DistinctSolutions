#include <fstream>
#include <string>
#include <vector>
#include <list>


using namespace std;



const int MAX_NO_POS = 1000;



void buildSuffixTable(string & pattern, vector<int> & suffixTable) {

    int len = 0;

    int i = 1;

    while (i < pattern.size()) {

        if (pattern[i] == pattern[len]) {

            len++;

            suffixTable[i] = len;

            i++;

        } else if (len > 0) {

            len = suffixTable[len - 1];

        } else {

            suffixTable[i] = 0;

            i++;

        }

    }

}



void kmp(string & A, string & B, vector<int> & suffixTable, int & n, list<int> & ans) {

    if (A.size() > B.size()) {

        return;

    }

    int len = 0;

    int i = 0;

    while (i < B.size()) {

        if (B[i] == A[len]) {

            len++;

            if (len == A.size()) {

                n++;

                if (n <= MAX_NO_POS) {

                    ans.push_back(i - len + 1);

                }

                len = suffixTable[len - 1];

            }

            i++;

        } else if (len > 0) {

            len = suffixTable[len - 1];

        } else {

            len = 0;

            i++;

        }

    }

}



int main() {

    ifstream fin;

    ofstream fout;

    string A, B;



    fin.open("strmatch.in");

    fin >> A >> B;

    fin.close();



    vector<int> suffixTable(A.size(), 0);

    buildSuffixTable(A, suffixTable);



    int n = 0;

    list<int> ans;

    kmp(A, B, suffixTable, n, ans);



    fout.open("strmatch.out");

    fout << n << endl;

    for (auto it = ans.begin(); it != ans.end(); ++it) {

        fout << *it << " ";

    }

    fout.close();



    ans.clear();



    return 0;

}
