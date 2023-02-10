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

int n;
string str1, str2;
vector<vector<pair<int,int>>>par(1000,vector<pair<int,int>>(1000));
vector<vector<ll>>dp(1000,vector<ll>(10005,-1));
ll solve(int ptr1, int ptr2) {
    if (ptr1 == str1.size() or ptr2 == str2.size())
        return 0;
    if(dp[ptr1][ptr2]!=-1)
        return dp[ptr1][ptr2];
    if (str1[ptr1] == str2[ptr2]) {
        par[ptr1][ptr2] = {ptr1 + 1, ptr2 + 1};
        return dp[ptr1][ptr2]= solve(ptr1 + 1, ptr2 + 1) + 1;
    }
    ll moveptr1 = solve(ptr1 + 1, ptr2);
    ll moveptr2 = solve(ptr1, ptr2 + 1);
    if(moveptr1>moveptr2){
        par[ptr1][ptr2] = {ptr1 + 1, ptr2 };
    }
    else{
        par[ptr1][ptr2] = {ptr1, ptr2+1};
    }
    return dp[ptr1][ptr2]= max(moveptr1, moveptr2);

}


void Dracarys() {
    cin >> str1 >> str2;
    cout << solve(0, 0)<<el;
    pair<int,int>curr={0,0};
    vector<char>ans;
    while(curr.first <str1.size() and curr.S<str2.size()){
        if(str1[curr.F]==str2[curr.S])ans.pb(str1[curr.F]);
        curr=par[curr.F][curr.S];
    }
    for(auto i : ans)cout<<i;
}


signed main() {
    Mohab
    int tc = 1;
//    cin >> tc;
    while (tc--)Dracarys();
}
