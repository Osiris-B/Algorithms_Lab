#include <iostream>
#include<time.h>
using namespace std;

int GCD_MiddleSchool(int m, int n)
{
  int gcd = 1;

  for (int i = 1; i <= n; i++)
  {
    if (m % i == 0 && n % i == 0)
    {
      gcd = i;
    }
  }
  return gcd;
}

int Euclid_Division(int m, int n)
{
  while (n != 0)
  {
    int temp = n;
    n = m % n;
    m = temp;
  }
  return m;
}

int Euclid_Subtraction(int m, int n)
{
  while (m != n)
  {
    if (m > n)
    {
      m -= n;
    }
    else
    {
      n -= m;
    }
  }
  return m;
}

int main()
{
  int num1, num2;
  int choice;
  cout << "Enter two numbers to find their GCD: \n";
  cin >> num1 >> num2;
  while (choice)
  {
    cout << "Enter 2 for Middle School, 3 for Euclid's Division, 4 for Euclid's Subtraction or 0 to exit.\n";
    cin >> choice;
    switch(choice){
      case 0: break;
      case 2:{
        clock_t start,end;
        int GCD;
        start = clock();
        GCD = GCD_MiddleSchool(num1, num2);
        end = clock();
        cout<<"GCD is "<<GCD<<endl;
        cout<<"Time taken is "<<(double)(end - start)/CLOCKS_PER_SEC<<" seconds.\n";
        break;
      }
      case 3:{
        clock_t start, end;
        int GCD;
        start = clock();
        GCD = Euclid_Division(num1,num2);
        end = clock();
        cout<<"GCD is "<<GCD<<endl;
        cout<<"Time taken is "<<(double)(end - start)/CLOCKS_PER_SEC<<" seconds.\n";
        break;
      }
      case 4:{
        clock_t start,end;
        int GCD;
        start = clock();
        GCD = Euclid_Subtraction(num1, num2);
        end = clock();
        cout<<"GCD is "<<GCD<<endl;
        cout<<"Time taken is "<<(double)(end - start)/CLOCKS_PER_SEC<<" seconds.\n";
        break;
      }
      default:{
        cout<<"Incorrect option. Enter 1 to continue or 0 to exit.\n";
        cin>>choice;
        if(!choice) break;
        else continue;
      }
      
    }
  }
  return 0;
}
