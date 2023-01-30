#include <bits/stdc++.h>
typedef long long ll;
typedef int itn;
using namespace std;
#define Mohab ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define atuo auto
const ll N = 1e5 + 10;
const ll mod =1e9+7;
#define el '\n'
#define oo INT32_MAX
#define C first
#define W second
#define P push
#define mk pair<pair<ll,ll>,ll>
#define file freopen("input.txt", "rt", stdin), freopen("output.txt", "wt", stdout);
#define pb push_back
#define ld long double
#define itn int
#define input(vec) for(auto &i:(vec))cin>>i;
#define print(vec) for(auto &i:(vec))cout<<i<<" ";
#define all(vec)  (vec).begin(),(vec).end()
void Dracarys() {
  int n;cin>>n;
   int x;
  multiset<int>st;
    for (int i = 0; i <n ; ++i) {
       cin>>x;
        st.insert(x);
    }
    itn cnt=0;
    while(!st.empty()){
         x =*st.begin();
        st.erase(st.begin());
        while(!st.empty() && x++){
            auto it=st.find(x);
            if(it!=st.end())st.erase(it);
            else break;
             }
        cnt++;
        }
    cout<<cnt<<el;
    }


signed main() {
    Mohab
    itn tc = 1;
    cin >> tc;
    while (tc--)Dracarys();
}
