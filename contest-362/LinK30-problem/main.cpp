#include <iostream>
using namespace std;
 
const int N=100007;
int n;
int numbers[N],tmp[N];
 
void mergesort(int nums[],int left,int right)
{
    if(left>=right)return;
    int mid=left+right>>1;
 
    mergesort(nums,left,mid),mergesort(nums,mid+1,right);
 
    int k=0,p=left,q=mid+1;
    while(p<=mid&&q<=right)
    {
        if(nums[p]<=nums[q])
            tmp[k++]=nums[p++];
        else
            tmp[k++]=nums[q++];
    }
    while(p<=mid)
        tmp[k++]=nums[p++];
    while(q<=right)
        tmp[k++]=nums[q++];
 
    for(int i=left,k=0;i<=right;i++,k++)
        nums[i]=tmp[k];
}
 
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&numbers[i]);
 
    mergesort(numbers,0,n-1);
 
    for(int i=0;i<n;i++)
        printf("%d ",numbers[i]);
 
    return 0;
}