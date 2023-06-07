#include <bits/stdc++.h>
using namespace std;

const int nak = 1e5 + 15;
const int mak = 5e5 + 15;
const int inf = 1e9;

int liczba_aut, max_na_podlodze, seq_len;
int seq[mak];

//towrzenie kopca 
#define parrent(v)  ((v) / 2)
#define left(v)     (2 * (v))
#define right(v)    (2 * (v) + 1)

int heap[nak];
int heap_pos[nak];
int heap_size;

struct node
{
    struct node *next;
    int t;
};
struct node *head[nak];
node nodes[mak];

int  key(int v);
void up_heap(int v);
void down_heap(int v);
void heap_delete_max();
void heap_insert(int v);
void heap_increase_key(int v);
//koniec tworzenia kopca

//tworzenie listy (XD)
void build_list();
//koniec tworzenia listy

void wczytanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> liczba_aut >> max_na_podlodze >> seq_len;
    for(int i = 0; i < seq_len; i++)
    {
        cin >> seq[i];
        seq[i]--;
    }
}

int liczenie()
{
    int ans = 0;
    build_list();
    heap_size = 0;
    
    for(int i = 0; i < seq_len; i++)
    {
        int c = seq[i];
        if(!heap_pos[c])
        {
            if(heap_size == max_na_podlodze) heap_delete_max();

            heap_insert(c);
            ans++;
        }

        head[c] = head[c] -> next;
        heap_increase_key(c);
    }

    return ans;
}

int main()
{
	wczytanie();
	cout << liczenie() << "\n";
}

void build_list()
{
    struct node *n = nodes;
    for(int t = seq_len - 1; t >= 0; t--)
    {
        int c = seq[t];
        n -> t = t;
        n -> next = head[c];
        head[c] = n;
        n++;
    }
}

//rozpisane funkcje dla kopca binarnego
int key(int v)
{
    return head[v] ? head[v] -> t : seq_len;
}
void up_heap(int v)
{
    int c = heap[v];
    while(v > 1 && key(c) > key(heap[parrent(v)]))
    {
        heap[v] = heap[parrent(v)];
        heap_pos[heap[v]] = v;
        v = parrent(v);
    }

    heap[v] = c;
    heap_pos[c] = v;
}
void down_heap(int v)
{
    int c = heap[v];
    while(left(v) <= heap_size)
    {
        int w = left(v);
        if(right(v) <= heap_size && key(heap[w]) < key(heap[right(v)])) w = right(v);

        if(key(heap[w]) > key(c))
        {
            heap[v] = heap[w];
            heap_pos[heap[v]] = v;
            v = w;
        }
        else break;
    }
    heap[v] = c;
    heap_pos[c] = v;
}
void heap_delete_max()
{
    heap_pos[heap[1]] = 0;
    heap[1] = heap[heap_size--];
    down_heap(1);
}
void heap_insert(int v)
{
    heap[++heap_size] = v;
    up_heap(heap_size);
}
void heap_increase_key(int v)
{
    up_heap(heap_pos[v]);
}
//koniec rozpisywanie funkcji dla kopca binarnego