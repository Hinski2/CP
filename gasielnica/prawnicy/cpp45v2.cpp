#include <bits/stdc++.h>
using namespace std;

int ilePrawnikow,ilePotrzeba;
pair <int, int> przedzial[1000005];
struct prawnicy
{
    int pos;
    int id;
    bool state;
};

vector<prawnicy>points;

const int START=0;
const int FINISH=1;

void sprawdzenie()
{
    set<int>delate;
    set<int>jest;
    
    int lAnswer=0,rAnswer=-1,prawo=0;
    for(int lewo=0;lewo<points.size();lewo++)
    {
        if(points[lewo].state==START&&delate.count(points[lewo].id)==0)
        {
            jest.insert(points[lewo].id);
        }
        while(prawo<points.size()&&jest.size()>=ilePotrzeba)
        {
            if(rAnswer-lAnswer<points[prawo].pos-points[lewo].pos)
            {
                lAnswer=points[lewo].pos;
                rAnswer=points[prawo].pos;
            }
            if(points[prawo].state==FINISH)
            {
                delate.insert(points[prawo].id);
                if(jest.count(points[prawo].id))
                {
                    jest.erase(points[prawo].id);
                }
            }
            prawo++;
        }
    }
    //wypisywanie wyników 
    cout<<rAnswer-lAnswer<<endl;// wypisanie piearwszego wiersza równego najdłuższemu spotkaniu
    for(int i=0;i<ilePrawnikow;i++)//przechodzi po każdzym prawniku
    {
        //jeśli lewy i przwy przedział się zgadza wypisuje id każdego z ilePrawników  
        if(przedzial[i].first<=lAnswer&&rAnswer<=przedzial[i].second&&ilePotrzeba-->0)
        {
            cout<<i+1<<" ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);//przyśpiesza wczytywanie i wypisywanie
    cin>>ilePrawnikow>>ilePotrzeba;
    for(int i=0;i<ilePrawnikow;i++)
    {
        cin>>przedzial[i].first>>przedzial[i].second;
        points.push_back({przedzial[i].first,i,START});
        points.push_back({przedzial[i].second,i,FINISH});
    }

    sort(points.begin(), points.end(), [](const prawnicy &l, const prawnicy &r) 
    {
        return l.pos < r.pos;
    });

    sprawdzenie();
}