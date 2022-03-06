#include <fstream>


using namespace std;

ifstream cin("evaluare.in");

ofstream cout("evaluare.out");

int n,ind;

string s;

int eval();

int numar();

int main()

{

    cin>>s;

    n=s.size();

    ind=0;

    cout<<eval();

    return 0;

}

int numar(){

    int num=0;

    while(s[ind]<='9' and s[ind]>='0' and ind<n){

        num*=10;

        num+=s[ind]-'0';

        ind++;

    }



    return num;

}

int eval(){

    int sum=0,semn=1,prod=1;

    while(ind<n){



        if(s[ind]=='-'){

            semn=-1;

            ind++;

            continue;

        }

        if(s[ind]=='+'){

            semn=1;

            ind++;

            continue;

        }

        if(s[ind]<='9' and s[ind]>='0'){

            prod=numar();

            while(s[ind]=='*' or s[ind]=='/'){

                if(s[ind]=='/'){

                    ind++;

                    if(s[ind]=='('){

                        ind++;

                        prod/=eval();

                    }

                    else{

                        prod/=numar();

                    }

                }

                else{

                    ind++;

                    if(s[ind]=='('){

                        ind++;

                        prod*=eval();

                    }

                    else

                        prod*=numar();

                }

            }

            sum+=semn*prod;

            semn=1;

            continue;

        }

        if(s[ind]==')'){

            ind++;

            return sum;

        }

        if(s[ind]=='('){

            ind++;

            prod=eval();

            while(s[ind]=='*' or s[ind]=='/'){

                if(s[ind]=='/'){

                    ind++;

                    if(s[ind]=='('){

                        ind++;

                        prod/=eval();

                    }

                    else

                        prod/=numar();

                }

                else{

                    ind++;

                    if(s[ind]=='('){

                        ind++;

                        prod*=eval();

                    }

                    else

                        prod*=numar();

                }

            }

            sum+=semn*prod;

            semn=1;

        }

    }

    return sum;

}
