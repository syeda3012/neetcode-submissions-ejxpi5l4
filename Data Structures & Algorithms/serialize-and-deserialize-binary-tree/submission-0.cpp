/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        preorder(root, result);
        return result;
    }
    void preorder(TreeNode*root, string &result){
        if(root == NULL){
            result += "N,";
            return;
        }
        result += to_string(root->val) + ",";
        preorder(root->left, result);
        preorder(root->right, result);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
        
    }
    TreeNode* buildTree(stringstream& ss){
        string val;
        getline(ss, val, ',');
        if(val == "N")return NULL;
        TreeNode*node = new TreeNode(stoi(val));
        node->left = buildTree(ss);
        node->right = buildTree(ss);

        return node;
    }
    
};
