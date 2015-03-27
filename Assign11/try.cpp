#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
 
int N, c[401][401];
 
void update(int x, int y) {
  if (c[x][y] >= 1000000001) return;
  for (int j = 0; j < 2*N; j++)
  for (int k = 0; k < 2*N; k++)
    c[j][k] = max(c[j][k], min(c[j][x], c[y][k]));
}
 
main() {
  while (cin >> N) {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 2*N; i++) c[i][i] = 1000000001;
    vector<pair<int, pair<int, int> > > e;
    for (int i = 0; i < N; i++)
    for (int j = i+1; j < N; j++) {
      int d;
      cin >> d;
      c[i][j+N] = max(c[i][j+N], d);
      c[j][i+N] = max(c[j][i+N], d);
      e.push_back(make_pair(d, make_pair(i, j)));
    }
    if (N <= 2) {cout << 0 << endl; continue;}
 
    for (int k = 0; k < 2*N; k++)
    for (int i = 0; i < 2*N; i++)
    for (int j = 0; j < 2*N; j++) {
      c[i][j] = max(c[i][j], min(c[i][k], c[k][j]));
    }
 
    sort(e.begin(), e.end());
    int ret = e.back().first;
    for (int i = e.size()-1; i >= 0; i--) {
      int A = 0;
      for (int j = 0; j < N; j++) A = max(A, min(c[j][j+N], c[j+N][j]));
      ret = min(ret, A + e[i].first);
 
      int a = e[i].second.first, b = e[i].second.second;
      update(a+N, b);
      update(a, b+N);
      update(b+N, a);
      update(b, a+N);
    }
 
    cout << ret << endl;
  }
}