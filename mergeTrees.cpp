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

void InOrder( Node * node, vector<int> &arr){
  if(node == NULL) return;
  InOrder(node->left, arr);
  arr.push_back(node->data);
  InOrder(node->right, arr);
}

Node * insertT(Node * root, int val){
  //Node * newOne = new Node(val);
  if(root == NULL) 
    root = new Node(val); 
  else{
    Node * current = root;
    Node * parent;
    while(true){
      parent = current;
      if(val < current->data){
        current = current->left;
        if(current == NULL){
          parent->left = new Node(val);
          return root;
        }
      }
      else{
        current = current->right;
        if(current == NULL){
          parent->right = new Node(val);
          return root;
        }
      }
    }
  }
  return root;
}

vector<int> mergeArrays(vector<int> a1, vector<int> a2){
  vector<int> target;
  int ia1=0, ia2=0; 

  while((ia1<a1.size()) && (ia2<a2.size())){
    if(a1[ia1] <a2[ia2]){
       target.push_back(a1[ia1]);
       ia1++;  
    }
    else{
      target.push_back(a2[ia2]);
      ia2++;
    }
  }
  while(ia1<a1.size()){
    target.push_back(a1[ia1]);
    ia1++;
  }
  while(ia2<a2.size()){
    target.push_back(a2[ia2]);
    ia2++;
  }
  return target;
}
// form a BST from a sorted array
Node * formTree(vector<int> &arr, int start, int end){
  if(start>end) return NULL ;
  int mid =(start+end)/2;
  Node * root = new Node(arr[mid]);
  root->left = formTree(arr, start, mid-1);
  root->right = formTree(arr, mid+1, end); 
  return root;
}

Node * mergeTrees(Node* t1, Node* t2){
  if(t1 == NULL) return t2;
  if(t2 == NULL) return t1;
  // Put the trees in inorder arrays. These will be sorted arrays
  int n, n1; // count number of nodes in the two trees. 
  vector<int> arr1, arr2;
  InOrder(t1, arr1);
  InOrder(t2, arr2); 

  // merge the two sorted arrays into one single array.
  vector<int> arrR;
  arrR = mergeArrays(arr1, arr2);

  // from a soreted array create a balanced BST. 
  Node * newTree = formTree(arrR, 0, arrR.size()-1);
  return newTree; 
}

bool isBST(Node * node, int low, int high){
  if(!node) return true;
  if((node->data > low) && (node->data < high))
    return (isBST(node->left, low, node->data) &&
            isBST(node->right, node->data, high));
  else
    return false;
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
  
  cout<< "second tree:  size and elements\n";
  cin>> n1;
  int inputArr1[n1];
  for (int i =0; i<n1; i++){
    cin>> num;
    inputArr1[i]=num;
  }
  Node  root1[n1];
  buildTree(inputArr1, n1, root1); 

  /********************************/
  //cout << "\nIn Order traversal\n";
  //InOrder(root);
  //cout << "\nIn Order traversal\n";
  //InOrder(root1);
  /*******************************/
  Node * mtree = NULL;
  mtree = mergeTrees(root, root1);
  cout << "\nIn Order traversal\n";
  InOrder(mtree);
  cout << "\n"; 
  /********************************/
  PrintLineOrder(mtree);
  /********************************/
  if(isBST(mtree, INT_MIN, INT_MAX))
    cout << " Tree is BST \n";
  else
    cout << "Tree is NOT BST \n";

  /*******************************/
  return 0;
}
