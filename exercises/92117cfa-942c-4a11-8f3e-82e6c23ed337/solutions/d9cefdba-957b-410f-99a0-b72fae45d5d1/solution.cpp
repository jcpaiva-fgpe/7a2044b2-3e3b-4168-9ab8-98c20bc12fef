#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;

  vector<int> l(n), r(m);
  for(int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  for(int i = 0; i < m; ++i) {
    cin >> r[i];
  }

  sort(l.begin(), l.end());
  sort(r.begin(), r.end());

  if(n > m) {
    swap(n, m);
    swap(l, r);
  }

  int lo = 0, hi = 1e9;
  while(lo < hi) {
    int mid = (lo + hi) >> 1;

    bool mid_okay = true;

    int j = 0;
    for(int i = 0; i < n; ++i) {
      while(j < m && abs(r[j] - l[i]) > mid) j ++;
      if(j == m) {
        mid_okay = false;
        break;
      }
      j ++;
    }

    if(mid_okay) {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  }

  cout << lo << endl;
}
