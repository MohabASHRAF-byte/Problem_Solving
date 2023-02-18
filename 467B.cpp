#include <bits/stdc++.h>

typedef long long ll;
typedef int itn;
using namespace std;
#define Mohab ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define atuo auto
#define el '\n'
#define oo INT64_MAX
#define F first
#define S second
#define P push
#define file freopen("input.txt", "rt", stdin), freopen("output.txt", "wt", stdout);
#define pb push_back
#define input(vec) for(auto &i:(vec))cin>>i;
#define print(vec) for(auto &i:(vec))cout<<i<<" ";
#define all(vec)  (vec).begin(),(vec).end()
#define PII pair<int,int>
int n, m, k, ans = 0;
vector<int> vec;

void Dracarys(int tc) {
    cin >> n >> m >> k;
    for (int i = 0, x; i < m + 1; ++i) cin >> x, vec.push_back(x);
    int fred = vec.back();vec.pop_back();
    for (auto &i: vec)if (__builtin_popcount(fred ^ i) <= k)ans++;
    cout << ans;
}

signed main() {
    Mohab
    int tc = 1;
//    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        Dracarys(i);
    }
}




