#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
  public:
    int data;
    Node * left;
    Node * right;
    Node(int val): data(val),left(NULL), right(NULL){};
    Node (): data(0), left(NULL), right(NULL){};
};

Node * buildTree(vector<int>in,int inStart,int inEnd,
                 vector<int> pre,int preStart,int preEnd)
{
  if(inStart>inEnd) return NULL;
  int val = pre[preStart];
 
  Node * root = new Node(val);

  // find the position of root in inOrderArray
  int posOfRoot =0;
  for( int ii=inStart; ii<=inEnd; ii++){
    if(in[ii] == val){
      posOfRoot = ii;
      break;
    }
  }
  int index = posOfRoot - inStart; 
  root->left = buildTree(in, inStart, (posOfRoot-1), 
                         pre, (preStart+1), index-1);
  root->right = buildTree(in, (posOfRoot+1), inEnd, 
                          pre, preStart + index+1, preEnd);
  return root;
}

void InOrder( Node * node){
  if(node== NULL) return;
  InOrder(node->left);
  cout << node->data << " ";
  InOrder(node->right);
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

void constrctTree(vector<int> iInOrderArray, vector<int> iPreOrderArray){
  int size = iInOrderArray.size()-1;
  Node * root = buildTree(iInOrderArray, 0, size, iPreOrderArray, 0, size);
  cout << "\n  Line Order \n";
  PrintLineOrder(root);

}

int main (){

  int n;
  int num;
  cin>> n;
  vector<int> inOrderArr;
  for (int i =0; i<n; i++){
    cin>> num;
    inOrderArr.push_back(num);
  }

  vector<int> preOrderArr;
  for (int i =0; i<n; i++){
    cin>> num;
    preOrderArr.push_back(num);
  }

  constrctTree(inOrderArr, preOrderArr);
  return 0;
}
