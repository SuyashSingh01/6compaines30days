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
// Amount of Time Take to Tree  To Be Infected and Tree Burning to Be Done  are  same problem
class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> mp;
    void preorder(TreeNode *root, int t, TreeNode *&src, int &n)
    {
        if (!root)
            return;
        if (root->val == t)
            src = root;
        n = max(root->val, n);
        if (root->left)
        {
            mp[root->left] = root;
        }
        preorder(root->left, t, src, n);
        if (root->right)
        {
            mp[root->right] = root;
        }
        preorder(root->right, t, src, n);
    }
    int amountOfTime(TreeNode *root, int start)
    {
        TreeNode *src = nullptr;
        int n = 0;
        preorder(root, start, src, n);
        queue<pair<TreeNode *, int>> q;
        // cout<<"- "<<src->val<<"\n";
        q.push({src, 0});
        int res = 0;
        // for(auto it:mp)cout<<it.first->val<<" -> "<<it.second->val<<endl;
        vector<int> visit(n + 1, 0);
        visit[src->val] = 1;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            res = max(res, it.second);
            if (mp.find(it.first) != mp.end() && visit[mp[it.first]->val] == 0)
            {
                q.push({mp[it.first], it.second + 1});
                visit[mp[it.first]->val] = 1;
            }
            if (it.first->left && visit[it.first->left->val] == 0)
            {
                q.push({it.first->left, it.second + 1});
                visit[it.first->left->val] = 1;
            }
            if (it.first->right && visit[it.first->right->val] == 0)
            {
                q.push({it.first->right, it.second + 1});
                visit[it.first->right->val] = 1;
            }
        }
        return res;
    }
};