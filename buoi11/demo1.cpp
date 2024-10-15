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

// Hàm thêm một nút vào cây BST
Node* insert(Node* root, int value) {
    if (root == nullptr) { // Nếu cây rỗng
        return new Node(value);
    }
    
    if (value < root->data) { // Chèn vào cây con bên trái nếu nhỏ hơn nút gốc
        root->left = insert(root->left, value);
    } else if (value > root->data) { // Chèn vào cây con bên phải nếu lớn hơn nút gốc
        root->right = insert(root->right, value);
    }
    
    return root; // Trả về cây mới sau khi chèn
}

// Hàm in cây theo thứ tự giữa (in-order traversal)
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    cout << "Inorder traversal of the tree: ";
    inOrder(root);
    
    return 0;
}
