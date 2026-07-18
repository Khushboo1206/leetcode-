class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& visited) {

        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (visited[i])
                continue;

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;

            visited[i] = true;
            path.push_back(nums[i]);

            backtrack(nums, path, visited);

            path.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> path;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, path, visited);

        return ans;
    }
};