#include <bits/stdc++.h>
using namespace std;
#define fastIo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n; // [1, 26]


struct Node{
  char value;

  char left;
  char right;
};

Node binaryTree[27];

void preOrder(Node _node){
  //preorder p > l > r // dfs
  cout << _node.value;
  if(_node.left != '.')
    preOrder(binaryTree[_node.left - '@']);
  if(_node.right != '.')
    preOrder(binaryTree[_node.right - '@']);

}

void inOrder(Node _node){
  //inorder l > r > p // 
  if(_node.left != '.')
    inOrder(binaryTree[_node.left - '@']);
  cout << _node.value;
  if(_node.right != '.')
    inOrder(binaryTree[_node.right - '@']);
}

void PostOrder(Node _node){
  //postorder l > p > r // 
  if(_node.left != '.')
    PostOrder(binaryTree[_node.left - '@']);
  
  if(_node.right != '.')
    PostOrder(binaryTree[_node.right - '@']);
  cout << _node.value;
}



int main(){ // parent가 0이면 NULL값인거임 

  fastIo; 
  
  cin >> n;
  char p, l, r; // A - '@' = 1
  
  for (int i = 0; i < n; i++){
    cin >> p >> l >> r;
    Node node;

    node.value = p;
    node.left = l;
    node.right = r;
    binaryTree[p - '@'] = node;
  }

  Node root = binaryTree[1]; 

  preOrder(root);
  cout << "\n";
  inOrder(root);
  cout << "\n";
  PostOrder(root);
  cout << "\n";

  return 0;
}