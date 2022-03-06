#include <fstream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;
ifstream f ("evaluare.in");
ofstream g ("evaluare.out");
char buff [5 + (int)1e6];
short x [300];
stack <int> st , ans;
vector <int> eval;
void solve (int semn){
    int b = ans . top ();
    ans . pop ();
    int a = ans . top ();
    ans . pop ();
    if (semn == -3)
        ans . push (a * b);
    if (semn == -4)
        ans . push (a / b);
    if (semn == -5)
        ans . push (a + b);
    if (semn == -6)
        ans . push (a - b);
    return;

}
bool check (int x , int y){
    if (x >= y)
        return true;
    if (x == -6 && y == -5)
        return true;
    if (x == -4 && y == -3)
        return true;
    return false;
}
int main()
{
    x ['+'] = -5 , x ['-'] = -6 , x ['*'] = -3 , x ['/'] = -4 , x ['('] = -1 , x [')'] = -2;
    f >> buff;
    int a;
    for(int i = 0 ; buff [i] ; i){
        if (isdigit (buff [i])){
            a = 0;
            while (isdigit (buff [i]))
                a = a * 10 + (buff [i ++] - '0');
            eval . push_back (a);
        }
        else{
            int val = x [buff [i]];
            if (val == -1)
                st . push (val);
            else
                if (val == -2){
                    while (0 < st . size () && st . top () != -1){
                        eval . push_back (st . top ());
                        st . pop ();
                    }
                    if (0 < st . size () && st . top () == -1)
                        st . pop ();
                }
                else{
                    while (0 < st . size () && check (st . top () , val) && st . top () != -1){
                            eval . push_back (st . top ());
                            st . pop ();
                    }
                    st . push (val);
                }
            ++ i;
        }
    }
    while (0 < st . size ())
        eval . push_back (st . top ()) , st . pop ();
    for(auto x : eval){
        if (x < 0)
            solve (x);
        else
            ans . push (x);
    }
    g << ans . top ();
    return 0;
}
