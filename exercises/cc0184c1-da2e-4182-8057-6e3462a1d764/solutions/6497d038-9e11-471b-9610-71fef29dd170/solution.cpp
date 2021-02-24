#include <cstdio>

using namespace std;

const int MAXN = 100100;

int N;
int A[MAXN], B[MAXN];
int x, y;

int main(void) 
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) 
    scanf("%d %d", A + i, B + i);

  for (int grade = 1; grade <= 5; ++grade) {
    int len = 0;
    for (int i = 0; i < N; ++i) {
      if (A[i] == grade || B[i] == grade) len++; else len = 0;
      if (len > x) {
        x = len;
        y = grade;
      }
    }
  }
  printf("%d %d\n", x, y);
  return 0;
}