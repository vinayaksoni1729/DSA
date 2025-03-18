#include <iostream>
using namespace std;

int prime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    else
    {
        int mid = n / 2;
        for (int i = 2; i < mid; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
int main()
{
    int n;
    string ans;
    cout << "Enter a number to check-";
    cin >> n;
    bool isPrime = prime(n);
    if (!isPrime && n > 1)
    {
        ans = "Composite";
    }
    else if (isPrime)
    {
        ans = "Prime";
    }
    else
    {
        ans = "None";
    }
    cout << "Entered number " << n << " is " << ans << endl;
}