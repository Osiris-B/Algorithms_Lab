#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &arr)
{
  int n = arr.size();
  clock_t start, end;
  start = clock();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
  end = clock();
  cout << "The sorted array is \n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << "\n";
  }
  cout << "\nTime taken is " << (double)(end - start) / CLOCKS_PER_SEC << " seconds.\n";
}

void InsertionSort(vector<int> &arr)
{
  int n = arr.size();
  clock_t start, end;
  start = clock();
  for (int i = 0; i < n; i++)
  {
    int j = i - 1;
    int temp = arr[i];
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
  end = clock();
  cout << "The sorted array is \n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << "\n";
  }
  cout << "\nTime taken is " << (double)(end - start) / CLOCKS_PER_SEC << " seconds.\n";
}

int main()
{
  int n, choice;
  cout << "Enter the number of elements: ";
  cin >> n;
  vector<int> arr1(n), arr2(n);

  cout << "Using random inputs.\n";
  for (int i = 0; i < n; i++)
  {
    int a = rand() * (INT_MAX);
    arr1[i] = a;
    arr2[i] = a;
  }
  while (choice)
  {
    cout << "Enter 2 for Bubble Sort, 3 for Insertion Sort or 0 to Exit.\n";
    cin >> choice;
    switch (choice)
    {
    case 0:
      break;
    case 2:
    {
      BubbleSort(arr1);
      break;
    }
    case 3:
    {
      InsertionSort(arr2);
      break;
    }
    default:
    {
      cout << "Incorrect option. Enter 1 to Continue or 0 to Exit.\n";
      cin >> choice;
      if (!choice)
        break;
      else
        continue;
    }
    }
  }
  return 0;
}
