#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int,int> twoSum(const vector<int>& nums,int target)
{
    int left=0;
    int right=nums.size()-1;
    while(left<right)
    {
        int sum=nums[left]+nums[right];
        if(sum==target)
        {
            return {left,right};
        }
        else if(sum<target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {-1,-1};
}

int main()
{
    int target,n;
    cin>>target>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    auto result=twoSum(nums,target);
    if(result.first!=-1)
    {
        cout<<result.first<<" "<<result.second<<endl;
    }
    else
    {
        cout<<"No solution found."<<endl;
    }

    return 0;
}