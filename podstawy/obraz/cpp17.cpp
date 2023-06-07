#include <iostream>
using namespace std;

int main()
{
    int w,z,l=0;
    scanf("%d %d\n",&w,&z);
    int t=w*(z+1);
    char *x;
    x = new char [t];
    int h=w*(z+1);
    int hh=(w-1)*z+w-1;
    for(int i=0;i<h;i++)
    {
        x[i] = getchar();
    }
    for(int p=0;p<z;p++)
    {
        for(int j=hh;j>=l;j=j-z-1)
        {
            putchar(x[j]);
        }
        putchar('\n');
        l++;
        hh++;
    }
    return 0;
}
