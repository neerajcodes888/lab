#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector <int>> arr={{3,4},{55,78},{47,95},{67,88},{99,173},{55,70}};
    int n=arr.size();
    float c,m;
    float xy=0,x=0,y=0,x2=0;
    for(int i=0;i<n;i++)
    {
        x+=arr[i][0];
        y+=arr[i][1];
        xy+=arr[i][0]*arr[i][1];
        x2+=(arr[i][0]*arr[i][0]);
    }
    c=((y*x2)-(x*xy))/((n*x2)-((x2)*(x2)));
    m=((y*x2)-(x*y))/((n*x2)-((x2)*(x2)));
    cout<<"new values of y for every value of x\n";
    for(int i=0;i<n;i++)
    {
        float y=m*arr[i][0]+c;
        cout<<"x= "<<arr[i][0]<<" y= "<<y<<"\n";
    }    
}