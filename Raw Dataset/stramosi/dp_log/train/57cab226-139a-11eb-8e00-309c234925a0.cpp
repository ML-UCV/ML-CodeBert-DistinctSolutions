#include <bits/stdc++.h>


using namespace std;

int n, Q, x, c, p, t[250005][18];

void build()

{

    for(int i=1; i<=17; i++)

    {

        for(int nod=1; nod<=n; nod++)

            t[nod][i] = t[t[nod][i-1]][i-1];

    }

}

class InParser {

private:

 FILE *fin;

 char *buff;

 int sp;



 char read_ch() {

  ++sp;

  if (sp == 4096) {

   sp = 0;

   fread(buff, 1, 4096, fin);

  }

  return buff[sp];

 }



public:

 InParser(const char* nume) {

  fin = fopen(nume, "r");

  buff = new char[4096]();

  sp = 4095;

 }



 InParser& operator >> (int &n) {

  char c;

  while (!isdigit(c = read_ch()) && c != '-');

  int sgn = 1;

  if (c == '-') {

   n = 0;

   sgn = -1;

  } else {

   n = c - '0';

  }

  while (isdigit(c = read_ch())) {

   n = 10 * n + c - '0';

  }

  n *= sgn;

  return *this;

 }



 InParser& operator >> (long long &n) {

  char c;

  n = 0;

  while (!isdigit(c = read_ch()) && c != '-');

  long long sgn = 1;

  if (c == '-') {

   n = 0;

   sgn = -1;

  } else {

   n = c - '0';

  }

  while (isdigit(c = read_ch())) {

   n = 10 * n + c - '0';

  }

  n *= sgn;

  return *this;

 }

};

class OutParser {

private:

    FILE *fout;

    char *buff;

    int sp;



    void write_ch(char ch) {

        if (sp == 50000) {

            fwrite(buff, 1, 50000, fout);

            sp = 0;

            buff[sp++] = ch;

        } else {

            buff[sp++] = ch;

        }

    }





public:

    OutParser(const char* name) {

        fout = fopen(name, "w");

        buff = new char[50000]();

        sp = 0;

    }

    ~OutParser() {

        fwrite(buff, 1, sp, fout);

        fclose(fout);

    }



    OutParser& operator << (int vu32) {

        if (vu32 <= 9) {

            write_ch(vu32 + '0');

        } else {

            (*this) << (vu32 / 10);

            write_ch(vu32 % 10 + '0');

        }

        return *this;

    }



    OutParser& operator << (long long vu64) {

        if (vu64 <= 9) {

            write_ch(vu64 + '0');

        } else {

            (*this) << (vu64 / 10);

            write_ch(vu64 % 10 + '0');

        }

        return *this;

    }



    OutParser& operator << (char ch) {

        write_ch(ch);

        return *this;

    }

    OutParser& operator << (const char *ch) {

        while (*ch) {

            write_ch(*ch);

            ++ch;

        }

        return *this;

    }

};



int main()

{

    InParser fin("stramosi.in");

    OutParser fout("stramosi.out");

    fin >> n >> Q;

    for(int i=1; i<=n; i++)

        fin >> t[i][0];

    build();

    while(Q--)

    {

        fin >> x >> c;

        if(c > n)

            fout << 0 << '\n';

        else

        {

            p = 0;

            while(c)

            {

                if(c&1)

                    x = t[x][p];

                c>>=1;

                ++p;

            }

            fout << x << '\n';

        }

    }



    return 0;

}
