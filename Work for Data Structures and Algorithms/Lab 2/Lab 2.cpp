#include <iostream>
#include <algorithm>
#include <queue>

class BSTandAVL {
private:
    // Node structure for both BST and AVL
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height; // For AVL balancing

        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* bstRoot;
    Node* avlRoot;

public:
    // Constructor
    BSTandAVL() : bstRoot(nullptr), avlRoot(nullptr) {}

    // Destroyer
    ~BSTandAVL() {
        clearBST();
        clearAVL();
    }

    // ==================== BST METHODS ====================

    // BST Insert
    void insertBST(int key) {
        bstRoot = insertBST(bstRoot, key);
    }

    // BST Search
    bool searchBST(int key) {
        return searchBST(bstRoot, key);
    }

    // BST Delete
    void deleteBST(int key) {
        bstRoot = deleteBST(bstRoot, key);
    }

    // BST Inorder Traversal
    void inorderBST() {
        std::cout << "BST Inorder: ";
        inorderBST(bstRoot);
        std::cout << std::endl;
    }

    // BST Level Order Traversal
    void levelOrderBST() {
        std::cout << "BST Level Order: ";
        levelOrderBST(bstRoot);
        std::cout << std::endl;
    }

    // Clear BST
    void clearBST() {
        clearBST(bstRoot);
        bstRoot = nullptr;
    }

    // ==================== AVL METHODS ====================

    // AVL Insert
    void insertAVL(int key) {
        avlRoot = insertAVL(avlRoot, key);
    }

    // AVL Search
    bool searchAVL(int key) {
        return searchAVL(avlRoot, key);
    }

    // AVL Delete
    void deleteAVL(int key) {
        avlRoot = deleteAVL(avlRoot, key);
    }

    // AVL Inorder Traversal
    void inorderAVL() {
        std::cout << "AVL Inorder: ";
        inorderAVL(avlRoot);
        std::cout << std::endl;
    }

    // AVL Level Order Traversal
    void levelOrderAVL() {
        std::cout << "AVL Level Order: ";
        levelOrderAVL(avlRoot);
        std::cout << std::endl;
    }

    // Check if AVL tree is balanced
    bool isBalancedAVL() {
        return isBalanced(avlRoot);
    }

    // Clear AVL
    void clearAVL() {
        clearAVL(avlRoot);
        avlRoot = nullptr;
    }

private:

    // ==================== BST PRIVATE METHODS ====================

    Node* insertBST(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertBST(root->left, key);
        }
        else if (key > root->key) {
            root->right = insertBST(root->right, key);
        }

        return root;
    }

    bool searchBST(Node* root, int key) {
        if (root == nullptr) return false;
        if (root->key == key) return true;

        if (key < root->key) {
            return searchBST(root->left, key);
        }
        else {
            return searchBST(root->right, key);
        }
    }

    Node* deleteBST(Node* root, int key) {
        if (root == nullptr) return root;

        if (key < root->key) {
            root->left = deleteBST(root->left, key);
        }
        else if (key > root->key) {
            root->right = deleteBST(root->right, key);
        }
        else {
            // Node to be deleted found
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteBST(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorderBST(Node* root) {
        if (root != nullptr) {
            inorderBST(root->left);
            std::cout << root->key << " ";
            inorderBST(root->right);
        }
    }

    void levelOrderBST(Node* root) {
        if (root == nullptr) return;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            std::cout << current->key << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    void clearBST(Node* root) {
        if (root != nullptr) {
            clearBST(root->left);
            clearBST(root->right);
            delete root;
        }
    }

    // ==================== AVL PRIVATE METHODS ====================

    // Get height of node
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Get balance factor
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // AVL Insert
    Node* insertAVL(Node* node, int key) {
        // 1. Perform normal BST insertion
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insertAVL(node->left, key);
        }
        else if (key > node->key) {
            node->right = insertAVL(node->right, key);
        }
        else {
            return node; // Duplicate keys not allowed
        }

        // 2. Update height of current node
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        // 3. Get balance factor
        int balance = getBalance(node);

        // 4. Perform rotations if unbalanced

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // AVL Search
    bool searchAVL(Node* root, int key) {
        if (root == nullptr) return false;
        if (root->key == key) return true;

        if (key < root->key) {
            return searchAVL(root->left, key);
        }
        else {
            return searchAVL(root->right, key);
        }
    }

    // AVL Delete
    Node* deleteAVL(Node* root, int key) {
        // 1. Perform standard BST delete
        if (root == nullptr) return root;

        if (key < root->key) {
            root->left = deleteAVL(root->left, key);
        }
        else if (key > root->key) {
            root->right = deleteAVL(root->right, key);
        }
        else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else {
                    *root = *temp;
                }
                delete temp;
            }
            else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteAVL(root->right, temp->key);
            }
        }

        if (root == nullptr) return root;

        // 2. Update height
        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

        // 3. Get balance factor
        int balance = getBalance(root);

        // 4. Perform rotations if unbalanced

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorderAVL(Node* root) {
        if (root != nullptr) {
            inorderAVL(root->left);
            std::cout << root->key << " ";
            inorderAVL(root->right);
        }
    }

    void levelOrderAVL(Node* root) {
        if (root == nullptr) return;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            std::cout << current->key << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    bool isBalanced(Node* root) {
        if (root == nullptr) return true;

        int balance = getBalance(root);
        return (abs(balance) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }

    void clearAVL(Node* root) {
        if (root != nullptr) {
            clearAVL(root->left);
            clearAVL(root->right);
            delete root;
        }
    }
};

int main() {
    BSTandAVL tree;

    std::cout << "=== Testing BST ===\n";
    tree.insertBST(50);
    tree.insertBST(30);
    tree.insertBST(70);
    tree.insertBST(20);
    tree.insertBST(40);
    tree.insertBST(60);
    tree.insertBST(80);

    tree.inorderBST();
    tree.levelOrderBST();

    std::cout << "Search 40 in BST: " << (tree.searchBST(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 100 in BST: " << (tree.searchBST(100) ? "Found" : "Not Found") << std::endl;

    std::cout << "\n=== Testing AVL ===\n";
    tree.insertAVL(10);
    tree.insertAVL(20);
    tree.insertAVL(30);
    tree.insertAVL(40);
    tree.insertAVL(50);
    tree.insertAVL(25);

    tree.inorderAVL();
    tree.levelOrderAVL();

    std::cout << "Search 30 in AVL: " << (tree.searchAVL(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Is AVL balanced: " << (tree.isBalancedAVL() ? "Yes" : "No") << std::endl;

    return 0;
}