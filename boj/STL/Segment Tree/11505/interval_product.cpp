#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 
typedef long long ll;

ll seg_init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
    
    if(start == end)    // 노드가 리프 노드인 경우
        return tree[node] = arr[start]; // 배열의 그 원소의 값을 가져야 함
    int mid = (start + end)/2;

    // 구간 합  
    return tree[node] = (seg_init(arr, tree, node*2, start, mid) * seg_init(arr, tree, node*2+1, mid+1, end)) % 1000000007;
}

void seg_update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
    if(index < start || index > end) return;
    
    if(start == end){
        tree[node] = diff;
        return;
    }
    else{
        int mid = (start + end)/2;
        seg_update(tree, 2*node, start, mid, index, diff);
        seg_update(tree, 2*node+1, mid+1, end, index, diff);
        tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007;

        return;
    }

    return;
}

ll seg_product(vector<ll> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1; // case 1 : 포함 x
    if(left <= start && end <= right) return tree[node]; // case 2 : find it ( 종료 조건 )

    int mid = (start + end)/2;

    return (seg_product(tree, node*2, start, mid, left, right) * seg_product(tree, node*2+1, mid+1, end, left, right))%1000000007;
}

int main(){

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<ll> base_arr(n);

    int tree_deepth = int(ceil(log2(n)));
    int tree_size = (1 << (tree_deepth+1));

    vector<ll> seg_tree(tree_size);

    for (int i = 0; i < n; i++)
        scanf("%lld", &base_arr[i]);
    
    // init seg_tree
    seg_init(base_arr, seg_tree, 1, 0, n-1);

    int cycle = m+k;
    while(cycle--) {
        int order;
        scanf("%d", &order);
        
        if(order == 1){
            ll index, temp_num;
            scanf("%lld %lld", &index, &temp_num);
            index--;
            seg_update(seg_tree, 1, 0, n-1, index, temp_num);
            base_arr[index] = temp_num; // update base tree 
        }
        else{
            ll l_idx, r_idx;
            scanf("%lld %lld", &l_idx, &r_idx);
            printf("%lld\n", seg_product(seg_tree, 1, 0, n-1, l_idx-1, r_idx-1));
        }
    }
    
    return 0;
}