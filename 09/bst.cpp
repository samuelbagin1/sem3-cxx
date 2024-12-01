#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *smaller;
    Node *greater;
};

struct BST {
    Node *root;
};

Node *addNode(Node *current, const int value) {
    if (!current) {
        return new Node{value, nullptr, nullptr};
    }
    if (current->data > value) {
        current->smaller = addNode(current->smaller, value);
    } else if (current->data < value) {
        current->greater = addNode(current->greater, value);
    }
    return current;
}

void addNode(BST *tree, const int value) {
    tree->root = addNode(tree->root, value);
}

BST * createBST(const initializer_list<int> lst){
    BST *tree{new BST{nullptr}};
    for_each(lst.begin(), lst.end(),[tree](const int& value){ addNode(tree,value);});
    return tree;
}

void preOrder(const Node* current){
    if(current){
        cout << current->data << " ";
        preOrder(current->smaller);
        preOrder(current->greater);
    }
}
void preOrder(const BST* tree){
    preOrder(tree->root);
    cout << endl;
}


void inOrder(const Node* current){
    if(current){
        inOrder(current->smaller);
        cout << current->data << " ";
        inOrder(current->greater);
    }
}
void inOrder(const BST* tree){
    inOrder(tree->root);
    cout << endl;
}

void postOrder(const Node* current){
    if(current){
        postOrder(current->smaller);
        postOrder(current->greater);
        cout << current->data << " ";
    }
}
void postOrder(const BST* tree){
    postOrder(tree->root);
    cout << endl;
}

void levelOrder(const BST* tree){
    queue<Node*> q;
    if(tree->root){
        q.push(tree->root);
    }
    while(!q.empty()){
        if(q.front()->smaller){
            q.push(q.front()->smaller);
        }
        if(q.front()->greater){
            q.push(q.front()->greater);
        }
        cout << q.front()->data << " ";
        q.pop();
    }
    cout << endl;
}


const Node* searchNode(const Node* current, const int& value){
    if (!current) {
        return nullptr;
    }
    if (current->data > value) {
        return searchNode(current->smaller, value);
    } else if (current->data < value) {
        return searchNode(current->greater, value);
    }
    else {
        return current;
    }
}

const Node* searchNode(const BST* tree, const int& value){
    return searchNode(tree->root, value);
}

int main() {

    BST *tree{new BST{nullptr}};
    // add node
    addNode(tree, 5);
    addNode(tree, 1);
    addNode(tree, 10);
    addNode(tree, 3);
    addNode(tree, 5); // duplicate

    BST *tree2 = createBST({10,2,1,3,24,100,16,4});

    // preorder
    preOrder(tree);

    // inorder
    inOrder(tree);

    // postorder
    postOrder(tree);

    // level-order
    levelOrder(tree);

    // search node
    const Node *r1 = searchNode(tree, 5);
    const Node *r2 = searchNode(tree, 0);

    return 0;
}
