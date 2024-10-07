/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* doubleIt(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }
//         if (head->val == 0 && head->next == nullptr) {
//             return new ListNode(0);
//         }

//         ListNode* curr = head;
//         int numOfNodes = 0;
//         while(curr != nullptr){
//             numOfNodes += 1;
//             curr = curr->next;
//         }

//         unsigned long long high = 1;
//         for(int i=1; i<numOfNodes; i++){
//             high = high*10;
//         }

//         unsigned long long num = 0;
//         ListNode* newcurr = head;
//         while(newcurr != nullptr){
//             num = (newcurr->val * high) + num;
//             high = high / 10;
//             newcurr=newcurr->next;
//         }

//         unsigned long long res = num * 2;

//         ListNode* newHead = nullptr;
//         while(res > 0){
//             int digit = res % 10;
//             ListNode* newNode = new ListNode(digit);
//             if(newHead == nullptr){
//                 newHead = newNode;
//             } else {
//                 newNode->next = newHead;
//                 newHead = newNode;
//             }
//             res = res/10;
//         }

//         return newHead;
//     }
// };