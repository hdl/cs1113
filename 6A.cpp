#include <iostream>
#include <algorithm>


using namespace std;
int handshake(int i)
{
    if(i<1){
        cout << "invaid input, exit"<<endl;
        exit(0);
    }
    if(i==1)
        return 0;
    if(i==2)
        return 2;
    else
        return handshake(i-1) + (i-1)*2;
}


int main(){

    int people;
    char ans;
    while(1){
        cout << "Enter the number of people who will be shaking hands: ";
        cin >> people;
        cout << "The number of handshakes that will occur is: "<<handshake(people)<<endl;
        cout << endl;
        cout << "Would you like to continue? (Enter 'Y' or 'N'): ";
        cin >> ans;
        if(ans=='N')
            return 0;
    }

}
