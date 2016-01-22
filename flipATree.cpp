#include<iostream>
#include<climits>
#include<queue>
#include<vector>
using namespace std;

class Node{
  public:
    int data;
    Node * left;
    Node * right;
    Node(int val): data(val),left(NULL), right(NULL){};
    Node (): data(0), left(NULL), right(NULL){};
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
void  PrintLineOrder(Node * root){
  if(root == NULL) return;
  queue<Node*> currentLevel, nextLevel;
  currentLevel.push(root);
  while(!currentLevel.empty()){
    Node * curNode = currentLevel.front();
    currentLevel.pop();
    if(curNode){
       cout << curNode->data << " ";
       nextLevel.push(curNode->left);
       nextLevel.push(curNode->right);
    }
    if(currentLevel.empty()){
      cout << "\n";
      queue<Node*> temp = currentLevel;
      currentLevel=nextLevel;
      nextLevel = temp;
    }
  }
}
void reverseTree(Node * node){
  if(node == NULL) return;
  Node * temp = node->left;
  node->left = node->right;
  node->right = temp;
  
  reverseTree(node->left);
  reverseTree(node->right);
}

int main(){
  int n, n1;
  int num;
  cout<< "first tree:  size and elements\n";
  cin>> n;
  int inputArr[n];
  for (int i =0; i<n; i++){
    cin>> num;
    inputArr[i]=num;
  }
  Node  root[n];
  buildTree(inputArr, n, root);

  cout << "\n  Line Order \n";
  PrintLineOrder(root);

  reverseTree(root);
  cout << "\n  Line Order \n";
  PrintLineOrder(root);
  return 0;
}

