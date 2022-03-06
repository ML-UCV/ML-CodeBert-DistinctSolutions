#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>




unsigned int z[4000002];



std::string a, b;



void compute_z_func(std::string& a)

{

    unsigned int r = 0, l = 0;

    for (unsigned int i = 1; i < a.length(); ++i)

    {

        if (i <= r)

        {

            z[i] = std::min(r - i + 1, z[i - l]);

        }

        while (i + z[i] < a.length() && a[z[i]] == a[i + z[i]])

            ++z[i];

        if (i + z[i] - 1 > r)

        {

            l = i;

            r = i + z[i] - 1;

        }

    }

}







int main(){



    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);



    std::cin >> a >> b;

    int n = a.length();

    int m = b.length();

    a += "#" + b;

    compute_z_func(a);



    int res = 0;

    for (int i = n + 1; i < a.length(); ++i)

        if (z[i] == n)

            ++res;



    std::cout << res << "\n";



    int cnt = 0;



    for (int i = n + 1; cnt < 1000 && i < a.length() + 1; ++i)

        if (z[i] == n)

        {

            std::cout << i - n - 1 << " ";

            ++cnt;

        }





 return 0;

}
