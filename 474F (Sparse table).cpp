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
const int N = 1e5 + 10;
int table[N][22];
vector<int> vec;

struct {
    int lg[N];

    void init(int nn) {
        lg[1] = 0;
        for (int i =2; i <= nn; ++i) {
            lg[i] = lg[i >> 1] + 1;
        }
        for (int i = 1; i < nn+1; ++i) {
            table[i][0] = vec[i];
        }
        for (int j = 1; j < 21; ++j) {
            for (int i = 0; i <= nn - (1 << j) + 1; ++i) {
                table[i][j] = gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int temp = lg[r - l + 1];
        return __gcd(table[l][temp], table[r - (1 << temp) + 1][temp]);

    }


} sparse;

int n;

void Dracarys(int tc) {
    cin >> n;
    vec.resize(::n + 5);
    map<int, vector<int>> mp;
    for (int i = 1; i < n + 1; ++i) {
        cin >> vec[i];
        mp[vec[i]].pb(i);
    }
    sparse.init(n);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int gcd = sparse.query(l, r);
        int plus = upper_bound(mp[gcd].begin(), mp[gcd].end(), r) - lower_bound(mp[gcd].begin(), mp[gcd].end(), l);
        int p = (r - l + 1 - plus);
        cout << p << "\n"[!q];
    }
}

signed main() {
    Mohab
    int tc = 1;
    //    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        Dracarys(i);
    }
}



