struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return head;
        if(head -> next == nullptr) return head;

        ListNode* first_even = head -> next;
        ListNode* prev_ev = nullptr;
        ListNode* prev_od = nullptr;

        ListNode* temp = head;
        int pos = 1;

        while(temp != nullptr){
            if(pos % 2 != 0){
                if(prev_od != nullptr) 
                    prev_od -> next = temp;
            
                prev_od = temp;
            }else{
                if(prev_ev != nullptr) 
                    prev_ev -> next = temp;
            
                prev_ev = temp;
            }

            pos++;
            temp = temp -> next;
        }
        prev_ev -> next = nullptr;
        prev_od -> next = first_even;

        return head;
    }
};