#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 
// long long ... abs(answer range) <= 2^63-1
// 세그먼트 트리 

long long seg_init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end){
    
    if(start == end)    // 노드가 리프 노드인 경우
        return tree[node] = arr[start]; // 배열의 그 원소의 값을 가져야 함
    int mid = (start + end)/2;

    // 구간 합  
    return tree[node] = seg_init(arr, tree, node*2, start, mid) + seg_init(arr, tree, node*2+1, mid+1, end);
}

void seg_update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(index < start || index > end) return;
    tree[node] += diff;
    
    // case : tree[node] = diff    
    if(start == end) return;

    int mid = (start + end)/2;
    seg_update(tree, 2*node, start, mid, index, diff);
    seg_update(tree, 2*node+1, mid+1, end, index, diff);

    return; 
}

long long seg_sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0; // case 1 : 포함 x
    if(left <= start && right >= end) return tree[node]; // case 2 : find it ( 종료 조건 )

    int mid = (start + end)/2;

    return seg_sum(tree, node*2, start, mid, left, right) + seg_sum(tree, node*2+1, mid+1, end, left, right);
}

int main(){

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<long long> base_tree(n);

    int tree_deepth = int(ceil(log2(n)));
    int tree_size = (1 << (tree_deepth+1));

    vector<long long> seg_tree(tree_size);

    for (int i = 0; i < n; i++)
        scanf("%lld", &base_tree[i]);
    
    // init seg_tree
    seg_init(base_tree, seg_tree, 1, 0, n-1);

    for (int j = 0; j < m+k; j++)
    {
        int choice;
        long long temp_m, temp_k;
        scanf("%d %lld %lld", &choice, &temp_m, &temp_k);
        if(choice == 1){
            seg_update(seg_tree, 1, 0, n-1, temp_m-1, temp_k-base_tree[temp_m-1]);
            base_tree[temp_m-1] = temp_k; // update base tree 
        }
        else
            printf("%lld\n", seg_sum(seg_tree, 1, 0, n-1, temp_m-1, temp_k-1));
        // "\n" 빼먹어서 계속 틀린듯? 문제 풀 때 집중 좀 하자.
    }
    
    return 0;
}