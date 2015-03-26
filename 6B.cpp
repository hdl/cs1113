#include <iostream>
#include <algorithm>


using namespace std;
double f(int n)
{
    if(n<1){
        cout << "invaid input, exit"<<endl;
        exit(0);
    }
    if(n==1)
        return 1;
    else
        return f(n-1) + (double)1/n/n;
}


int main(){

    int n;
    char ans;
    while(1){
        cout << "Enter the number n: ";
        cin >> n;
        cout << "The value of the series for n == "<< n << " is : "<< f(n);
        cout << endl;
        cout << "Would you like to continue? (Enter 'Y' or 'N'): ";
        cin >> ans;
        if(ans=='N')
            return 0;
    }

}
