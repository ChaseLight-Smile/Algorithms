package com.uniplore.solution;

public class LeetCode148 {
	 public class ListNode {
	      int val;
	      ListNode next;
	      ListNode(int x) { val = x; }
	 }
	public ListNode sortList1(ListNode head) {
        if(head == null) {
            return null;
        }else{
            //1.首先我们应该对数组进行计数
            ListNode current = head; 
            int length = 0 ;
            while(current != null){
                length++;
                current = current.next;
            }
            
            //2. 接着我我们应该从中点将链表分开
            ListNode head1 = new ListNode(0);
            ListNode head2 = new ListNode(0);
            int mid = (length)/2;
            
            int head1Length = 0 ;
            head1 = head;
            current = head1;   //2.过程结束
            
            //3. 将linked list拆分成两个linked list
            while(head1Length < mid-1  && current != null) {
                head1Length++;
                current = current.next;
            }
            head2 = current.next;
            current.next = null;
            if(length == 1) {
                return head;
            }else{
                //递归的调用本段代码，直到全部拆分成长度为1的链表
                ListNode list1 = sortList1(head1);
                ListNode list2 = sortList1(head2);
                head = merge1(list1,list2);
                return head;
            }
        }
    }
    //合并两个list的代码，该段代码的时间复杂度为O(n)，采用原地合并策略
    private ListNode merge1(ListNode list1, ListNode list2){
        ListNode head = new ListNode(0);
        ListNode current = head;
        while(true) {
            if(list1 == null) {
                if(list2 != null){
                    current.val = list2.val;
                    current.next = list2.next;
                    list1 = null;
                    list2 = null;
                    return head;
                }
                
            }else if(list2 == null){
                if(list1 != null){
                    current.val = list1.val; 
                    current.next = list1.next;
                    list1 = null;
                    list2 = null;
                    return head;
                }
                
            }else if(list1 == null && list2 == null){
              /*  current = null;
                list1 = null;
                list2 = null;
                return head;*/
            }else if(list1.val > list2.val){
                current.val = list2.val;
                list2 = list2.next;
                ListNode temp = new ListNode(Integer.MIN_VALUE);
                current.next = temp;
                current = current.next;
            }else if(list1.val < list2.val){
                current.val = list1.val;
                list1 = list1.next;
                ListNode temp = new ListNode(Integer.MIN_VALUE);
                current.next = temp;
                current = current.next;
            }else if(list1.val == list2.val){
                //说明list1和list2此时存在相同的值，都要放到链表当中
                current.val = list1.val;
                list1 = list1.next;
                
                ListNode temp1 = new ListNode(list2.val);
                current.next = temp1;
                list2 = list2.next;
                current = current.next;
                
                ListNode temp2 = new ListNode(Integer.MIN_VALUE);
                current.next = temp2;
                current = current.next;
                
            }
        }
    }
    
    
    public ListNode sortList2(ListNode head) {
        if(head == null) {
            return null;
        }else{
            //1.首先我们应该对数组进行计数
            ListNode current = head; 
            int length = 0 ;
            while(current != null){
                length++;
                current = current.next;
            }
            
            //2. 接着我我们应该从中点将链表分开
            ListNode head1 = new ListNode(0);
            int mid = (length)/2;
            
            int head1Length = 0 ;
            head1 = head;
            current = head1;   //2.过程结束
            
            //3. 将linked list拆分成两个linked list
            while(head1Length < mid-1  && current != null) {
                head1Length++;
                current = current.next;
            }
            head = current.next;  
            current.next = null;   //head1最后一个元素的next域赋值为空
            
            current = null;
            if(length == 1) {
                return head1;
            }else{
                //递归的调用本段代码，直到全部拆分成长度为1的链表
                head1 = sortList2(head1);
                head =  sortList2(head);
                head = merge2(head1,head);
                return head;
            }
        }
    }
    //合并两个list的代码，该段代码的时间复杂度为O(n)，采用原地合并策略
    private ListNode merge2(ListNode list1, ListNode list2){
        ListNode head = new ListNode(0);
        ListNode current = head;
        while(true) {
            if(list1 == null) {
                if(list2 != null){
                    current.val = list2.val;
                    current.next = list2.next;
                    list1 = null;
                    list2 = null;
                    current = null;
                    return head;
                }
                
            }else if(list2 == null){
                if(list1 != null){
                    current.val = list1.val; 
                    current.next = list1.next;
                    list1 = null;
                    list2 = null;
                    current = null;
                    return head;
                }
                
            }else if(list1 == null && list2 == null){
               /* current = null;
                list1 = null;
                list2 = null;
                current = null;
                return head;*/
            }else if(list1.val > list2.val){
                current.val = list2.val;
                list2 = list2.next;
                ListNode temp = new ListNode(Integer.MIN_VALUE);
                current.next = temp;
                current = current.next;
            }else if(list1.val < list2.val){
                current.val = list1.val;
                list1 = list1.next;
                ListNode temp = new ListNode(Integer.MIN_VALUE);
                current.next = temp;
                current = current.next;
            }else if(list1.val == list2.val){
                //说明list1和list2此时存在相同的值，都要放到链表当中
                current.val = list1.val;
                list1 = list1.next;
                
                ListNode temp1 = new ListNode(list2.val);
                current.next = temp1;
                list2 = list2.next;
                current = current.next;
                
                ListNode temp2 = new ListNode(Integer.MIN_VALUE);
                current.next = temp2;
                current = current.next;
                
            }
        }
    }
}
