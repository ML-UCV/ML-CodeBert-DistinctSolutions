#include <fstream>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

char s[100005], st1[50001];

int i,st2[50001],vf1,vf2, pr[256];

int calcul(int a, int b, char op){

   switch(op){

   case '+':return a+b;

   case '-': return a-b;

    case '*': return a*b;

     case '/':return a/b;

   }

}

int main()

{

    fin.getline(s,100001);

    pr['+']=pr['-']=1;

    pr['*']=pr['/']=2;

    for(i=0;s[i]!=0;i++)

        if(s[i]=='(')

             st1[++vf1]=s[i];

        else

            if(s[i]==')'){

                 while(st1[vf1]!='('){

                      int rez=calcul(st2[vf2-1],st2[vf2],st1[vf1]);

                        vf1--;

                        vf2--;

                        st2[vf2]=rez;

                       }

                    vf1--;

            }

          else

              if(s[i]>='0'&&s[i]<='9'){

                    int nr=0;

                    while(s[i]>='0'&&s[i]<='9'){

                        nr=nr*10+s[i]-'0';

  i++;

                    }

                    i--;

                     st2[++vf2]=nr;

                    }

                else

                {

                    while(vf1>0&&pr[st1[vf1]]>=pr[s[i]]){

                       int rez=calcul(st2[vf2-1],st2[vf2],st1[vf1]);

                         vf1--;

                         vf2--;

                        st2[vf2]=rez;

                    }

                    st1[++vf1]=s[i];

                }

                   while(vf1>0){

       int rez=calcul(st2[vf2-1],st2[vf2],st1[vf1]);

          vf1--;

          vf2--;

          st2[vf2]=rez;

    }

    fout<<st2[vf2];





    return 0;

}
