#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

vector<vector<int>> threeSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
            while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= target) k--;
            if (nums[i] + nums[j] + nums[k] == target) {
                res.push_back({nums[i], nums[j], nums[k]});
            }
        }
    }
    return res;
}

int main() {
    int target, n, x;
    vector<int> a;
    vector<vector<int>> res;
    cin >> target >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    res = threeSum(a, target);
    sort(res.begin(), res.end(), comp);
    for (auto line : res) {
        cout << line[0] << " " << line[1] << " " << line[2] << endl;
    }
    return 0;
}
