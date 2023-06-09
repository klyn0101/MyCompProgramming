#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
using namespace std;
using Graph = vector<vector<int>>;
int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    rep(i,0,N)
        cin >> A[i];
    rep(i,0,M)
        cin >> B[i];
    
    int ans = 0;
    rep(i,0,M)
        ans += A[B[i] - 1];

    cout <<  ans << endl;
    
    return 0;
}


