#include <bits/stdc++.h>
std::pair <int, int> hash(const std::string &str) {

    std::pair <int, int> ans(0, 0);

    int p1 = 1, p2 = 1;

    for (int i=str.size()-1; i>=0; --i)

        ans.first = (ans.first + str[i]*p1)%100021, p1 = (p1*73)%100021,

        ans.second = (ans.second + str[i]*p2)%100007, p2 = (p2*73)%100007;

    return ans;

}



std::string t, s;

std::pair <int, int> hash_t;



std::ifstream input ("strmatch.in");

std::ofstream output("strmatch.out");



int main()

{

    input >> t >> s;

    int len_t = t.size();

    hash_t = hash(t);



    if (t.size() > s.size()) {

        output << 0;

        return 0;

    }



    int pp1 = 1, pp2 = 1;

    for (int i=0; i<len_t; ++i)

        pp1 = (pp1*73)%100021, pp2 = (pp2*73)%100007;



    std::vector <int> sol;

    std::pair <int, int> val = hash(s.substr(0, len_t));

    if (val == hash_t) sol.push_back(0);

    for (int i=len_t; i<s.size(); ++i) {

        val.first = (val.first*73 + s[i] - s[i-len_t]*pp1 % 100021 + 100021)%100021;

        val.second = (val.second*73 + s[i] - s[i-len_t]*pp2 % 100007 + 100007)%100007;

        if (val == hash_t) sol.push_back(i-len_t+1);

    }



    output << sol.size() << '\n';

    for (int i=0; i<sol.size() && i<1000; ++i)

        output << sol[i] << ' ';



    return 0;

}
