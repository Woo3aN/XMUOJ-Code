#include <iostream>
using namespace std;

const int N = 100007;
int n;
int numbers[N], tmp[N];

long long mergesort(int nums[], int left, int right)
{
    if (left >= right)
        return 0;
    int mid = left + right >> 1;

    long long result = mergesort(nums, left, mid) + mergesort(nums, mid + 1, right);

    int k = 0, p = left, q = mid + 1;
    while (p <= mid && q <= right)
    {
        if (nums[p] <= nums[q])
            tmp[k++] = nums[p++];
        else
        {
            result += mid - p + 1;
            tmp[k++] = nums[q++];
        }
    }
    while (p <= mid)
        tmp[k++] = nums[p++];
    while (q <= right)
        tmp[k++] = nums[q++];

    for (int i = left, k = 0; i <= right; i++, k++)
        nums[i] = tmp[k];

    return result;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    cout << mergesort(numbers, 0, n - 1);

    return 0;
}