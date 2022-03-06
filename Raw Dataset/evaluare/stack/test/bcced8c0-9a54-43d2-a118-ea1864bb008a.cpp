#include <fstream>
#include <stack>
#include <queue>

using namespace std;
stack <char> ch;
queue <int> st;
int pr[300],hashh[300],f[10],v[100005];
int main()
{
    ifstream cin("evaluare.in");
    ofstream cout("evaluare.out");
    string s;
    cin>>s;
    int n=s.size();
    pr['+']=1;
    pr['-']=1;
    pr['/']=2;
    pr['*']=2;
    hashh['+']=1000000001;
    hashh['-']=1000000002;
    hashh['/']=1000000003;
    hashh['*']=1000000004;
    hashh['(']=1000000006;
    hashh[')']=1000000007;
    f[1]='+';
    f[2]='-';
    f[3]='/';
    f[4]='*';
    f[6]='(';
    f[7]=')';

    int i;


    for(i=0;i<n;i++){
        bool ok=0;
        int nr=0;

        while(s[i]<='9' and s[i]>='0' and i<n){
            nr=nr*10+(s[i]-'0');

            ok=1;
            i++;
        }

        if(ok==1){
            i--;
        }


        if(ok==1){

            st.push(nr);
        }
        else{


            if(s[i]=='('){
                ch.push(s[i]);
            }
            else{
                if(s[i]==')'){

                    while(ch.top()!='('){
                        st.push(hashh[ch.top()]);
                        ch.pop();
                    }
                    ch.pop();
                }
                else{


                    if(ch.empty()==false)
                    while(pr[ch.top()]>=pr[s[i]] and ch.top()!='('){
                        st.push(hashh[ch.top()]);
                        ch.pop();
                        if(ch.empty()==true)
                            break;
                    }
                    ch.push(s[i]);
                }

            }

        }


    }

    int a;
    while(ch.empty()==false){
        st.push(hashh[ch.top()]);
        ch.pop();
    }
    int cnt=0;
    while(st.empty()==false){
        a=st.front();
        st.pop();
        if(a>=1000000000){

            if(f[a-1000000000]=='+'){
                cnt--;
                v[cnt]=v[cnt]+v[cnt+1];
            }
            if(f[a-1000000000]=='-'){
                cnt--;
                v[cnt]=v[cnt]-v[cnt+1];
            }
            if(f[a-1000000000]=='*'){
                cnt--;
                v[cnt]=v[cnt]*v[cnt+1];
            }
            if(f[a-1000000000]=='/'){
                cnt--;
                v[cnt]=v[cnt]/v[cnt+1];
            }
        }
        else{

            v[++cnt]=a;
        }
    }

    cout<<v[1];
    return 0;
}
