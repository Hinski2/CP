#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
char dokument[1005][1005], stempel[1005][1005];
vector<pair<int,int>> xIndex;

bool sprawdzenie(int x,int y)//położenie wzgędem pierwszego znalezionego x
{
    for (int i=0;i<(int)xIndex.size();i++) 
    {
    int dx=xIndex[i].first,dy=xIndex[i].second;//pozycja iTego "x"

        if((x+dx < 0) || (x+dx >= n) || (y+dy < 0) || (y+dy >= m))
        {
            return true;//zwraca true przez co funkcja wypisuje NIE
        }
        if(dokument[x+dx][y+dy]=='x')
        {
            //jeśli natrafi na x zamienia na . bo nie można postawić puieczątki na pieczątce
            dokument[x+dx][y+dy]='.';
        }
        else
        {
            //jeśli natrafi na . funkcja wypisuje NIE
            return true;
        }
    }
    return false;// jeśli wszystko jest dobrze funkcja wypisuje TAK
}

int main() 
{
    int q;
    scanf("%d", &q);

    while (q--)//wykonuje się q-razy
    {
        bool ok=true; //sprawdza czy wszystko się zgadza i można wypisać "TAK"
        pair<int,int> pierwszy = make_pair(-1, -1);

        xIndex.clear();      //czyści cały vector
        //skanuje wymiary dokumentu i pieczątki 
	    scanf("%d %d %d %d", &n, &m, &a, &b);

	    for(int i=0;i<n;i++)
        {
	        scanf("%s", dokument[i]);//wczytuje całą linijkę dokumentu
        }

    	for(int i=0;i<a;i++) 
        {
	        scanf("%s", stempel[i]);//wczytuje całą linijke pieczątki
            for(int j=0;j<b;j++) //przechodzi po każdyk chraktezrze w linijce
            {
                //jeśli w linijce i charakter nr j == x oraz pos nie jest zapisany
                if((stempel[i][j]=='x') && (pierwszy==make_pair(-1, -1)))
                {
                    pierwszy=make_pair(i, j); //zapisz pozycje pierwszego x
                }
                //jeśli w linijce i charakter nr j == x oraz pos jest zapisany
                if(stempel[i][j]=='x')
                {
                    xIndex.push_back(make_pair(i, j)); //zapisuje pozycje x
                }
            }
        }

    	for(int i=0;i<n && ok;i++)//wykonuje się jeśli ok==true
        {
	        for(int j=0;j<m && ok;j++)
            {
    		    if(dokument[i][j] == 'x')//jeśli linijka nr. i o nr. j == x
                {
        		    if(sprawdzenie(i-pierwszy.first, j-pierwszy.second)) //jeśli funkcja mark==true
                    {
		            	printf("NIE\n");
                        ok=false;
        		    }
                }
            }
        }
        if(ok)//końcowe wypisanie TAK jeśli ok==true
        {
            printf("TAK\n");
        }
    }
    return 0;
}
