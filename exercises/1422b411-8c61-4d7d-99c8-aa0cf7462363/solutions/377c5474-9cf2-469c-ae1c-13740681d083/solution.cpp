#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int R, C;
int zab[1000][1000];

vector<char> A, B;
void prvi( char c, int t ) { for( ; t > 0; --t ) A.push_back( c ); }
void drugi( char c, int t ) { for( ; t > 0; --t ) B.push_back( c ); }

int main( void ) {
  scanf( "%d %d", &R, &C );
  for( int i = 0; i < R; ++i )
    for( int j = 0; j < C; ++j )
      scanf( "%d", &zab[i][j] );
  drugi( '\n', 1 ); 

  if( R%2 ) {
    for( int i = 0; i < R/2; ++i ) {
      prvi( 'R', C-1 );
      prvi( 'D', 1 );
      prvi( 'L', C-1 );
      prvi( 'D', 1 );
    }
    prvi( 'R', C-1 );
  }
  else if( C%2 ) { 
    for( int i = 0; i < C/2; ++i ) {
      prvi( 'D', R-1 );
      prvi( 'R', 1 );
      prvi( 'U', R-1 );
      prvi( 'R', 1 );
    }
    prvi( 'D', R-1 );
  }
  else {
    int x = 0, y = 1;
    for( int i = 0; i < R; ++i )
      for( int j = 0; j < C; ++j )
        if( (i+j)%2 && zab[i][j] < zab[x][y] )
          x = i, y = j;

    int a = 0, b = 0; 
    int r = R-1, c = C-1; 
    for( ;; ) {
      if( a+2 <= x ) {
        prvi( 'R', c-b );
        prvi( 'D', 1 );
        prvi( 'L', c-b );
        prvi( 'D', 1 );
        a += 2;
      }
      else if( b+2 <= y ) {
        prvi( 'D', r-a );
        prvi( 'R', 1 );
        prvi( 'U', r-a );
        prvi( 'R', 1 );
        b += 2;
      }
      else if( r-2 >= x ) {
        drugi( 'R', c-b );
        drugi( 'D', 1 );
        drugi( 'L', c-b );
        drugi( 'D', 1 );
        r -= 2;
      }
      else if( c-2 >= y ) {
        drugi( 'D', r-a );
        drugi( 'R', 1 );
        drugi( 'U', r-a );
        drugi( 'R', 1 );
        c -= 2;
      }
      else break;
    }
    
    if( a+1 == x ) { prvi( 'R', 1 ); prvi( 'D', 1 ); }
    if( b+1 == y ) { prvi( 'D', 1 ); prvi( 'R', 1 ); }
  }

  reverse( B.begin(), B.end() );
  for( vector<char>::iterator it = A.begin(); it != A.end(); ++it ) putchar( *it );
  for( vector<char>::iterator it = B.begin(); it != B.end(); ++it ) putchar( *it );

  return 0;
}

