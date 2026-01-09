#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class node {
    public:
        int data;
        int row;
        int col;

        node(int data, int row, int col) {
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };
    class compare {
    public:
        bool operator()(node* a, node* b) { return a->data > b->data; }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        node* maxi = new node(INT_MIN, -1, -1);
        node* mini = new node(INT_MAX, -1, -1);
        priority_queue<node*, vector<node*>, compare> min_heap;

        for (int i = 0; i < nums.size(); i++) {
            node* temp = new node(nums[i][0], i, 0);
            if (temp->data > maxi->data) maxi = temp;
            min_heap.push(temp);
        }
        int ans_mini = min_heap.top()->data;
        int ans_maxi = maxi->data;
        int min_range = ans_maxi - ans_mini;
        while (!min_heap.empty()) {
            mini = min_heap.top();
            min_heap.pop();
            if (min_range > maxi->data - mini->data) {
                min_range = maxi->data - mini->data;
                ans_maxi = maxi->data;
                ans_mini = mini->data;
            }
            if (mini->col + 1 < nums[mini->row].size()) { // element within bounds
                node* newNode = new node(nums[mini->row][mini->col + 1],mini->row, mini->col + 1);
                if (newNode->data > maxi->data) {
                    maxi = newNode;
                }
                min_heap.push(newNode);
            } 
            else break;
        }
        ans.push_back(ans_mini);
        ans.push_back(ans_maxi);
        return ans;
    }
};
int main() {
    
    return 0;
}