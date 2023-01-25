//Codeforces Interactive Problem
//Problem link - https://codeforces.com/gym/101021/problem/1
//RifatXia

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // RifatXia();

    int l = 1, r = 1e6, step = 25, ans = -1;
    string s;
    while(l <= r && step--)
    {
        int mid = l + (r - l)/2;
        cout << mid << endl;
        cin >> s;
        if(s == ">=")
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << "! " << ans << endl;

    return 0;
}
