#include<iostream> 
using namespace std;  
int binary_search(int a[], int &length, int num);
int main()
{
	int n,i,j,length=0,temp;
	cin >> n;
	int *a = new int[n],
		*b = new int[n],
		*c = new int[n];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		while (a[i] < 0 || a[i]>10000)
			cin >> a[i];
	}
	b[0] = 1;
	c[0] = -1;
	for (i = 1; i < n; i++)
	{
		temp = binary_search(c, length, a[i]);
		if (temp == -1)
		{ 
			c[length] = a[i]; 
			b[i] = length+1; 
		}
		else
		{
			c[temp] = a[i];
			b[i] = temp + 1;
		}
		
	} 
	cout << b[n-1] << endl;
	Sleep(9000);
	return 0;
}

int binary_search(int a[], int &length, int num)
{
	if (a[length] < num)
	{
	    ++length;
	    return -1;
    }

	int high, low, mid;
	high = length;
	low = 0;
	
	while (low < high)
	{
		mid = (high + low) / 2;
		if ((low + 1 == high) && ( a[low]<num && a[high]>num))
		{
			return high;
		}
		else if (num < a[mid])
		{
			high = mid;
		}
		else if (num > a[mid])
			low = mid;

	}
	return -2;
}
