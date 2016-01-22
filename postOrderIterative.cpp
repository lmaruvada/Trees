#include<iostream>
#include<climits>
#include<vector>
#include<stack>
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

void postOrderIterative( Node * root){
  stack<Node *> temporary;
  stack<Node *> final;
  Node * node;
  temporary.push(root);
  while(!temporary.empty()){
    node = temporary.top();
    temporary.pop();
    final.push(node);
    if(node->left)
      temporary.push(node->left);
    if(node->right)
      temporary.push(node->right); 
  } 
  cout << " \nPostOrder Iterative\n";
  while(!final.empty()){
    node = final.top();
    cout << node->data << " ";
    final.pop();
  }
  cout << "\n";
}

void postOrderRecursive(Node * root){
  if(root==NULL) return;
  postOrderRecursive(root->left);
  postOrderRecursive(root->right);
  cout << root->data << " ";
}

int main(){
  int n;
  int num;
  cout<< "tree:  size and elements\n";
  cin>> n;
  int inputArr[n];
  for (int i =0; i<n; i++){
    cin>> num;
    inputArr[i]=num;
  }
  Node  root[n];
  buildTree(inputArr, n, root);

  cout << "\nIn Order traversal\n";
  InOrder(root);
  
  postOrderIterative(root); 
   
  cout << "PostOrder Recursive\n";
  postOrderRecursive(root);
  cout << endl;
  return 0;
}
