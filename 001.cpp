#include <iostream>
#include <sstream>

using namespace std;

bool read(int * a, int & b)
{
	cout << "Enter the elements: \n";
	string str;
	getline(cin, str);
	istringstream stream(str);
	for (int i = 0; i < b; ++i)
	{
		if (!(stream >> a[i]))
		{
			cout << "An error has occured while reading input data." << endl;
			return false;
		}
	}
	return true;
}

void sort(int *A, int root, int last)
{
	int maxstep, stop = 0;
	while ((root * 2 <= last) && (!stop))
	{
		if (root * 2 == last)
			maxstep = root * 2;
		else if (A[root * 2] > A[root * 2 + 1])
			maxstep = root * 2;
		else
			maxstep = root * 2 + 1;

		if (A[root] < A[maxstep])
		{
			int temp = A[root];
			swap(A[root], A[maxstep]);
			A[maxstep] = temp;
			root = maxstep;
		}
		else
			stop = 1;
	}
}

void heap_sort(int *A, int B)
{
	for (int i = (B / 2) - 1; i >= 0; i--)
		sort(A, i, B);
	for (int i = B - 1; i >= 1; i--)
	{
		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		sort(A, 0, i - 1);
	}
}

int main()
{
	int b;
	string k;
	cout << "Enter the number of elements: \n";
	getline(cin, k);
	istringstream stream(k);
	if (!(stream >> b))
	{
		cout << "An error has occured while reading input data." << endl;
		return -1;
	}
	int * a = new int[b];
	if (read(a, b)) 
	{
		cout << "Result: \n";
		heap_sort(a, b);;
		for (int i = 0; i < b; ++i) 
		{
			cout << a[i] << " ";
		}
		delete[] a;
		return 0;
	}
}
