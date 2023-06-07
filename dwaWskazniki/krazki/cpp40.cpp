#include <bits/stdc++.h>
using namespace std;

int hight,ile,rurka[300005],disk[300005];
int main()
{
    scanf("%d %d",&hight,&ile);

    for (int i=1;i<=hight;i++)
    {
        scanf("%d",&rurka[i]);
    }

    for (int i=1;i<=ile;i++)
    {
        scanf("%d",&disk[i]);
    }
    //koniec wczytywanie początek liczenia
    for (int i=2;i<=hight;i++)
    {
        rurka[i]=min(rurka[i],rurka[i-1]);
    }

    int dno=hight;
    for(int i=1;i<=ile;i++,dno--)
    {
        while(dno>0 && rurka[dno]<disk[i])dno--;
        if(dno==0)
        {
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n",dno+1);
}