#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&ans){
    for (int i = 0 ; i< ans.size(); i ++ ){
         cout<< ans[i]<<" ";
    }
}

void clustring(vector<int>ans){
    int n=ans.size();
    int sum=0;
    int set_mean=4;
    int msize=(ans[n-1] - ans[0])/set_mean;
    int start=ans[0];
    int end=start + msize;

    for (int i=0; i < set_mean; i++){
        sum=0;
        int cnt=0;
        for(int j=0;j<n;j++){
            if(ans[j] >= start && ans[j] <= end){
                sum+=ans[j];
                cnt++;
            }
        }
        int mean=sum/cnt;
        for(int j=0;j<n;j++){
            if(ans[j] >= start && ans[j] <= end){
                ans[j]=mean;
            }
        }
        start+=set_mean;
        end+=set_mean;
    }
    ans[n-1]=ans[n-2];
    print(ans);
}

int  main()
{
    vector<int>ans{22,56,77,89,24,67,22,90,99,84,39,123,111,234,567,789};
    sort(ans.begin(),ans.end());
    cout<<"\noriginal data with mising value: ";
    print(ans);

    cout<<"\n\n after clustring : ";
   clustring(ans);

}