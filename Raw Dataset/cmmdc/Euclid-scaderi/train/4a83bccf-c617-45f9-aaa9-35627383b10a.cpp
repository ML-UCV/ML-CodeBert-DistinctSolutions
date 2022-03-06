#include <iostream>
#include <fstream>
int main()
{
    int a, b;
    std::cin>>a>>b;
    std:: ofstream myfile;
    myfile.open ("cmmdc.in");
    myfile<< a << "\n" << b;
    myfile.close();
    while (a != b)
    {
        if(a>b)
            a -= b;
        else if(a<b)
            b -= a;
    }
    while (a == 1)
    {
        if(a!=1)
            a -= 0;
        else
            a = 0;
    }

    std::cout<<a;

    myfile.open ("cmmdc.out");
    myfile << a;
    myfile.close();
    return 0;
}
