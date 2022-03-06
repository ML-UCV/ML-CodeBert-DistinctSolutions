//
//  main.cpp
//  sate
//
//  Created by Eusebiu Rares on 19/03/2020.
//  Copyright Â© 2020 Eusebiu Rares. All rights reserved.
//

#include <iostream>
#include "fstream"
#include "queue"
#include "vector"
#include "bitset"

#pragma GCC optimize ("O3")
 
template <typename T>
class InputReader {
private:
        FILE *input_file ;
        static const int SIZE = (1 << 17) ;
        int point ;
        char buffer[SIZE] ;
        __attribute__ ( (always_inline)) void advance() {
                ++ point ;
                if (point == SIZE) {
                        point = 0 ;
                        fread (buffer, SIZE, 1, input_file) ;
                }
        }
public:
        InputReader() {}
        InputReader (const char *file_name) {
                input_file = fopen (file_name, "r") ;
                point = 0 ;
                fread (buffer, SIZE, 1, input_file) ;
        }
        __attribute__ ( (always_inline)) InputReader &operator >> (T &n) {
                for (; !isdigit (buffer[point]) ; advance()) ;
                n = 0 ;
                for (; isdigit (buffer[point]) ; advance()) {
                        n = n * ( (1 << 3) + (1 << 1)) + buffer[point] - '0' ;
                }
                return *this ;
        }
} ;
 
template <typename F>
class OutputParsing {
private :
        static const int SIZE = (1 << 20) ;
        char outBuffer[SIZE] ;
	const int BULAN = 500 ;
        int outputSize ;
        __attribute__ ( (always_inline)) int numberDigits(F x) {
                int digits = x > 999999999 ? 11 :
                             x > 99999999  ? 10 :
                             x > 9999999   ? 9  :
                             x > 999999    ? 8  :
                             x > 99999     ? 7  :
                             x > 9999      ? 6  :
                             x > 999       ? 5  :
                             x > 99        ? 4  :
                             x > 9         ? 3  : 2 ;
                return digits ;
        }
public :
        FILE *output_file ;
        OutputParsing() {}
        OutputParsing (const char *file_name) {
                output_file = fopen (file_name, "wb") ;
                outputSize = -1 ;
        }
        __attribute__ ( (always_inline)) void sflush() {
                fwrite(outBuffer, 1, outputSize, output_file) ;
        }
        __attribute__ ( (always_inline)) void operator << (F val) {
                if (val == -1) {
                        outBuffer[++ outputSize] = 45 ;
                        outBuffer[++ outputSize] = 49 ;
                        outBuffer[++ outputSize] = 10 ;
                } else {
                        int digits = numberDigits(val) ;
                        for (int i = digits ; -- i ; val /= 10) {
                                outBuffer[outputSize + i] = val % 10 + 48 ;
                        }
                        outBuffer[outputSize = outputSize + digits] = 10 ;
                }
                if (outputSize <= SIZE - BULAN) {
                        sflush() ;
                }
					return ;
        }
};
 
InputReader<int> in ("sate.in") ;
OutputParsing<int> out ("sate.out") ;

const int MV = 35000 ;

std::vector<std::pair<int, int> > G[MV + 1] ;
int sol[MV + 1] ;

template <class T>
class Coada {
	private :
	T v[MV + 1] ;
	int st, dr ;
	public :
	Coada() {
		st = 1 ;
		dr = 0 ;
	}
	void push(T val) {
		v[++ dr] = val ;
	}
	T front() {
		return v[st] ;
	}
	bool empty() {
		return !(st <= dr) ;
	}
	void pop() {
		st ++ ;
	}
} ;

int main(int argc, const char * argv[]) {
	int n, m, x, y ;
	in >> n >> m >> x >> y ;
	int a, b, d ;
	for (int i = 1 ; i <= m ; ++ i) {
		in >> a >> b >> d ;
		G[a].push_back({b, d}) ;
		G[b].push_back({a, -d}) ;
	}
	for (int i = 1 ; i <= n ; ++ i) {
		sol[i] = MV + 1 ;
	}
	Coada<int> Q ;
	Q.push(x) ;
	sol[x] = 0 ;
	while (!Q.empty()) {
		int node = Q.front() ; Q.pop() ;
		for (auto it : G[node]) {
			if (!(sol[it.first] xor (MV + 1))) {
				sol[it.first] = sol[node] + it.second ;
				Q.push(it.first) ;
				if (it.first == y) {
					out << sol[y] ;
					return 0 ;
				}
			}
		}
	}
}
