#include<iostream>
using namespace std;
int main()
{
    int n,sum=0;
cout<<"Enter no. of elements(Data):";
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
cin>>a[i];
}
    cout<<" Original array:";
 
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
        sum+=a[i];
    }
    float mean=sum/n;
    cout<<"\n1: by ignoring values resultend array\n";
        for(int j=0;j<n;j++)
    {
        if(a[j]==-1)
            continue;
        else
            cout<<a[j]<<" ";
    }
    cout<<"\n2:by replacig with mean values\n";
            for(int j=0;j<n;j++)
    {
        if(a[j]==-1)
            a[j]=mean;
            cout<<a[j]<<" ";
    }
    
}