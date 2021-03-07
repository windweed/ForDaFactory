/**
 * @file 链表
 * 21合并两个有序链表，83删除排序链表中的重复元素，160相交链表
*/
#include "listnode.h"

using namespace std;

class ListSolution {
public:
    /**
     * @brief leetcode 21 merge-two-sorted-lists 合并有序链表 easy
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

    /**
     * @brief leetcode 83 remove-duplicates-from-sorted-list
     *      删除排序链表中的重复元素 easy
     *      给定一个排序链表，删除所有重复的元素
     * @example 输入1->1->2 输出 1->2
    */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode* tmp = curr->next;
                curr->next = tmp->next;
                delete tmp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }

    /**
     * @brief leetcode 160 intersection-of-two-linked-lists 相交链表 easy
     *      找到两个单链表相交的起始节点。
    */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *pa = headA, *pb = headB;
        if (!pa || !pb) {
            return nullptr;
        }

        while (pa != pb) { // 注意。这是确认有交点才这么写。不然会死循环。不够严谨
            pa = (pa) ? pa->next : headB;
            pb = (pb) ? pb->next : headA;
        }
        return pa;
    }

};



