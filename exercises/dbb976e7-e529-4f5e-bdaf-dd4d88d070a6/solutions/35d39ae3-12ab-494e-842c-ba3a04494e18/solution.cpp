#include <algorithm>
#include <functional>

#include <cstdio>
#include <cstdlib>
#include <cstdlib>

#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;



int main(void)
{
  vector<int> A, B;

  load(A);
  load(B);


  Kmp kmp(B);
  printf("%d\n", kmp.match(A) + 1);

  return (0-0);
}