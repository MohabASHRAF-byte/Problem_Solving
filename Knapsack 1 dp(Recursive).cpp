#include <bits/stdc++.h>

typedef long long ll;
typedef int itn;
using namespace std;
#define Mohab ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define atuo auto
const ll N = 1e5 + 10;
const ll mod = 1e9 + 7;
#define el '\n'
#define oo INT32_MAX
#define F first
#define S second
#define P push
#define mk pair<pair<ll,ll>,ll>
#define file freopen("input.txt", "rt", stdin), freopen("output.txt", "wt", stdout);
#define pb push_back
#define ld long double
#define itn int
#define input(vec) for(auto &i:(vec))cin>>i;
#define print(vec) for(auto &i:(vec))cout<<i<<" ";
#define all(vec)  (vec).begin(),(vec).end()

int weights[105];
int values[105];
ll dp[105][N];
int n;
ll solve(int idx ,int rem){
    if(idx==n or rem==0)
        return 0;
    if(dp[idx][rem]!=-1)return dp[idx][rem];
    ll ans= solve(idx+1,rem);
     if(rem >= weights[idx]){
         ans=max(ans,solve(idx+1,rem-weights[idx])+values[idx]);
     }
    return dp[idx][rem]=ans;
}

void Dracarys() {
    memset(dp,-1,sizeof dp);
    int w;
    cin >> n>>w;
    for (int i = 0; i < n; ++i) {
        cin>>weights[i]>>values[i];
    }
    cout << solve(0,w)<<el;

}


signed main() {
    Mohab
    int tc = 1;
//    cin >> tc;
    while (tc--)Dracarys();
}
