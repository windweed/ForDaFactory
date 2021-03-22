/**
 * @file 链表
 *       21合并两个有序链表，83删除排序链表中的重复元素，92反转链表II，
 *       141环形链表，142环形链表II，160相交链表，206反转一个单链表
*/
#include "listnode.hh"

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
        // 由于一次只走一步，因此l1和l2不可能同时为nullptr
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
     * @brief leetcode 92 reverse-linked-list-ii 反转链表II mideum
     *        给定单链表的头节点head和两个位置left,right（从1开始数），
     *        其中left<=right，反转从left到right的链表节点。返回反转后的链表。
     * @example Input: head=[1,2,3,4,5], left=2,right=4; Output:[1,4,3,2,5]
     * @note 借助206 @c reverseList , 反转指定区间后再拼上去。
    */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummyNode = ListNode(-1);
        dummyNode.next = head;
        ListNode* preNode = &dummyNode;
        // preNode 保存left的前一个节点。
        for (int i = 0; i < left - 1; i++) {
            preNode = preNode->next;
        }
        // 走到right
        ListNode* rightNode = preNode;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }
        // 截取链表
        ListNode* leftNode = preNode->next; // 截取的链表的开头
        ListNode* curr = rightNode->next;   // 截取的链表尾的后面一个节点
        rightNode->next = nullptr;
        preNode->next = nullptr;
        reverseList(leftNode);

        // 接回去
        preNode->next = rightNode; // rightNode现在指向截取的链表的新头
        leftNode->next = curr;     // leftNode现在指向截取的链表的尾
        return dummyNode.next;
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
            if (!fast || !fast->next) { // 到达了结尾，并没有环
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

    /**
     * @brief leetcode 206 reverse-linked-list 反转一个单链表 easy
     * @note 将当前节点的next改为前边的节点，so，需要事先存储前一个节点，修改后为了能
     *       继续往下，所以还需要存储后一个节点。
    */
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode* next = curr->next; // 提前存好下一个，这样修改curr->next后可以继续
            curr->next = prev;           // 修改curr->next，指向前一个
            prev = curr;
            curr = next;
        }
        return prev;
    }
};



