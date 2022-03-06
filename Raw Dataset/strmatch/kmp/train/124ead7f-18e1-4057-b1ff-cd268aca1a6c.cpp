#include <iostream>
#include<fstream>
#include<string>
#include <vector>


using namespace std;



int main() {

 string minta, str;

 ifstream fin("strmatch.in");

 ofstream fout("strmatch.out");

 getline(fin, minta);

 getline(fin, str);

 int minta_hossz = minta.size();

 int str_hossz = str.size();

    int db = 0;

    vector<int> a;
    int* prefix;

    prefix = new int[minta_hossz + 1];



    prefix[1] = 0;

    int k = 0;

    for (int i = 1; i < minta_hossz; i++) {

        while (k > 0 && minta[k] != minta[i])

            k = prefix[k];



        if (minta[k] == minta[i])

            k++;



        prefix[i + 1] = k;

    }

    k = 0;

    db = 0;

    for (int i = 0; i < str_hossz; i++) {

        while (k > 0 && minta[k] != str[i])

            k = prefix[k];

        if (minta[k] == str[i])

            k++;

        if (k == minta_hossz) {

            a.push_back(i - minta_hossz + 1);

            db++;

        }

    }

    fout << db << "\n";

    if (db > 1000) {

        for (int i = 0; i <= 999; i++) {

            fout << a[i] << " ";

        }

    }

    else {

        for (auto& e : a) {

            fout << e << " ";

        }

    }

}
