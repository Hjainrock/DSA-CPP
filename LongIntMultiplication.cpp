// Long Integer Multiplication using Divide and Conquer
#include <iostream>
using namespace std;
#include<math.h>

int countDigit(long long n)
{
if (n/10 == 0)
return 1;
return 1 + countDigit(n / 10);
}

long long large_integer_mult(long long a, long long b)
{
long long w, x, y, z;
int m, n;
int threshold = 2;
int d1 = countDigit(a);
int d2 = countDigit(b);
if(d1>=d2)
n=d1;
else
n=d2;
if(a == 0 || b == 0)
return 0;
else if(n <= threshold)
return (a*b);
else
{
m = long(n/2); //m is mid
x = a / long(pow(10,m));
y = a % long(pow(10,m));
w = b / long(pow(10,m));
z = b % long(pow(10,m));
return large_integer_mult(x,w)*pow(10,2*m) + (large_integer_mult(x, z) + large_integer_mult(w, y))*pow(10,m) + large_integer_mult(y, z);
}
}

int main() {
long long n1, n2;
cout << "Enter two Large integers\n";
cin>>n1>>n2;
long long result = large_integer_mult(n1 , n2);
cout<<"Multiplication is: "<<result;

return 0;
}
