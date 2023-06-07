#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double r;
int main()
{
    cout.precision(3);
    cin>>r;
    cout<<fixed;
    cout<<M_PI*pow(r,2)<<endl;
    cout<<2*M_PI*r;
    return 0;
}
