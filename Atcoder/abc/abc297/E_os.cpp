#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define INF ((1LL << 62) - (1LL << 31)) /*オーバーフローしない程度に大きい数*/
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using pqueue = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>;
ll B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
ll dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}
vll A;
// x 円は安い方からｋ番目の金額以上か
bool isOk(ll x, set<ll> &graph, ll v, ll &cnt) {
  if (graph.size() == K)
    return 1;
  rep(i, 0, N) {
    ll nv = v + A[i];
    if (nv <= x && graph.find(nv) == graph.end()) {
      graph.insert(nv);
      if (isOk(x, graph, nv, cnt))
        return 1;
    }
  }
  return 0;
}

ll bs(ll mx) {
  ll ng = 0, ok = mx;
  while (ok - ng > 1) {
    ll mid = (ng + ok) / 2;
    set<ll> graph;
    ll cnt = 0;
    if (isOk(mid, graph, 0, cnt))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

int main() {
  cin >> N >> K;
  A.resize(N, 0);
  ll mx = 0;
  rep(i, 0, N) {
    cin >> A[i];
    mx = max(mx, A[i]);
  }
  cout << bs(300000000000000) << endl;

  return 0;
}
