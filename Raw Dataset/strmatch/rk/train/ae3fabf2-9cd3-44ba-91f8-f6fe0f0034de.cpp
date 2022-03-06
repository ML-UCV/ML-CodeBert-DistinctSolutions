#include <fstream>
#include <string>
#include <vector>






using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



struct RollingHash

{

    int a, mod, aMax;

    int value;



    RollingHash(int a, int mod)

    {

        this->a = a;

        this->mod = mod;

        aMax = 1;

        value = 0;

    }



    void initHash(const string &s)

    {

        for(int i = 0; i<s.size(); i++)

        {

            value = (value * a + s[i])%mod;

            if(i)

            aMax = (aMax * a)%mod;

        }

    }



    void roll(char in, char out)

    {

        value = ((value - (out * aMax) % mod + mod) * a + in) % mod;

    }



    bool operator ==(RollingHash other)

    {

        return value == other.value;

    }

};



vector<int> sol;

int k;



void debug(RollingHash r1, RollingHash r2, RollingHash r3, RollingHash r4)

{

    g<<r1.value<<" "<<r2.value<<"\n";

    g<<r3.value<<" "<<r4.value<<"\n";

    g<<"\n";

}



void solve()

{

    RollingHash pattern1 = RollingHash(31, 100003), pattern2 = RollingHash(31, 100109);

    RollingHash text1 = RollingHash(31, 100003), text2 = RollingHash(31, 100109);



    string pattern, text;

    f>>pattern>>text;

    if(pattern.size() > text.size())

    {

        return;

    }



    pattern1.initHash(pattern);

    pattern2.initHash(pattern);

    text1.initHash(text.substr(0, pattern.size()));

    text2.initHash(text.substr(0, pattern.size()));



    if(pattern1 == text1 && pattern2 == text2)

    {

        k++;

        sol.push_back(0);

    }

    for(int i = pattern.size(); i < text.size(); i++)

    {

        text1.roll(text[i], text[i - pattern.size()]);

        text2.roll(text[i], text[i - pattern.size()]);

        if(pattern1 == text1 && pattern2 == text2)

        {

            k++;

            if(sol.size() < 1000)

                sol.push_back(i - pattern.size() + 1);

        }

    }

}





void afisare()

{

    g<<k<<"\n";

    for(int i = 0; i<sol.size(); i++)

        g<<sol[i]<<" ";

}



int main()

{

    solve();

    afisare();

    return 0;

}
