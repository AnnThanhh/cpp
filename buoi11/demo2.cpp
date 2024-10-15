#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Hàm tìm kiếm một nút trong cây BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) { // Trả về nếu tìm thấy hoặc cây rỗng
        return root;
    }
    
    if (key < root->data) { // Tìm kiếm trong cây con bên trái
        return search(root->left, key);
    } else { // Tìm kiếm trong cây con bên phải
        return search(root->right, key);
    }
}

int main() {
    Node* root = nullptr;
    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    
    int key = 40;
    Node* result = search(root, key);
    
    if (result != nullptr) {
        cout << "Node " << key << " found in the tree.\n";
    } else {
        cout << "Node " << key << " not found in the tree.\n";
    }
    
    return 0;
}
