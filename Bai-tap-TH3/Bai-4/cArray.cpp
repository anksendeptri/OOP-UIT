#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Constructor
cArray::cArray(int size)
{
	n = size;
}

//phuong thuc tao mang ngau nhien
//cach thuc: nhap so luong phan tu, sau do su dung ham rand() de tao cac so ngau nhien trong khoang 0-99 va them vao vector arr
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

//phuong thuc dem so lan xuat hien cua mot so trong mang
//cach thuc: nhap so can dem, sau do duyet qua vector arr va dem so lan xuat hien cua so do
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

//phuong thuc kiem tra mang co tang dan hay khong
//cach thuc: duyet qua vector arr va so sanh moi phan tu voi phan tu truoc do, neu co phan tu nao nho hon phan tu truoc do thi mang khong tang dan
bool cArray::kiemTraTangDan()
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
			return false;
	}
	return true;
}

//phuong thuc tim so le nho nhat trong mang
//cach thuc: duyet qua vector arr va tim so le nho nhat, khoi tao min = 100 (lon hon gia tri lon nhat trong mang) va cap nhat min khi tim thay so le nho hon
int cArray::timSoLeNhoNhat()
{
	int min = 100;
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

//phuong thuc tim so nguyen to lon nhat trong mang
//cach thuc: duyet qua vector arr va tim so nguyen to lon nhat, khoi tao maxPrime = -1 (nho hon gia tri nho nhat trong mang) va cap nhat maxPrime khi tim thay so nguyen to lon hon
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

//phuong thuc sap xep mang tang dan va giam dan
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
