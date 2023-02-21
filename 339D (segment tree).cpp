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
    const int N = 2e5 + 10;
    vector<int> Tree;
    int natural;
    int n;
    vector<int> vec;
    int lg[N];

    struct {
        void init(int nn) {
            Tree.resize(4 * nn, 0);
            natural = 0;
            lg[1] = 0;
            for (int i = 2; i <= n; ++i) {
                lg[i] = lg[i >> 1] + 1;
            }
        }

        int merge(int &x, int &y, bool check) {
            return (check?x|y:x^y);
        }

        void build(int node, int start, int end) {
            if (start == end) {
                Tree[node] = vec[start];
                return;
            }
            int mid = (start + end) / 2;
            build(node * 2, start, mid);
            build(node * 2 + 1, mid + 1, end);
            Tree[node] = merge(Tree[node <<1], Tree[node << 1|1], lg[(end - start + 1)] & 1);
        }

        void update(int node, int start, int end, int idx, int val) {
            if (start == end) {
                Tree[idx + n] = val;
                return;
            }
            int mid = (start + end) >>1;
            if (idx <= mid)
                update(node<<1, start, mid, idx, val);
            else
                update(node <<1|1, mid + 1, end, idx, val);
            Tree[node] = merge(Tree[node <<1], Tree[node <<1 |  1], lg[(end - start + 1)] & 1);
        }

        int query(int node, int start, int end, int l, int r) {
            if (r < start || l > end)
                return natural;
            else if (l <= start && r >= end)
                return Tree[node];
            else {
                int mid = (start + end) / 2;
                int rq = query(node * 2, start, mid, l, r);
                int lq = query(node * 2 + 1, mid + 1, end, l, r);
                return merge(rq, lq, lg[(end - start + 1)] & 1);
            }
        }

    } segmentTree;

    int m;
    int q;

    void Dracarys(int tc) {
        cin >> m>> q;
        n = (1 << m);
        vec.resize(::n);
        input(vec)
        segmentTree.init(::n);
        segmentTree.build(1, 0, n - 1);
        while (q--) {
            int idx, val;
            cin >> idx >> val;
            segmentTree.update(1, 0, n - 1, idx - 1, val);
            cout << Tree[1] << "\n"[!q];
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




