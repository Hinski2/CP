#include <iostream>
#include <string>

using namespace std;
string sa = "aeiouy";
string n ;

int main()
{
    cin>>n;
    size_t x = sa.find(n);
    if (x != string::npos) cout<<"tak";
    else cout<<"nie";

    return 0;
}
