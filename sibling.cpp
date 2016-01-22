#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;
class Node{
  public:
    int data;
    Node * left;
    Node * right;
    Node * nextRight;
    Node(int val): data(val),left(NULL), right(NULL), nextRight(NULL){};
    Node (): data(0), left(NULL), right(NULL), nextRight(NULL){};
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
vector <Node *> siblings;
bool nodeIsLeaf( Node * node){
  if(( node->left == NULL) && (node->right== NULL)) 
    return true;
  else 
    return false; 
}
void connectSibling(Node * n){
  if(nodeIsLeaf(n)){
    if(siblings.empty())
      siblings.push_back(n);
    else{
      siblings[siblings.size()-1]->nextRight=n;
      siblings.push_back(n);
    }
  }
  return;
}
void  buildSiblingP(Node *node){
  if(node == NULL) return;
  buildSiblingP(node->left);
  connectSibling(node);
  buildSiblingP(node->right);
}

void set_sibling_pointer(Node *root){
  Node *slow,*fast;
  slow=fast=root;
  while(slow != NULL){
    if(slow->left){
      fast->nextRight=slow->left;
      fast=fast->nextRight;
    }
    if(slow->right){
      fast->nextRight=slow->right;
      fast=fast->nextRight;
    }
    slow=slow->nextRight;           
  }
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

  buildSiblingP(root);

  Node * current = siblings[0];
  cout << endl;

  while(current){
    cout << current->data << " ";
    current = current->nextRight;
  }

  set_sibling_pointer(root);
  cout << endl;
  Node * curr = root;
  while(curr){
    cout << curr->data << " ";
    curr = curr->nextRight;
  }
  return 0;
}
