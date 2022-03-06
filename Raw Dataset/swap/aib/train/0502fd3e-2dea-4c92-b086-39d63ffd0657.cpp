#include <iostream>
#include <fstream>
#include <queue>
#include <string>



std::ifstream in("swap.in");
std::ofstream out("swap.out");

int AIB[50005];
std::queue<int> positions[256];

void update(int x, int k) {

    while (x < 50005) {
        AIB[x] += k;
        x += (x & (-x));
    }
}

int query(int x) {

    int sum = 0;

    while (x) {
        sum += (AIB[x]);
        x -= (x & (-x));
    }

    return sum;
}

int main() {
    std::string s1, s2;
    getline(in, s1);
    getline(in, s2);

    for (int i = 0; i < s1.size(); i++)
    {
        positions[s1[i]].push(i);
        update(i + 1, 1);
    }

    int total = 0;
    for (int i = 0; i < s2.size(); i++) {
        char ch = s2[i];

        if (positions[ch].empty()) {
            out << "-1\n";
            return 0;
        }

        int position = positions[ch].front();
        positions[ch].pop();

        total += query(position);
        update(position + 1, -1);
    }

    out << total << "\n";
}
