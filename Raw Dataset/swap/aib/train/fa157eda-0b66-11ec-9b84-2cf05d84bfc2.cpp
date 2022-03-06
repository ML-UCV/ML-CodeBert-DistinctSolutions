#include <bits/stdc++.h>




std::ifstream fin ("swap.in");

std::ofstream fout ("swap.out");



int bit[50005];

void update (int pos, int val){

    while (pos < 50005){

        bit[pos] += val;

        pos = (pos | (pos+1));

    }

}



int query (int pos){

    int ans = 0;

    while (pos >= 0){

        ans = ans + bit[pos];

        pos = (pos & (pos+1)) - 1;

    }

    return ans;

}



int main()

{

    std::string s1, s2;

    std::deque <int> pos[26];

    fin >> s1 >> s2;

    int moves = 0, i;

    for (i=0; i<s1.size(); i++){

        pos[s1[i]-'a'].push_back (i);

        update (i, 1);

    }

    for (i=0; i<s2.size(); i++){

        if (pos[s2[i]-'a'].empty() == true){

            fout << -1 << '\n';

            return 0;

        }

        moves = moves + query (pos[s2[i]-'a'].front()) - i - 1;

        update (0, 1);

        update (pos[s2[i]-'a'].front(), -1);

        pos[s2[i]-'a'].pop_front();

    }



    fout << moves << '\n';

    return 0;

}
