#include <fstream>
#include <string>
using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

int positions[1000];

int pos_size = 0, hide = 0;

int prefix[20000000];

int main() {

    string pat, str;

    cin>>pat>>str;

    if(pat.size() > str.size()) {

        cout<<"0\n";

        return 0;

    }



    prefix[0] = 0;

    for(int x = 1, p = 0; x<pat.size(); x++) {

        if(pat[x] == pat[p]) {

            p++;

            prefix[x] = p;

        } else {

            while((p != 0) && (pat[x] != pat[p]))

                p = prefix[p - 1];

            if(pat[x] == pat[p])

                p++;

            prefix[x] = p;

        }

    }

    int db = pat.size(), db1 = str.size();



    for(int x = 0, i = 0; x<str.size();) {

        if(str[x + i] != pat[i]) {

            if(i) {

                x = x + i - prefix[i - 1];

                i = prefix[i - 1];

            } else

                x++;

        } else {

            i++;

            if(i == pat.size()) {

                if(pos_size == 1000)

                    hide++;

                else

                    positions[pos_size++] = x;

                x = x + i - prefix[i - 1];

                i = prefix[i - 1];

            }

        }

    }



    cout<<pos_size + hide<<'\n';

    for(int x = 0; x<pos_size; x++) {

        cout<<positions[x]<<' ';

    }

    return 0;

}
