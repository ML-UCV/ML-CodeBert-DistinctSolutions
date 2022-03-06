#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

std::string sir;
int pos;

void read() {
  std::ifstream in("evaluare.in");

  in >> sir;

  in.close();
}

int expresie();
int termen();
int factor();

int expresie() {
  int val = termen();

  while (pos < sir.size()) {
    if (sir[pos] == '+') {
      ++pos;
      val += termen();
    } else if (sir[pos] == '-') {
      ++pos;
      val -= termen();
    } else {
      break;
    }
  }

  return val;
}

int termen() {
  int val = factor();

  while (pos < sir.size()) {
    if (sir[pos] == '*') {
      ++pos;
      val *= factor();
    } else if (sir[pos] == '/') {
      ++pos;
      val /= factor();
    } else {
      break;
    }
  }

  return val;
}

int factor() {
  int val = 0;

  if (sir[pos] == '(') {
    ++pos;
    val = expresie();
    ++pos;
  } else {
    while (isdigit(sir[pos])) {
      val = 10 * val + (sir[pos] - '0');
      ++pos;
    }
  }

  return val;
}

int main() {
  read();

  std::ofstream out("evaluare.out");
  out << expresie();

  return 0;
}
