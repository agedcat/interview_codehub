#include<iostream>
#include<vector>

int partion(std::vector<int>&nums,int left,int right)
{
     int temp=nums[left];
    while(left<right)
    {
        while(nums[right]>temp&&left<right) 
        {
            right--;
        }
        nums[left]=nums[right];
        while(nums[left]<=temp&&left<right) 
        {
            left++;
        }
        nums[right]=nums[left];
    }
    nums[left]=temp;
    return left;
}

int findKth(std::vector<int>&nums,int left,int right,int k)
{
    int ans;
    int index=partion(nums,left,right);
    int kth=right-index+1;
    if(kth==k) ans=nums[index];
    if(kth>k) ans=findKth(nums,index+1,right,k);
    if(kth<k) ans=findKth(nums,left,index-1,k-kth);
    return ans;
}

int findKthLargest(std::vector<int>&nums,int k)
{
    return findKth(nums,0,nums.size()-1,k);
}

int main(void)
{
    std::vector<int>nums={2,1};
    int k=2;
    int ans=findKthLargest(nums,k);
    std::cout<<ans<<std::endl;
    system("pause");
    return 0;

}