#include <iostream>
#include <fstream>


const int MAXN = 4e6 + 4;



using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



string s;

string a,b;

int z[MAXN];



void Z(){

    int n = s.size();

    int l = 0,r = 0;

    int cate_sunt = 0;

    z[0] = s.size();

    for(int i = 1; i < n; i++){

        if(i > r){

            int cnt = 0;

            while(i + cnt < n && s[i + cnt] == s[cnt])

                cnt++;

            z[i] = cnt;

            l = i;

            r = i + cnt - 1;

        }else{

            if(z[i - l] + i < r){

                z[i] = z[i - l];

            }else{

                z[i] = min(z[i - l],r - i + 1);

                int capat = i + z[i],cnt = 0;

                int inceput = z[i];



                while(capat + cnt < n && s[capat + cnt] == s[cnt + inceput])

                    cnt++;

                z[i] += cnt;

                l = i;

                r = capat + cnt - 1;

            }

        }

        if(z[i] == a.size()){

            cate_sunt++;

        }

    }

    out<<cate_sunt<<"\n";

    int cnt = 0;

    for(int i = 0; i < n; i++){

        if(z[i] == a.size() && cnt <= 999){

            cnt++;

            out<<i - a.size() - 1<<" ";

        }

    }

}



int main()

{



    in>>a>>b;







    s = a + '#' + b;

    Z();

    return 0;

}
