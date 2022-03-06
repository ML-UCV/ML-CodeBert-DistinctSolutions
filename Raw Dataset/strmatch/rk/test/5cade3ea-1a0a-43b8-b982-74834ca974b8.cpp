#include <fstream>
#include <string>
#include <vector>
#include <list>


using namespace std;



const int MAX_NO_POS = 1000;

const int BASE = 62;

const int MOD = 10007;

const int MOD2 = 10009;



void rabinKarp(string & A, string & B, int & n, list<int> & ans) {

    if (A.size() > B.size()) {

        return;

    }



    int hashWindow = 0;

    int hashWindow2 = 0;

    int hashPattern = 0;

    int hashPattern2 = 0;

    int pow = 1;

    int pow2 = 1;

    for (int i = 0; i < A.size() - 1; i++) {

        pow = (pow * BASE) % MOD;

        pow2 = (pow2 * BASE) % MOD2;

    }

    for (int i = 0; i < A.size(); i++) {

        hashWindow = (BASE * hashWindow + B[i]) % MOD;

        hashWindow2 = (BASE * hashWindow2 + B[i]) % MOD2;

        hashPattern = (BASE * hashPattern + A[i]) % MOD;

        hashPattern2 = (BASE * hashPattern2 + A[i]) % MOD2;

    }

    if (hashWindow == hashPattern && hashWindow2 == hashPattern2) {

        n++;

        ans.push_back(0);

    }



    for (int i = A.size(); i < B.size(); i++) {

        hashWindow = (BASE * (hashWindow - (pow * B[i - A.size()])) + B[i]) % MOD;

        hashWindow2 = (BASE * (hashWindow2 - (pow2 * B[i - A.size()])) + B[i]) % MOD2;

        hashWindow += (hashWindow < 0) ? MOD : 0;

        hashWindow2 += (hashWindow2 < 0) ? MOD2 : 0;

        if (hashWindow == hashPattern && hashWindow2 == hashPattern2) {

            n++;

            if (n <= MAX_NO_POS) {

                ans.push_back(i - A.size() + 1);

            }

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



    int n = 0;

    list<int> ans;

    rabinKarp(A, B, n, ans);



    fout.open("strmatch.out");

    fout << n << endl;

    for (auto it = ans.begin(); it != ans.end(); ++it) {

        fout << *it << " ";

    }

    fout.close();



    ans.clear();



    return 0;

}
