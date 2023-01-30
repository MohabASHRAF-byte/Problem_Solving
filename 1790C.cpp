#include <bits/stdc++.h>

using namespace std;
#define Mohab ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define itn int
const ll N = 100+ 5;
#define el '\n'
#define oo INT64_MAX
#define F first
#define S second
//information
// dag --> directed acyclic graph
// detecting cycles using back tracking

// initial
int n, m, u, v;
vector<vector<int>> graph(N);
vector<int> frq(N,0);
vector<int> ans;
priority_queue<int, vector<int>, greater<>> q;

//
void solve() {
    int n, m, u, v;
vector<vector<int>> graph(N);
vector<int> frq(N,0);
vector<int> ans;
priority_queue<int, vector<int>, greater<>> q;
  cin>>n;
  for (int i = 0; i < n; i++)
   {
    vector<int>vec(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin>>vec[i];
    }
    for (int  i = 0; i < n-2; i++)   
    {
      graph[vec[i]].push_back(vec[i+1]);
      frq[vec[i+1]]++;
    }
}
    for (int i = 1; i <=n ; ++i) {
        if(frq[i]==0)
            q.push(i);
    }


    while (!q.empty()){
        int node = q.top();
        q.pop();
        ans.push_back(node);
        for(auto child : graph[node]){
            frq[child]--;
            if(frq[child]==0){
                q.push(child);
            }
        }
    }

    if(ans.size()!=n){
        cout<<"here";
    }
    for(auto  i : ans)cout<<i <<' ';
     cout<<"\n";
}

int main() {
    Mohab
    int t =1;
    cin>>t;
    while(t--)solve();

}
