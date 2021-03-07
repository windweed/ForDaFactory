/**
 * @file 链表
 * 21合并两个有序链表，83删除排序链表中的重复元素，142环形链表II，160相交链表
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
     * @brief leetcode 142 linked-list-cycle-ii 环形链表II mideum
     *        给定一个链表，返回链表入环的第一个节点。无环返回null。不能修改链表。
     * @note 为了表示给定链表的中的环，我们使用整数pos来表示链表连接到链表中的位置(从0开始)
     *       如果pos是-1，则在该链表中没有环。注意，pos仅仅用于标识环的情况，不会传入函数。
    */
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        do
        {
            if (!fast || !fast->next) {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        // 如果有环路，查找环路节点
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
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



