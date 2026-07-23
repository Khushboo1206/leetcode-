class Solution {
public:
    int postIndex;

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int start, int end) {

        if (start > end)
            return nullptr;

        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int index = start;
        while (inorder[index] != rootValue)
            index++;

        root->right = solve(inorder, postorder, index + 1, end);
        root->left = solve(inorder, postorder, start, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        return solve(inorder, postorder, 0, inorder.size() - 1);
    }
};