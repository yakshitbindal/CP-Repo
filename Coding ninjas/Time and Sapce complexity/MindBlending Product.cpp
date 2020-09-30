#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long ans[n];
        long lp=1;
        long rp=1;
        for(int i=0;i<n;i++)
        {
            ans[i]=lp;
            lp=lp*arr[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=ans[i]*rp;
            rp=rp*arr[i];
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
    }
}