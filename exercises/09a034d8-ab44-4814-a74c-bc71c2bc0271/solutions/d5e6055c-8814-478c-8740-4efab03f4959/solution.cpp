#include <cstdio>

int main() {
  int n, p, x;

  scanf("%d %d", &n, &p);

  for(int i = 0; i < 5; ++i) {
    scanf("%d", &x);
    printf("%d%s", x-n*p, (i == 4 ? "\n" : " "));
  }

  return 0;
}