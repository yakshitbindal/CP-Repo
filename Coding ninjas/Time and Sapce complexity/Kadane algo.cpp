#include<bits/stdc++.h>
using namespace std;

int kadane(int *arr,int n)
{
    int curr_sum=0,max_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum>max_sum)
            max_sum=curr_sum;
        if(curr_sum<0)
            curr_sum=0;
    }
    return max_sum;
}

int main()
{
    int arr[]={0,-1,2,-2,1,0};
    cout<<kadane(arr,6);
}