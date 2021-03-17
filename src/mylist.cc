/**
 * @file 链表
 * 21合并两个有序链表，83删除排序链表中的重复元素，141环形链表，142环形链表II，160相交链表
*/
#include "listnode.hh"
#include <list>
#include <forward_list>

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
     * @brief leetcode 141 linked-list-cycle 环形链表 easy
     *        给定一个链表，判断链表中是否有环。
     * @note Floyd判圈法：快慢指针。
    */
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false;
        }

        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
    
    /**
     * @brief leetcode 142 linked-list-cycle-ii 环形链表II mideum
     *        给定一个链表，返回链表入环的第一个节点。无环返回null。不能修改链表。
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



