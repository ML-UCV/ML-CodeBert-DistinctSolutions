#include<bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



string mes;

string post;

int i;

stack<long long> nr;

stack<char> op;



long long calc(long long nr1,long long nr2,char operatie)

{



    switch(operatie){

    case '+':

        return nr1+nr2;

    case '-':

        return nr1-nr2;

    case '*':

        return nr1*nr2;

    case '/':

        return nr1/nr2;

    case '^':

        return pow(nr1,nr2);

    }

    return 0;

}



int prec(char ch)

{

    switch(ch)

    {

        case '+':

        case '-':

            return 1;

        case '*':

        case '/':

            return 2;

        case '^':

            return 3;

        case '(':

            return 0;

    }

    return 0;

}



int main()

{

   fin>>mes;



   while(i<mes.size())

   {

       if(isdigit(mes[i]))

       {

           while(isdigit(mes[i]))

           {

               post+=mes[i];

               i++;

           }

           post+=" ";

           i--;

       }

       else if(mes[i] == '(')

       {

           op.push('(');

       }

       else if(mes[i] == ')')

       {

            while(!op.empty() && op.top() != '(')

            {

                post+= op.top();

                post+= " ";

                op.pop();

            }

            if(!op.empty())

                op.pop();

       }

       else

       {

           if(op.empty() || prec(op.top()) < prec(mes[i]) )

           {

               op.push(mes[i]);

           }

           else

           {

               while(!op.empty() && prec(op.top()) >= prec(mes[i]))

               {

                   post+= op.top();

                   post+= " ";

                   op.pop();

               }

               op.push(mes[i]);

           }

       }



       i++;

   }



    while(!op.empty() )

    {

        post+= op.top();

        post+= " ";

        op.pop();

    }





   i = 0;

   long long sol = 0;

   while(i < post.size())

   {

       if(isdigit(post[i]))

       {

           long long numar = 0;

           while(isdigit(post[i]))

           {

               numar = numar * 10 + (post[i]-'0');

               i++;

           }

           nr.push(numar);



       }

       else if(post[i] == '+' || post[i] == '*' || post[i] == '-' || post[i] == '^' || post[i] == '/')

       {



            long long nr1 = nr.top();

            nr.pop();

            long long nr2 = nr.top();

            nr.pop();

            long long res = calc(nr2,nr1,post[i]);

            nr.push(res);



       }



       i++;

   }



   fout<<nr.top();



}
