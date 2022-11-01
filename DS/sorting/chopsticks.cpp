#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, d;
	cout << "Enter number of elements and D value" << endl;
	cin >> n >> d;
	int a[n];
	cout << "Enter the elements now" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int c = 0;

	for (int i = 0; i < n; i++)
	{
		if (i + 1 < n)
		{
			if (a[i + 1] - a[i] <= d)
			{
				c++;
				i++;
			}
		}
		else
			break;
	}
	cout << "Number of pairs with " << d << " difference is " << c << endl;

	return 0;
}
