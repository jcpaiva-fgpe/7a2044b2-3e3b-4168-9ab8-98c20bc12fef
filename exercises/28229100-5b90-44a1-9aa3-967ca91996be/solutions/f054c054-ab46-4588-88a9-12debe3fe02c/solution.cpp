#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <set>
#include <vector>
#include <algorithm>

using namespace std;
const int p = 10007;

#define MAXN 300005

int M, N, Nm[ MAXN ];
char s[ MAXN ];
char b[ MAXN ];
char *m[ MAXN ];

int H[ MAXN ];
int Hm[ MAXN ];
int P[ MAXN ];
int sa[ MAXN ];
int cnt[ MAXN ];

vector< int > V0[ MAXN ], V1[ MAXN ];

struct cmp {
  bool operator()( int a, int b ) {
    if( Nm[a] != Nm[b] ) return ( Nm[a] > Nm[b] );
    return ( a < b );
  }
};

set< int, cmp > pq;

int hash( int *H, int x, int l ) {
  int ret = H[x+l-1];
  if( x ) ret -= H[x-1] * P[l];
  return ret;
}

int lcp( int a, int b ) { // a i b su sufiksi
  if( s[a] != s[b] ) return 0;
  int lo = 1, hi = min( N-a, N-b ), mid;

  while( lo < hi ) {
    mid = ( lo + hi + 1 ) >> 1;
    if( hash( H, a, mid ) != hash( H, b, mid ) ) hi = mid-1;
    else lo = mid;
  }

  return lo;
}

int lcp2( int a, int b ) { // a je sufiks, b je mali string
  if( s[a] != m[b][0] ) return 0;
  int lo = 1, hi = min( N-a, Nm[b] ), mid;

  while( lo < hi ) {
    mid = ( lo + hi + 1 ) >> 1;
    if( hash( H, a, mid ) != hash( Hm, 0, mid ) ) hi = mid-1;
    else lo = mid;
  }

  return lo;
}

bool cmpf( int a, int b ) { // komparator za suffix array
  int L = lcp( a, b );
  if( L == N-a ) return 1;
  if( L == N-b ) return 0;
  return ( s[a+L] < s[b+L] );
}

int cmpf2( int a, int b ) { // 0 ako je b prefiks od a, -1 ako je manji, +1 ako je veci
  int L = lcp2( a, b );
  if( L == Nm[b] ) return 0;
  if( s[a+L] < m[b][L] ) return -1;
  return +1;
}

int lo_search( int x ) { // x je mali string koji trazim u arrayu
  int lo = 0, hi = N-1, mid;

  while( lo < hi ) {
    mid = ( lo + hi ) >> 1;
    if( cmpf2( sa[mid], x ) < 0 ) lo = mid+1;
    else hi = mid;
  }

  return lo;
}

int hi_search( int x ) { // x je mali string koji trazim u arrayu
  int lo = 0, hi = N-1, mid;

  while( lo < hi ) {
    mid = ( lo + hi + 1 ) >> 1;
    if( cmpf2( sa[mid], x ) > 0 ) hi = mid-1;
    else lo = mid;
  }

  return lo;
}


int main( void )
{
  scanf( "%d", &N );
  scanf( "%s", s );
  scanf( "%d", &M );

  for( int i = 0; i < M; ++i ) {
    scanf( "%s", b );
    m[i] = (char*) malloc( ( Nm[i] = strlen( b ) ) + 2 );
    strcpy( m[i], b );
  }

  sa[0] = 0;

  H[0] = s[0];
  P[0] = 1;

  for( int i = 1; i < N; ++i ) {
    H[i] = H[i-1] * p + s[i];
    P[i] = P[i-1] * p;
    sa[i] = i;
  }

  sort( sa, sa + N, cmpf );

  for( int i = 0; i < M; ++i ) {
    Hm[0] = m[i][0];
    for( int j = 1; j < Nm[i]; ++j )
      Hm[j] = Hm[j-1] * p + m[i][j];

    int los = lo_search( i );
    int his = hi_search( i );

    if( lcp2( sa[los], i ) >= Nm[i] ) {
      V0[los].push_back( i );
      V1[his].push_back( i );
    }
  }

  for( int i = 0; i < N; ++i ) {
    for( int j = 0; j < V0[i].size(); ++j ) pq.insert( V0[i][j] );
    if( !pq.empty() ) {
      ++cnt[sa[i]];
      --cnt[sa[i]+Nm[*pq.begin()]];
    }
    for( int j = 0; j < V1[i].size(); ++j ) pq.erase( V1[i][j] );
  }

  int now = 0, sol = 0;

  for( int i = 0; i < N; ++i )
    sol += ( ( now += cnt[i] ) != 0 );

  printf( "%d\n", N-sol );

  return 0;
}