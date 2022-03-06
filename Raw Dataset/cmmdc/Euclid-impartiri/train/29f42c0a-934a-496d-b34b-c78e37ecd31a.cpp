#include <iostream>
#include <fstream>
#include <string>
#include <vector>






using namespace std;



vector<int> Read(string path)

{

 std::ifstream file;

 file.open(path, std::ios::in);

 vector<int> read;

 int ti;

 while (file >> ti)

  read.push_back(ti);

 file.close();

 return read;

}

void Write(string path, vector<int> data)

{

 std::ofstream file;

 file.open(path);

 for (int i = 0; i < data.size(); i++)

 {

  file << data[i] << " ";

 }

 file.close();

}

void Write(string path, int data)

{

 std::ofstream file;

 file.open(path);

 file << data;

 file.close();

}



void Swap(int* a, int* b)

{

 int ti = *a;

 *a = *b;

 *b = ti;

}



int GCD(int a, int b)

{

 while (b != 0)

 {

  int t = b;

  b = a % b;

  a = t;

 }

 return a;

}





int main()

{

 vector<int> input = Read("cmmdc.in");

 int gcd = GCD(input[0], input[1]);

 if (gcd == 1)

  gcd = 0;



 Write("cmmdc.out", gcd);

}
