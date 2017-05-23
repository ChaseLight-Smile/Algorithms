package com.uniplore.problemset1;

public class LeetCode2 {
	
	 //Definition for singly-linked list.
	 public class ListNode {
	      int val;
	      ListNode next;
	      ListNode(int x) { val = x; }
	 }

	public class Solution {
	    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	        ListNode result = new ListNode(0);   //返回最后的计算结果
	        if((l1.val + l2.val) >= 10) {
	            result.val = (l1.val+l2.val)%10;
	            if( l1.next != null) {
	                l1.next.val = l1.next.val + 1;
	                System.out.println(l1.next.val);    
	            }else {
	                ListNode temp1 = new ListNode(1);
	                l1.next = temp1;
	            }
	        }else {
	            result.val = (l1.val + l2.val);
	        }
	        
	        ListNode current = result;   //获取到当前头节点
	        
	        while(l1.next != null) {
	            l1 = l1.next ;
	            if(l2.next != null) {
	                l2 = l2.next ;
	            }else {
	                ListNode l2Temp = new ListNode(0);
	                l2.next = l2Temp;
	                l2 = l2.next;
	            }
	            ListNode temp = new ListNode(0);
	            if((l1.val + l2.val) >= 10) {
	                temp.val = (l1.val+l2.val)%10;
	                if( l1.next != null) {
	                    l1.next.val = l1.next.val + 1; 
	                }else {
	                    ListNode temp2 = new ListNode(1);
	                    l1.next = temp2;
	                }
	            }else {
	                temp.val = (l1.val + l2.val);
	            }
	            current.next = temp ;
	            current = current.next ;
	        }
	        
	        while(l2.next != null) {
	            l2 = l2.next ;
	            if(l1.next != null) {
	                l1 = l1.next ;
	            }else {
	                ListNode l1Temp = new ListNode(0);
	                l1.next = l1Temp;
	                l1 = l1.next;
	            }
	            ListNode temp = new ListNode(0);
	            if((l1.val + l2.val) >= 10) {
	                temp.val = (l1.val+l2.val)%10;
	                if( l1.next != null) {
	                    l1.next.val = l1.next.val + 1; 
	                }else {
	                    ListNode temp2 = new ListNode(1);
	                    l1.next = temp2;
	                }
	            }else {
	                temp.val = (l1.val + l2.val);
	            }
	            current.next = temp ;
	            current = current.next ;
	        }
	        
	        return result;
	    }
	}
}
