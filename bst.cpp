#include <iostream>
using namespace std;

class BST{
    struct TNode {
        int data;
        TNode *left;
        TNode *right;
    };
    TNode *root;
    public:

    BST(){
        root = NULL;
    }
    TNode *createNode(int data){
        TNode *newNode = new TNode;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    TNode* insert(TNode *root, int data){
        if(root == NULL){
            root = createNode(data);
        }
        else if(data <= root->data){
            root->left = insert(root->left, data);
        }
        else{
            root->right = insert(root->right, data);
        }
        return root;
    }

    void insertD(int data){
        root = insert(root, data);
    }

    void inorder(TNode *root){
        if(root != NULL){
            inorder(root->left);    //left
            cout << root->data << " ";
            inorder(root->right);   //right
        }
    }
    void print(){
        inorder(root);
    }

    void inverseTree(){
        TNode *temp = root;
        TNode *temp2 = NULL;
        while(temp != NULL){
            temp2 = temp->left;
            temp->left = temp->right;
            temp->right = temp2;
            temp = temp->left;
        }   
    }


};

int main(){
    BST bst;
    bst.insertD(10);
    bst.insertD(5);
    bst.insertD(15);
    bst.insertD(2);
    bst.insertD(7);
    bst.insertD(12);
    bst.print();
    cout << endl;
    bst.inverseTree();
    bst.print();cout << endl;
}