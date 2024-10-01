#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

// TreeNode structure representing each node of the tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to build a binary tree from inorder and postorder traversals
    TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return nullptr;
        }

        // Map to store the indices of elements in inorder traversal
        map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }

        // Recursive function to construct the tree
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, indexMap);
    }

private:
    // Recursive helper function to construct a tree from inorder and postorder traversals
    TreeNode* buildTreeHelper(const vector<int>& inorder, int inStart, int inEnd, 
                              const vector<int>& postorder, int postStart, int postEnd, 
                              const map<int, int>& indexMap) {
        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        // Last element of postorder is the root node
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // Get the index of the root in inorder traversal
        int inRootIndex = indexMap.at(rootVal);
        int leftSubtreeSize = inRootIndex - inStart;

        // Build the left and right subtrees recursively
        root->left = buildTreeHelper(inorder, inStart, inRootIndex - 1, postorder, postStart, postStart + leftSubtreeSize - 1, indexMap);
        root->right = buildTreeHelper(inorder, inRootIndex + 1, inEnd, postorder, postStart + leftSubtreeSize, postEnd - 1, indexMap);

        return root;
    }
};

// Function to print inorder traversal of a tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Function to take input for a vector
void inputVector(vector<int>& vec, const string& prompt) {
    int n;
    cout << "Enter the number of elements for " << prompt << ": ";
    cin >> n;
    cout << "Enter " << prompt << " elements: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
}

// Main function
int main() {
    vector<int> inorder, postorder;

    // Input for inorder and postorder vectors
    inputVector(inorder, "Inorder");
    inputVector(postorder, "Postorder");

    // Display the input vectors
    cout << "Inorder Vector: ";
    for (const int& val : inorder) cout << val << " ";
    cout << endl;

    cout << "Postorder Vector: ";
    for (const int& val : postorder) cout << val << " ";
    cout << endl;

    // Create a solution object and build the tree
    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    // Print the inorder traversal of the constructed tree
    cout << "Inorder of the Constructed Binary Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
