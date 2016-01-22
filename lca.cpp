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

bool findPath(Node * node,int val, vector<int> &path){
  if(node->data == val) {
    path.push_back(node->data);
    return true;
  }
  if(node == NULL) return false;
  path.push_back(node->data);
  if(val<node->data){
    node=node->left;
  }
  else{
    node = node->right;
  } 
  return findPath(node, val, path);
}
void lcaNode(Node * node, int val1, int val2){
  vector<int> path1, path2;
  if(findPath(node, val1, path1)){
    if(findPath(node, val2, path2)){
      for(int i =0; i<path1.size();i++){
         if(path1[i] != path2[i]) {
            cout << "FindLCA(" << val1 << ","<< val2<< ")";
            cout << path1[i-1] << endl;
            return;
         }
      }
    }
    else{
      cout << "No LCA value for (" << val1 << ","<< val2<< ")";
    }
  }
  else{
      cout << "No LCA value for (" << val1 << ","<< val2<< ")";
  }
  return;
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
  PrintLineOrder(root);
  cout << endl;
  lcaNode(root, 10, 20);
  lcaNode(root, 50, 80);
  lcaNode(root, 20, 60);
  

  return 0;
}

