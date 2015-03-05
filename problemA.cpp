#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace std;
double f(double t){
    return cos(PI*t*t/2);
}
// Simpson's numerical integration routine. This function returns an
// approximation of the integral of f over the interval [a,b] when
//  using n subintervals in the approximation process.
double simpson(double a, double b, int n)
{
  double sum = 0.0, delta_x = (b-a)/n;
  int i;

  sum = f(a) + f(b);
  for (i = 1; i < n; i++)
    {
      if (i % 2 == 1)
        sum = sum + 4.0 * f(a + i * delta_x);
      else
        sum = sum + 2.0 * f(a + i * delta_x);
    }
  return delta_x * sum/3.0;
}

int main(){

    double x;
    char y;
begin:
    cout.precision(8);
    cout << "Input x: ";
    cin >> x;
    cout << "Intervals C(x)"<<endl;
    for(int i=1; i<=5; i++){
        cout << 10*i << "    " << simpson(0, x, 10*i) <<endl;
    }
    cout<<"Input another x value (y/n)?";
    cin >> y;
    if(y=='y')
        goto begin;
    return 0;

}
