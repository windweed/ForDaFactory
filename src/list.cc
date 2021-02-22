/**
 * @file 链表
 * 21合并两个有序链表
*/
#include "listnode.h"
#include <list>
#include <forward_list>

using namespace std;

class ListSolution {
public:
    /**
     * @brief leetcode 12 merge-two-sorted-lists 合并有序链表 easy
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode prev_head = ListNode(-1);
        ListNode* prev = &prev_head;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 ? l1 : l2;
        return prev_head.next;
    }


    /**
     * @brief 判断链表是否有环
    */
    bool hasLoop();

};



