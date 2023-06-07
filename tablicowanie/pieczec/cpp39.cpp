#include <bits/stdc++.h>                                                        
using namespace std;                                                            
                                                                                
int q;                                                                          
// int xVec,yVec;                                                                  
// int xMax,xMin,yMax,yMin;                                                        
bool dokument[1005][1005];                                                      
vector<pair<int,int>>stempel; //okrojona wersja pieczeci                        
vector<pair<int,int>>pieczec;                                                   
char pierwszy;                                                                  
                                                                                
void builDocument(int n,int m)                                                  
{                                                                               
    for(int x=0;x<n;x++)                                                        
    {                                                                           
    scanf("%c",&pierwszy);                                                      
        for(int y=0;y<m;y++)                                                    
        {                                                                       
            //skanowanie znaku                                                  
            char znak;                                                          
            scanf("%c",&znak);                                                  
            //przypoisywanie znaku                                              
            if(znak=='x')dokument[x][y]=true;  //true jest tusz / jest "x"      
            else dokument[x][y]=false;         //false nie ma tuszu / jest "."  
        }                                                                       
    }                                                                           
}                                                                               
void buildPieczec(int a,int b)                                                  
{                                                                               
    for(int x=0;x<a;x++)                                                        
    {                                                                           
    scanf("%c",&pierwszy);                                                      
        for(int y=0;y<b;y++)                                                    
        {                                                                       
            //skanowanie znaku                                                  
            char znakk;                                                         
            scanf("%c",&znakk);         //wczytuje znak                         
            //przypoisywanie znaku                                              
            if(znakk=='x')              //jeśli to jest x to zapiuje to miejsce w vektorze                                                                      
            {                                                                   
                pieczec.push_back(make_pair(x,y));
            }                                                                   
        }                                                                       
    }                                                                           
}                                                                               
                                                                                
void cut()                                                                      
{                                                                               
    for(int i=0;i<(int)pieczec.size();i++)                                           
    {                                                                           
        stempel.push_back(make_pair(pieczec[i].first-pieczec[0].first,pieczec[i].second-pieczec[0].second));                                                    
    }                                                                           
}                                                                               
int check(int n,int m,int x, int y,int i)                                       
{                                                                               
    if(x+stempel[i].first<0&&x+stempel[i].first>n)return 0;                     

    if(y+stempel[i].second>m)return 0;                                          

    return 1;                                                                   
}                                                                               
                                                                                
string sprawdzenie(int n,int m)                                                 
{                                                                               
    for(int x=0;x<n;x++)                                                        
    {                                                                           
        for(int y=0;y<m;y++)                                                    
        {                                                                       
            if(dokument[x][y]==true)   // jest x                                
            {                                                                   
                for(int i=0;i<(int)stempel.size();i++)                               
                {                                                               
                    if(check(n,m,x,y,i)==0)return "NIE";                                                                                                  
                    if(dokument[x+stempel[i].first][y+stempel[i].second]==true) 
                    {                                                           
                        dokument[x+stempel[i].first][y+stempel[i].second]=false;
                    }                                                           
                    else return "NIE";                                          
                }                                                               
            }                                                                   
            else continue;             // jest .                                
        }                                                                       
    }                                                                           
    return "TAK";                                                               
}                                                                               
                                                                                
int main()                                                                      
{                                                                               
    int n,m,a,b;                                                                
    //skanowanie danych                                                         
    scanf("%d",&q);                                                             
    for(int i=0;i<q;i++)                                                        
    {                                                                           
        //wczytywanie danych                                                    
        scanf("%d %d %d %d",&n,&m,&a,&b);                                       
                                                                                
        //tworzenie dokumentu, pieczęci i stempla                               
        builDocument(n,m);                                                      
        buildPieczec(a,b);                                                      
        cut();                                                                  
                                                                                
        cout<<sprawdzenie(n,m)<<"\n";                                           
                                                                                
        //czyszczenie vectorów                                                  
        stempel.clear();                                                        
        pieczec.clear();                                                        
    }                                                                           
}      