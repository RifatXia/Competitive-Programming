// Generate the sum of SOD from 1 to n
// Test - https://www.spoj.com/problems/ETF/
// RifatXia 

#include <bits/stdc++.h>
using namespace std;

const int lim = 1e6 + 10;
int phi[lim];
 
void eulers_totient() 
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i < lim; i++)
        phi[i] = i - 1;
 
    for (int i = 2; i < lim; i++)
        for (int j = 2 * i; j < lim; j += i)
              phi[j] -= phi[i];
}
 
int main(void)
{
    eulers_totient();
 
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
        cout << phi[n] << en;
    }
 
    return 0;
} 
