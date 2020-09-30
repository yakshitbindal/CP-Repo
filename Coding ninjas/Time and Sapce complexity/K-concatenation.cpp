#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int size=n;
        if(k>1)
            size=n*2;
        long* a=new long[size];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(size==n*2)
        {
            for(int i=n;i<2*n;i++)
            {
                a[i]=a[i-n];
            }
        }

        //kadane's algorithm
        long curr_sum=0;
        long max_sum=0;
        for(int i=0;i<size;i++)
        {
            curr_sum+=a[i];
            if(curr_sum>max_sum)
            {
                max_sum=curr_sum;
            }
            if(curr_sum<0)
            {
                curr_sum=0;
            }
        }

        long arr_sum=0;
        for(int i=0;i<n;i++)
        {
            arr_sum+=a[i];
        }

        long ans=0;
        if(arr_sum>0 && k>1)
        {
            ans = max_sum + (k-2)*arr_sum;
        }
        else
        {
            ans=max_sum;
        }
        
        cout<<ans<<endl;
    }
}