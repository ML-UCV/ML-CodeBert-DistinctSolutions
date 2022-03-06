#include <cstdio>
#include <cctype>

using namespace std;

FILE *fin = fopen( "stramosi.in", "r" ), *fout = fopen( "stramosi.out", "w" );

const int BufSz = (1 << 17);
const int Max10 = 10;

int rpos = BufSz - 1;
char rbuf[BufSz];
int p10[Max10 + 1] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
char wbuf[BufSz];
int wpos = 0;

static inline char readChar() {
  if ( !(rpos = (rpos + 1) & (BufSz - 1)) ) {
    fread( rbuf, 1, BufSz, fin );
  }
  return rbuf[rpos];
}
int readInt() {
  int ch, res = 0;

  while ( isspace( ch = readChar() ) );
  do {
    res = res * 10 + ch - '0';
  } while ( isdigit( ch = readChar() ) );
  return res;
}

static inline void writeChar( char ch ) {
  wbuf[wpos] = ch;
  if ( !(wpos = (wpos + 1) & (BufSz - 1)) ) {
    fwrite( wbuf, 1, BufSz, fout );
  }
}
static inline void writeInt( int x ) {
  int i, cf;
  i = Max10;
  while ( p10[i] > x ) {
    --i;
  }
  if ( i == 0 ) {
    writeChar( '0' );
  } else {
    do {
      cf = '0';
      while ( p10[i] <= x ) {
        x -= p10[i];
        ++cf;
      }
      writeChar( cf );
    } while ( --i > 0 );
  }
  writeChar( '\n' );
}
static inline void flushBuf() {
  fwrite( wbuf, 1, wpos, fout );
}

const int MaxN = 250002;
const int MaxLog = 20;

int anc[MaxN][MaxLog];
int log[MaxN];

int main() {
  int n, q, p, i, lg;

  fscanf( fin, "%d%d", &n, &q );
  for ( i = 1; i <= n; ++i ) {
    fscanf( fin, "%d", &anc[i][0] );
  }
  for ( p = 1; p <= MaxLog - 1; ++p ) {
    for ( i = 1; i <= n; ++i ) {
      anc[i][p] = anc[anc[i][p - 1]][p - 1];
 }
  }
  for ( i = 2; i <= n; ++i ) {
 log[i] = log[i / 2] + 1;
  }
  while ( q-- ) {
 i = readInt();
 p = readInt();
    lg = log[p];
 while ( p ) {
   i = anc[i][lg];
   p -= (1 << lg);
   lg = log[p];
 }
 writeInt( i );
  }
  flushBuf();
  fclose( fin );
  fclose( fout );
  return 0;
}
