#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll init_seg(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = arr[start];
    else{
        int mid = (start + end)/2;
        return tree[node] = init_seg(arr, tree, node*2, start, mid) + init_seg(arr, tree, node*2+1, mid+1, end);
    }
}

void update_lazy(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_seg(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end, int left_index, int right_index, ll diff) {
    update_lazy(tree, lazy, node, start, end);
    if (left_index > end || right_index < start)
        return;

    if (left_index <= start && end <= right_index) {
        tree[node] += (end-start+1)*diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }

    update_seg(tree, lazy, node*2, start, (start+end)/2, left_index, right_index, diff);
    update_seg(tree, lazy, node*2+1, (start+end)/2+1, end, left_index, right_index, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
ll sum_seg(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);

    if (left > end || right < start)
        return 0;

    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end)/2;
    return sum_seg(tree, lazy, node*2, start, mid, left, right) + sum_seg(tree, lazy, node*2+1, mid+1, end, left, right);
}
int main() {
    
    int n, m, k;
    scanf("%d %d %d",&n,&m,&k);
    
    vector<ll> base_arr(n);

    int tree_deepth = (int)ceil(log2(n));
    int tree_size = (1 << (tree_deepth+1)) - 1;

    vector<ll> seg_tree(tree_size);
    vector<ll> lazy_tree(tree_size);

    int cycle = m+k;

    for (int i=0; i<n; i++)
        scanf("%lld", &base_arr[i]);

    init_seg(base_arr, seg_tree, 1, 0, n-1);
    while (cycle--) {
        int order, l_idx, r_idx;
        scanf("%d",&order);
        if (order == 1) {
            ll diff;
            scanf("%d %d %lld",&l_idx,&r_idx, &diff);
            update_seg(seg_tree, lazy_tree, 1, 0, n-1, l_idx-1, r_idx-1, diff);
        } 
        else {
            scanf("%d %d",&l_idx,&r_idx);
            printf("%lld\n",sum_seg(seg_tree, lazy_tree, 1, 0, n-1, l_idx-1, r_idx-1));
        }
    }
    return 0;
}