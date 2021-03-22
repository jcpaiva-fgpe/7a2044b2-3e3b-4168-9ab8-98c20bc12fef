#include <cstdio>

typedef double lf;
int n, m[300001];

lf max(lf a, lf b) {
  return a > b ? a : b;
}

lf solve() {
  lf dx = 1, M = m[0];
  for (int j = 1; j < n - 1; ++j) {
    dx = max(dx, dx + m[j] / (M + m[j]));
    dx = max(dx,  2 - m[j] / (M + m[j]));
    M += m[j];
  }
  return dx;
}

int main() {
  scanf("%d", &n);
  for (int j = 0; j < n; ++j)
    scanf("%d", m + n - j - 1);
  printf("%.8lf\n", n > 1 ? solve() : 0);
  return 0;
}