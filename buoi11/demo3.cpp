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

// Hàm tìm nút nhỏ nhất trong cây con bên phải (hữu ích cho việc xóa)
Node* minValueNode(Node* node) {
    Node* current = node;
    
    // Đi xuống cây con bên trái để tìm nút nhỏ nhất
    while (current && current->left != nullptr) {
        current = current->left;
    }
    
    return current;
}

// Hàm xóa một nút khỏi cây BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root; // Cây rỗng
    
    // Nếu key nhỏ hơn nút gốc, tiếp tục tìm trong cây con bên trái
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // Nếu key lớn hơn nút gốc, tiếp tục tìm trong cây con bên phải
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // Đã tìm thấy nút cần xóa
    else {
        // Nút chỉ có 1 con hoặc không có con
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Nút có 2 con, tìm nút nhỏ nhất trong cây con bên phải
        Node* temp = minValueNode(root->right);
        
        // Thay thế giá trị của nút cần xóa bằng giá trị của nút nhỏ nhất
        root->data = temp->data;
        
        // Xóa nút nhỏ nhất bên cây con phải
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
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
    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    
    cout << "Inorder traversal before deletion: ";
    inOrder(root);
    
    root = deleteNode(root, 50);
    
    cout << "\nInorder traversal after deletion: ";
    inOrder(root);
    
    return 0;
}
