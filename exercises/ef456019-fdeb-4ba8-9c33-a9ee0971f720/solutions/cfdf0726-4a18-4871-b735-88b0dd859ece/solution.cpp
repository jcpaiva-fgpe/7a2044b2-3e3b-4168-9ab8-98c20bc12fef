#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int K; cin >> K; K++;
  string ret;
  for (; K > 1; K >>= 1)
    ret = ((K & 1) ? "7" : "4") + ret;
  cout << ret << '\n';
  return 0;
}