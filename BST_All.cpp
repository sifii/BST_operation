#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert_bst(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }
    
    if(val< root->data){
        root ->left = insert_bst(root->left, val);}
    else{
        root ->right = insert_bst(root->right,val);
    }
    return root;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* delete_bst(Node* root, int key){
    if(key<root->data){
        root->left = delete_bst(root->left,key);
    }
    else if(key > root->data){
        root->right = delete_bst(root->right,key);
    }
    
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp =inorderSucc(root->right);
        root->data =temp->data;
        root->right = delete_bst(root->right, temp->data);
    }
    return root;
}

Node* search_bst(Node* root, int key){
    if(root== NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return search_bst(root->left, key);
    }
    return search_bst(root->right, key);
}



int main()
{
    
    int n,s,i,d,u;
    cout<<"Enter the No. of element in Bst ";
    cin>>n;
    int a[n];
     cout<<"enter element"<<endl;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    Node *root = NULL;
    root = insert_bst(root,a[0]);
    for(int i = 1;i<n;i++){
        insert_bst(root,a[i]);
    } 
    
    cout<<"PREORDER :";
    preorder(root); 
    cout<<endl;
    cout<<"INORDER :";
    inorder(root);
    cout<<endl; 
    cout<<"POSTORDER :";
    postorder(root);
    cout<<endl;
    cout<<"Search element :";
    cin>>s;
    if(search_bst(root, s) == NULL){
        cout<<"key not exist"<<endl;
    }else{
        cout<<"key exist"<<endl;
    }
    cout<<"Insert element :";
    cin>>i;
    insert_bst(root,i);
    cout<<"Yes Insert_print inorder :";
    inorder(root);
    cout<<endl;
    cout<<"Delete element :";
    cin>>d;
    if(search_bst(root, d) == NULL){
        inorder(root);
        cout<<"look delete element not exist"<<endl;
    }else{
        root = delete_bst(root,d);
        cout<<"Yes Delete_print inorder :";
        inorder(root);
    }
    cout<<endl;
    cout<<"Update element :";
    cin>>u;
    if(search_bst(root, u) == NULL){
        inorder(root);
        cout<<"look update element not exist"<<endl;
    }else{
        int p;
        cout<<"update by :";
        cin>>p;
        root = delete_bst(root,u);
        insert_bst(root,p);
        inorder(root);
    }
    cout<<endl;
   
    
    return 0;
}


