#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter no. of elements(Data):";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int sum = 0;
    float a2[n];
    int Max = *max_element(a, a + n), Min = *min_element(a, a + n);
    for (int i = 0; i < n; i++)
    {
        a2[i] = ((a[i] - Min) / (Max - Min)) * (1 - 0);
        sum += a[i];
    }
    cout << "\n1.Normalization by Max-min \n";
    for (int i = 0; i < n; i++)
    {
        cout << a2[i] << " ";
    }
    float mean = sum / n;
    float xi = 0;
    for (int i = 0; i < n; i++)
    {
        xi += (a[i] - mean) * (a[i] - mean);
    }
    float sd = xi / n;
    sd = pow(sd, 1 / 2);
    cout << "\n2.Normalization by z-score \n";
    for (int i = 0; i < n; i++)
    {
        if (a[i] - mean > 0)
        {
            a2[i] = (a[i] - mean) / sd;
        }
        else
            a2[i] = (mean - a[i]) / sd;
        cout << a2[i] << " ";
    }

    int j = 0;
    while (Max != 0)
    {
        Max = Max / 10;
        j++;
    }
    cout << "\n3.Normalization by decimal scaling \n";
    for (int i = 0; i < n; i++)
    {
        a2[i] = a[i] / pow(10, j);
        cout << a2[i] << " ";
    }
}