#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

cArray::cArray(int size)
{
	n = size;
}

void cArray::taoMangNgauNhien()
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		arr.push_back(rand() % 100);
	}
}

void cArray::Xuat()
{
	for (auto x : arr)
	{
		cout << x << " ";
	}
}

int cArray::demSoLanXuatHien(int x)
{
	int count = 0;
	for (auto num : arr)
	{
		if (num == x)
			count++;
	}
	return count;
}

bool cArray::kiemTraTangDan()
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
			return false;
	}
	return true;
}

int cArray::timSoLeNhoNhat()
{
	int min = 101;
	for (auto num : arr)
	{
		if (num % 2 != 0 && num < min)
			min = num;
	}
	return min;
}

bool isPrime(int num) 
{
	if (num <= 1) return false;
	for (int i = 2; i*i <= num; i++) 
	{
		if (num % i == 0) return false;
	}
	return true;
}
int cArray::timSoNguyenToLonNhat()
{
	int  maxPrime = -1;
	for (auto num : arr)
	{
		if (isPrime(num) && num > maxPrime)
			maxPrime = num;
	}
	return maxPrime;
}
// Bubble Sort
void cArray::sapXepTangDan()
{	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void cArray::sapXepGiamDan()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}
