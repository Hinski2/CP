#include <bits/stdc++.h>
using namespace std;

long long tree[1 << 21];//2097152
long long lazy[1 << 21];//2097152
int M = 1 << 20; //2097152

void zastosuj(int i, long long sum) //zlicza sume z przedziału 
{
    tree[i] += sum;
    if(i < M) lazy[i] += sum;
}

void push(int x) 
{
    for(int h = 20; h > 0; h--)
    {
        int i = x >> h;//i=x/2^h
        if(lazy[i]) //jeśli jest większy od 0
        {
            zastosuj(i * 2, lazy[i]);
            zastosuj(i * 2 + 1, lazy[i]);
            lazy[i] = 0;
        }
    }
}

void build(int x) //aktualizuje dzieci 
{
    x /= 2;//schodzi do poziomu dzieci 
    while(x)//wykonuje się dopuki x>0
    {
        tree[x] = max(tree[x * 2], tree[x * 2 + 1]);//nadpisuje zmiany w drzewie w dół 
        x /= 2;
    }
}

void add(int l, int r, int value) 
{
    int _l = l += M, _r = r += M;
    push(_l);
    push(_r);
    
    zastosuj(l, value);
    if(l != r) zastosuj(r, value);
    while(l / 2 != r / 2) 
    {
        if(l % 2 == 0) zastosuj(l + 1, value);
        if(r % 2 == 1) zastosuj(r - 1, value);
        l /= 2;
        r /= 2;
    }
    
    build(_l);//aktualizuje wartości dzieci 
    build(_r);//aktualizuje wartości dzieci 
    
}

long long query()//sprawdza max z całego przedziału
{ 
    return tree[1];//zwraca ten max
}

// KONIEC DRZEWA

int ileDni, ileFilmu;//ilość dni oraz ilośc ocen filmów
int iFilm[1000005];//i-ty film
int iOcena[1000005];//i-ta ocena

int r[1000005];//maksymalna prawa wartośc i-tego filmu bez powturzenia
int l[1000005];//maksymalna lewa wartość i-tefo filmu bez powturzenia

int main() 
{
    //skanuje ilość dni oraz ilość ocen
    scanf("%d %d", &ileDni, &ileFilmu);
    //skanuje i-ty film
    for(int i = 0; i < ileDni; i++)
        scanf("%d", &iFilm[i]);
    //skanuje i-tą ocene
    for(int i = 1; i <= ileFilmu; i++)
        scanf("%d", &iOcena[i]);

    //sprawdza skrajne wartości wystąpienia tej samej liczby i dla każdego l przypisuje odpowiednie r
    for(int i = ileDni - 1; i >= 0; i--) 
    {
        //jeśli nr.filmu już wystąpił w ciągu wczytuje jeszcze raz ostatni przedział dotyczący tego filmu
        if(l[iFilm[i]] != 0) add(l[iFilm[i]], r[l[iFilm[i]]] - 1, -iOcena[iFilm[i]]);
        
        //wczytuje prawą pozycje
        r[i] = (l[iFilm[i]] == 0 ? ileDni : l[iFilm[i]]);
        //wczytuje lewą pozycje
        l[iFilm[i]] = i;
        
        add(i, r[i] - 1, iOcena[iFilm[i]]);//tworzy przedział od i do najbliższej na prawo takiej samej liczby
    }
    
    long long ans = query();//wczytuje maksymalną wartość z przedziału
    
    //szuka największej wartości w drzewie
    for(int i = 0; i < ileDni; i++) 
    {
        add(i, r[i] - 1, -iOcena[iFilm[i]]);
        if(r[i] != ileDni) add(r[i], r[r[i]] - 1, iOcena[iFilm[i]]);
        ans = max(ans, query());//szuka największej wartości 
    }
    printf("%lld\n", ans);//wypisuje odpowiedz
    
}
