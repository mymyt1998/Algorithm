#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t, n, a[105][105],i,j;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            for (j = 0; j <= i; j++)
                cin >> a[i][j];
        for(i=n-2;i>=0;i--)
            for (j = n - 2; j >= 0; j--)
            {
                a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
            }
        cout << a[0][0]<<endl;
    }
    return 0;
}
