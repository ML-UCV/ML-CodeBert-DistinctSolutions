#include <iostream>
#include <fstream>
#include <stack>
#include <queue>






using namespace std;





ifstream f("evaluare.in");

ofstream g("evaluare.out");



class ExpresionEvaluator

{

private:

    const int INF=1e9;

    int res;

    stack <int> s;

    queue <pair <bool,int>> q;



    int priorities[255]={0};



    int getRes(int x,int y,char op)

    {

        switch(op)

        {

        case '+':

            return x+y;

        case '-':

            return x-y;

        case '*':

            return x*y;

        case '/':

            return x/y;

        }

    }



    bool isNumber(char c)

    {

        return (c<='9' && c>='0');

    }



    int getNumber(char *&p)

    {

        int nr=0;

        while(isNumber(*p))

        {

            nr=nr*10+(*p-'0');

            ++p;

        }



        return nr;

    }



    void buildPostfix(char *v)

    {

        char *p=v;

        while(*p!='\0')

        {

            if(isNumber(*p))

                q.push(make_pair(0,getNumber(p)));

            else

                {

                if(*p=='(')

                    s.push(*p);

                else if(*p==')')

                {

                    while(s.top()!='(')

                       {

                        q.push(make_pair(1,s.top()));

                        s.pop();

                       }

                    s.pop();



                }

                else

                {

                    while(!s.empty() && priorities[s.top()]>=priorities[*p])

                    {

                        q.push(make_pair(1,s.top()));

                        s.pop();

                    }

                    s.push(*p);

                }



                ++p;

                }

        }

        while(!s.empty())

        {

            q.push(make_pair(1,s.top()));

            s.pop();

        }

    }



public:



    int evaluate()

    {

        if(res!=INF)

            return res;

        while(!q.empty())

        {

            if(q.front().first==0)

                s.push(q.front().second);

            else

            {

                int y=s.top();

                s.pop();

                int x=s.top();

                s.pop();

                s.push(getRes(x,y,(char)q.front().second));

            }



            q.pop();

        }

        res=s.top();

        s.pop();

        return res;

    }



    void printPostfix()

    {

        queue <pair <bool,int> >e=q;

        while(!e.empty())

        {

            if(e.front().first)

                cout<<(char)e.front().second<<' ';

            else

                cout<<e.front().second<<' ';

            e.pop();

        }

    }



    ExpresionEvaluator(char *v)

    {

        res=INF;

        priorities['+']=1;

        priorities['-']=1;

        priorities['*']=2;

        priorities['/']=2;

        buildPostfix(v);



    }

};







int main()

{

    char v[100001];

    f>>v;



    ExpresionEvaluator exp(v);

    g<<exp.evaluate();



    return 0;

}
