#include <iostream>
using namespace std;

// Definition of the TreeNode class
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node
    TreeNode(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

// Pre-order traversal (Root -> Left -> Right)
void preOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        cout << root->value << " ";  // Visit the root
        preOrderTraversal(root->left);  // Recursively traverse the left subtree
        preOrderTraversal(root->right);  // Recursively traverse the right subtree
    }
}

// In-order traversal (Left -> Root -> Right)
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);  // Recursively traverse the left subtree
        cout << root->value << " ";  // Visit the root
        inOrderTraversal(root->right);  // Recursively traverse the right subtree
    }
}

// Post-order traversal (Left -> Right -> Root)
void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);  // Recursively traverse the left subtree
        postOrderTraversal(root->right);  // Recursively traverse the right subtree
        cout << root->value << " ";  // Visit the root
    }
}
    // Function to search for a node in the tree
TreeNode* searchNode(TreeNode* root, int target) 
{
    if (root == NULL || root->value == target) {
        return root;  // Return the node if found, or nullptr if not found
    }

    // Recursively search in the left subtree
    TreeNode* leftResult = searchNode(root->left, target);
    if (leftResult != NULL) {
        return leftResult;  // Node found in the left subtree
    }

    // If not found in the left, recursively search in the right subtree
    return searchNode(root->right, target);
}



// Main function to demonstrate tree traversal
int main() {
    // Creating a sample tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);  // Output: 1 2 4 5 3
    cout << endl;

    cout << "In-order Traversal: ";
    inOrderTraversal(root);  // Output: 4 2 5 1 3
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrderTraversal(root);  // Output: 4 5 2 3 1
    cout << endl;
int target = 5;
    TreeNode* result = searchNode(root, target);

    if (result != NULL) {
        cout << "Node with value " << target << " found in the tree." << endl;
    } else {
        cout << "Node with value " << target << " not found in the tree." << endl;
    }


    return 0;
}

