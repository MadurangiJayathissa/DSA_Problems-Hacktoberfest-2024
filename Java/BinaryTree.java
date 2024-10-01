// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    // Default constructor
    TreeNode() {}

    // Constructor with value
    TreeNode(int val) {
        this.val = val;
    }

    // Constructor with value, left child, and right child
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class BinaryTree {
    
    // Method to find the maximum depth of the binary tree
    public int maxDepth(TreeNode root) {
        // Base case: if the node is null, the depth is 0
        if (root == null) {
            return 0;
        }
        
        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        
        // Return the maximum of the two depths plus one for the current node
        return Math.max(leftDepth, rightDepth) + 1;
    }

    // Main method to test the code
    public static void main(String[] args) {
        // Constructing the binary tree: [3,9,20,null,null,15,7]
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        
        // Creating an instance of BinaryTree and calculating maximum depth
        BinaryTree tree = new BinaryTree();
        int maxDepth = tree.maxDepth(root);
        
        // Output the result
        System.out.println("The maximum depth of the tree is: " + maxDepth);
    }
}

