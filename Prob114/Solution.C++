// Link To Problem:-
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// METHOD 1:-

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        if (root->left != NULL)
        {
            TreeNode *temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;

            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        flatten(root->right);
    }
};

// METHOD 2:-

class Solution
{
private:
    TreeNode *prev = NULL;

public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};
