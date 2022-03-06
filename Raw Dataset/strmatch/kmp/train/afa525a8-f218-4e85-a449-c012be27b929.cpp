#include<fstream>
#include<string>
#include<vector>
using namespace std;



int prefix[2000010];

int nr = 0;

vector<int> v;



void make_prefix(string match)

{

    prefix[0] = 0;



    for (int i = 1; i < match.size(); ++i)

    {

        int s = prefix[i - 1];



        while (s != 0 && match[s] != match[i])

        {

            s = prefix[s - 1];

        }



        if (match[s] == match[i])

        {

            prefix[i] = s + 1;

        }

    }

}



void print_matches(string search, string match)

{

    int last_state = 0;

    for (int i = 0; i < search.size(); ++i)

    {

        while (last_state != 0 && search[i] != match[last_state])

        {

            last_state = prefix[last_state - 1];

        }



        if (search[i] == match[last_state])

        {

            last_state++;



            if (last_state == match.size())

            {

                last_state = prefix[last_state - 1];

                nr++;

                if (v.size() < 1000)

                {



                    v.push_back(i - match.size() + 1);

                }

            }

        }

    }

}



ifstream in("strmatch.in");

ofstream out("strmatch.out");



int main()

{

    string match;

    string search;



    in >> match >> search;



    make_prefix(match);



    print_matches(search, match);



    out << nr<< "\n";



    for (int i = 0; i < v.size(); ++i)

    {

        out << v[i] << " ";

    }

}
