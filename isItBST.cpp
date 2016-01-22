#include<iostream>
#include<climits>
using namespace std;

class Node{
  public:
    int data;
    Node * left;
    Node * right;
    Node(int val): data(val),left(NULL), right(NULL){};
    Node (): data(0), left(NULL), right(NULL){};
};
class Tree{
  public: 
    Node * root;
    Tree(): root(NULL){};
};

void buildTree(int * arr, int size, Node * nodeArr){
  
  for(int i=0; i<size; i++){
    if(arr[i]!=0){
      if(i==0){
        nodeArr[0].data= arr[i];
      }
      else{
        nodeArr[i].data = arr[i];
        int parentPos= (i-1)/2;
        //Node parent = nodeArr[parentPos];
        if(i%2 == 1) 
           nodeArr[parentPos].left=&nodeArr[i];
        else
           nodeArr[parentPos].right=&nodeArr[i];
      }
    } 
  }
  return ;
}

void InOrder( Node * node){
  if(node== NULL) return;
  InOrder(node->left);
  cout << node->data << " ";
  InOrder(node->right);
}

bool isBST(Node * node, int low, int high){
  if(!node) return true;
  if((node->data > low) && (node->data < high))
    return (isBST(node->left, low, node->data) &&
            isBST(node->right, node->data, high));
  else 
    return false;
}

int main(){
  int n;
  int num;
  cin>> n;
  int inputArr[n];
  for (int i =0; i<n; i++){
    cin>> num;
    inputArr[i]=num;
  }
  Node  root[n];
  buildTree(inputArr, n, root); 
  
  if(isBST(root, INT_MIN, INT_MAX))
    cout << " Tree is BST \n";
  else
    cout << "Tree is NOT BST \n";

  /********************************/
  cout << "In Order traversal\n";
  InOrder(root);
  /*******************************/

  return 0;
}
