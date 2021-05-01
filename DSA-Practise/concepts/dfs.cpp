// leetcode version on a Binary Tree
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
    void display_node() {
        if (right == nullptr && left  == nullptr) {
            cout << "Leaf: " << val << "\n";
        }
        else {
            cout << "Node: " << val;
            if (left != nullptr)
                cout << " Left: " << left->val;
            if (right != nullptr)
                cout << " Right: " << right->val;
            cout << "\n";
        }
    }
};
int main(){
    int n;
    cin >> n;
    vector<TreeNode> vec(n);
    for(int i=0; i<n; i++){
        int val, par_idx, par_val;
        cin >> val;
        vec[i] = TreeNode(val);
        if (i == 0)
            continue; /* vec[0] = TreeNode(val); */
        else if (i & 1) {
            par_idx = (i-1)/2;
            par_val = vec[par_idx].val;
            vec[par_idx].left = &vec[i];
        }
        else {
            par_idx = (i-2)/2;
            par_val = vec[par_idx].val;
            vec[par_idx].right = &vec[i];
        }
    }
    /* display node vector */
    for (auto &i: vec) {
        i.display_node();
    }
}
