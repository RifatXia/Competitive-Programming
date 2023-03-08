#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int num[n];
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    // total number of combinations = 1 * 2 ^ n = 2 ^ n
    int tot = 1 << n;
    
    for(int i = 0; i < tot; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // shifting 1 j spaces to the left
            int x = 1 << j;

            // checking whether the jth bit of the number is zero or not, print if not zero 
            if((x & i) != 0)
                cout << num[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
