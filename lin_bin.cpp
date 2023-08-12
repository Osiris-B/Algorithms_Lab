#include <bits/stdc++.h>
using namespace std;

void Linear_Search(vector<int> &arr, int target)
{
  clock_t start, end;
  start = clock();
  int flag = 0, i;
  for (i = 0; i < arr.size(); i++)
  {
    if (arr[i] == target)
    {
      flag = 1;
      break;
    }
  }
  end = clock();

  if (flag)
    cout << "Required element was found at position " << i + 1 << ".\n";
  else
    cout << "Requiredd element was not found in the given array.\n";

  cout << "Time taken is " << (double)(end - start) / CLOCKS_PER_SEC << " seconds.\n";
}

void Binary_Search(vector<int> &arr, int target)
{
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int mid = 0;
  int flag = 0;
  clock_t start, end;

  start = clock();
  while (low <= high)
  {
    mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
      flag = 1;
      break;
    }
    else if (target > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  end = clock();
  if(flag) cout<<"The required element was found at position "<<mid+1<<".\n";
  else cout<<"The required element was not found in the given array.\n";

  cout<<"Time taken is "<<(double)(end - start)/CLOCKS_PER_SEC<<" seconds.\n";
}

int main(){
  int n, key;
  int choice;
  cout<<"Enter the number of elements: ";
  cin>>n;

  vector<int> arr(n);

  cout<<"Enter elements of array:\n";
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  sort(arr.begin(), arr.end());

  cout<<"Enter element to be searched: ";
  cin>>key;
  while(choice){
    cout<<"Enter 2 for Linear Search , 3 for Binary Search or 0 to Exit.\n";
    cin>>choice;
    switch(choice){
      case 0: break;
      case 2:{
        Linear_Search(arr, key);
        break;
      }
      case 3:{
        Binary_Search(arr, key);
        break;
      }
      default:{
        cout<<"Incorrect option. Enter 1 to Continue or 0 to Exit.\n";
        cin>>choice;
        if(!choice) break;
        else continue;
      }
    }
  }
  return 0;
}