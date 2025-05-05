#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
};
Node* createNode(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
};
Node* insert(Node* root,int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int longpath(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=longpath(root->left);
    int rh=longpath(root->right);
    return max(lh,rh)+1;
}
int minval(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
bool search(Node* root,int key){
    if(root==NULL) return false;
    if(root->data==key) return true;
    if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}
void mirror(Node* root) {
    if (root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}
int main(){
    Node* root = NULL;
    int n,val;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the value of node: ";
        cin>>val;
        root = insert(root,val);
    }
    cout<<"Inorder traversal of the given tree is: ";
    inorder(root);
        cout<<"\nPreorder traversal of the given tree is: ";
    preorder(root);
        cout<<"\nPostorder traversal of the given tree is: ";
    postorder(root);
    cout<<"\nThe number of nodes in longest path:"<<longpath(root);
    cout<<"\nMinimum Value in tree:"<<minval(root);
    int key;
    cout<<"\nEnter Key to search: ";
    cin>>key;
    if(search(root,key)){
        cout<<"\nKey found!!\n";
    }
    else{
        cout<<"Key not found";
    }
    mirror(root);
    cout << "\nInorder after mirroring: ";
    inorder(root);
    
    return 0;
}