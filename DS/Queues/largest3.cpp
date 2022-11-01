#include <bits/stdc++.h>
using namespace std;

void populateAux(int aux[], queue<int> queue0, queue<int> queue1,
				queue<int> queue2, int* top)
{
	while (!queue0.empty()) {
		aux[(*top)++] = queue0.front();
		queue0.pop();
	}

	while (!queue1.empty()) {
		aux[(*top)++] = queue1.front();
		queue1.pop();
	}

	while (!queue2.empty()) {
		aux[(*top)++] = queue2.front();
		queue2.pop();
	}
}

int findMaxMultupleOf3(int arr[], int size)
{
	sort(arr, arr + size);

	queue<int> queue0, queue1, queue2;

	int i, sum;
	for (i = 0, sum = 0; i < size; ++i) {
		sum += arr[i];
		if ((arr[i] % 3) == 0)
			queue0.push(arr[i]);
		else if ((arr[i] % 3) == 1)
			queue1.push(arr[i]);
		else
			queue2.push(arr[i]);
	}

	if ((sum % 3) == 1) {
		if (!queue1.empty())
			queue1.pop();

		else {
			if (!queue2.empty())
				queue2.pop();
			else
				return 0;

			if (!queue2.empty())
				queue2.pop();
			else
				return 0;
		}
	}

	else if ((sum % 3) == 2) {
		if (!queue2.empty())
			queue2.pop();

		else {
			if (!queue1.empty())
				queue1.pop();
			else
				return 0;

			if (!queue1.empty())
				queue1.pop();
			else
				return 0;
		}
	}

	int aux[size], top = 0;

	populateAux(aux, queue0, queue1, queue2, &top);

	sort(aux, aux + top, greater<int>());

	for (int i = 0; i < top; ++i)
		cout << aux[i];

	return top;
}
int main()
{

	int arr[] = {8,1,9,1,1,5,6,7,8,3,3,3,4,5,2,2,3,2,3,4,2,5,3,7,3,9,7,8,6,2,2,8,8,9,6,7,4,0,9,9,0,8,6,1,1,3};;
	int size = sizeof(arr) / sizeof(arr[0]);

	if (findMaxMultupleOf3(arr, size) == 0)
		cout << "Not Possible";
    
	return 0;
}
