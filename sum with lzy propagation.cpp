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
#define file freopen("input.txt", "rt", stdin);
#define pb push_back
#define input(vec) for(auto &i:(vec))cin>>i;
#define print(vec) for(auto &i:(vec))cout<<i<<" ";
#define all(vec)  (vec).begin(),(vec).end()
#define PII pair<int,int>
const int N = 2e5 + 2;
vector<int> Tree, vec, lzy;
int natural;
int n;

struct {
    // zero indexed segment tree
    void init() {
        Tree.resize(4 * N);
        lzy.resize(4 * N);
        vec.resize(n);
        natural = 0;
    }

    int merge(int &x, int &y) {
        return x + y;
    }

    itn ls(int &node) {
        return (node << 1);
    }

    int rs(int &node) {
        return (node << 1 | 1);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            Tree[node] = vec[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(ls(node), start, mid);
        build(rs(node) | 1, mid + 1, end);
        Tree[node] = merge(Tree[ls(node)], Tree[rs(node)]);
    };

    // zero indexed
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            Tree[idx + n] = val;
            return;
        }
        int mid = (start + end) >> 1;
        update(ls(node), start, mid, idx, val);
        update(rs(node), mid + 1, end, idx, val);
        Tree[node] = merge(Tree[ls(node)], Tree[rs(node)]);
    }

    // zero indexed
    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end)
            return natural;
        else if (l <= start && r >= end)
            return Tree[node];
        else {
            int mid = (start + end) / 2;
            int rq = query(node * 2, start, mid, l, r);
            int lq = query(node * 2 + 1, mid + 1, end, l, r);
            return merge(rq, lq);
        }
    }

    void propagate(int node, int start, int end) {
        if (lzy[node] != 0) {
            Tree[node] += (((end - start + 1) * lzy[node]));
            if (start != end) {
                lzy[node << 1] += lzy[node];
                lzy[node << 1 | 1] += lzy[node];
            }
            lzy[node] = 0;
        }
    }

    void lzy_update(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);
        if (start > r || end < l)
            return;
        if (l <= start && r >= end) {
            lzy[node] += val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) >> 1;
        lzy_update(node << 1, start, mid, l, r, val);
        lzy_update(node << 1 | 1, mid + 1, end, l, r, val);
        Tree[node] = merge(Tree[node << 1], Tree[node << 1 | 1]);
    }

    int lzy_query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (r < start || l > end)
            return natural;
        else if (l <= start && r >= end)
            return Tree[node] + (lzy[node * (end - start + 1)]);
        else {
            int mid = (start + end) / 2;
            int rq = lzy_query(node * 2, start, mid, l, r);
            int lq = lzy_query(node * 2 + 1, mid + 1, end, l, r);
            return merge(rq, lq);
        }
    }

    void debug() {
        for (int i = 0; i < (4 * n); ++i) {
            cout << i << " " << Tree[i] << el;
        }
        cout << el;
    }
} segmentTree;


void Dracarys(int tc) {
    cin >> n;
    segmentTree.init();
    input(vec)
    segmentTree.build(1, 0, n - 1);
    segmentTree.lzy_update(1, 0, n - 1, 0, 3, 100);
    segmentTree.lzy_update(1, 0, n - 1, 7, 7, 100);
    segmentTree.lzy_update(1, 0, n - 1, 3, 5, 100);
    cout << " here \n";
    cout << segmentTree.lzy_query(1, 0, n - 1, 0, 3) << el << el;
    cout << segmentTree.lzy_query(1, 0, n - 1, 0, 0) << el << el;
    cout << segmentTree.lzy_query(1, 0, n - 1, 7, 7) << el << el;
    cout << segmentTree.lzy_query(1, 0, n - 1, 5, 5) << el << el;
    cout<<Tree[1]<<el;
    segmentTree.debug();
}

signed main() {
    Mohab
    freopen(R"(C:\Users\amoha\CLionProjects\untitled1\input.txt)", "rt", stdin);
    int tc = 1;
    //    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        Dracarys(i);
    }
}



