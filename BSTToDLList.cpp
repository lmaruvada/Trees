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
Node * head = NULL;
Node * current = NULL;
Node * tail = NULL;
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
void attachToLL(Node * n){
  if(head == NULL){
    head = n;
    current = n;
  }
  else{
    current->right = n;
    n->left = current;
    current = n;
  }
}
void InOrderTrav(Node *node){
  if(node == NULL) return;
  InOrderTrav(node->left);
  attachToLL(node);
  InOrderTrav(node->right);
}
void convertToDLL(Node * root){
  InOrderTrav(root); 
  tail = current;
  tail->right = head;
  head->left = tail;
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
  convertToDLL(root);
  Node * temp = head;
  if(temp != NULL){
    cout << temp->data << " ";
    temp = temp->right;
    while(head != temp){
      cout << temp->data << " ";
      temp = temp->right;
    }
  }
  cout << endl;
  temp=tail;
  if(temp != NULL){
    cout << temp->data << " ";
    temp = temp->left;
    while(tail != temp){
      cout << temp->data << " ";
      temp = temp->left;
    }
  }
  return 0;
}

