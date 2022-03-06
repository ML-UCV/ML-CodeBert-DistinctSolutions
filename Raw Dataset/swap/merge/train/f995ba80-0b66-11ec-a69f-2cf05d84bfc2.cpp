#include <bits/stdc++.h>




std::ifstream fin ("swap.in");

std::ofstream fout ("swap.out");



int moves=0;



void merge (std::vector <int> &arr, int left, int right){

    if (left == right)

        return;

    int mid = (left + right) / 2;

    merge (arr, left, mid);

    merge (arr, mid+1, right);



    std::vector <int> aux;

    int i=left, j=mid+1;

    while (i <= mid or j <=right){

        if (i > mid)

            aux.push_back (arr[j++]), moves = moves + (mid - i + 1);

        else if (j > right)

            aux.push_back (arr[i++]);

        else if (arr[i] <= arr[j])

            aux.push_back (arr[i++]);

        else

            aux.push_back (arr[j++]), moves = moves + (mid - i + 1);

    }

    for (i=left; i<=right; i++)

        arr[i] = aux[i-left];

}



int main()

{

    std::string s1, s2;



    fin >> s1 >> s2;

    std::vector <int> v(s1.size());

    std::deque <int> pos[26];

    for (int i=0; i<s1.size(); i++)

        pos[s1[i]-'a'].push_back (i);

    for (int i=0; i<s2.size(); i++){

        char chr = s2[i] - 'a';

        if (pos[chr].empty() == true){

            fout << -1 << '\n';

            return 0;

        }

        v[pos[chr].front()] = i;

        pos[chr].pop_front();

    }



    merge (v, 0, v.size()-1);

    fout << moves << '\n';

    return 0;

}
