#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // fill the map
        unordered_map<int, int> m;
        ListNode* head_cp = head;
        
        while(head_cp) {
            m[head_cp -> val]++;
            head_cp = head_cp -> next;
        }

        ListNode* new_head = nullptr, *itr = nullptr;
        for(int i = -1e5; i <= 1e5; i++) {
            if(!m.count(i)) continue;

            for(int no = 0; no < m[i]; no++) {
                add(new_head, itr, i);
            }
        }

        return new_head;
    }

    void add(ListNode* &head, ListNode* &last, int val) {
        if(head == nullptr) {
            ListNode* n = new ListNode(val);
            head = n;
            last = n;
        } else if(head == last) {
            ListNode* n = new ListNode(val);
            head -> next = n;
            last = n;
        } else {
            ListNode* n = new ListNode(val);
            last -> next = n;
            last = last -> next;
        }
    }
};