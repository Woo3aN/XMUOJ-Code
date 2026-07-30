#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100007;
int nums[N];

int findLeftBound(int left, int right, int target) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int findRightBound(int left, int right, int target) {
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (nums[mid] <= target) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    while (q--) {
        int k;
        scanf("%d", &k);
        
        int leftBound = findLeftBound(0, n - 1, k);
        if (nums[leftBound] != k) {
            cout << "-1 -1" << endl;
        } else {
            int rightBound = findRightBound(0, n - 1, k);
            cout << leftBound << " " << rightBound << endl;
        }
    }
    
    return 0;
}
