package solution;

public class MergeSortedLists {
	public class ListNode {
	    int val;
	    ListNode next;
	    ListNode(int x) { val = x; }
	}
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode result = null;  //变量在申请之后一定要初始化，否则会报编译错误
        
        //下面是三种特殊的情况，当其中有一个链表为空时，直接返回不为空的一个，如果两个链表全部为空，则返回空
        if(l1 == null && l2 != null){
            result = l2;
            return result;
        }
        
        if(l2 == null && l1 != null){
            result = l1; 
            return result;
        }
        
        if(l1 == null && l2 == null){
            result = null;
            return result;
        }
        
        result = new ListNode(0);   //创建新的节点
        ListNode current = result;   //创建一个当前节点，result的指针不会发生变化，变化的是current
        //System.out.println(current.val);
        //处理两个链表都不为空的情况
        while(l1 != null && l2 != null){
            if(l1.val > l2.val){
                current.val = l2.val;
                l2 = l2.next;
                if(l2 == null){
                    current.next = l1;
                    break;
                }
                ListNode temp = new ListNode(0);
                current.next = temp; 
                current = current.next;
            }else if(l1.val < l2.val) {
                current.val = l1.val;
                l1 = l1.next;
                if(l1 == null){
                    current.next = l2;
                    break;
                }
                ListNode temp = new ListNode(0);
                current.next = temp; 
                current = current.next;
            }else{  //l1.val == l2.val
                current.val = l1.val;
                
                ListNode temp = new ListNode(0);
                current.next = temp; 
                current = current.next;
                current.val = l2.val;
                
                l1 = l1.next;
                l2 = l2.next;
                if(l1 == null){
                    current.next = l2;
                    break;
                }
               
                if(l2 == null){
                    //System.out.println(l1.val + " " + l1.next.val);
                    //System.out.println("娃娃");
                    current.next = l1;
                    //System.out.println(current.next.val + " " + current.next.next.val);
                    break;
                }
                
                temp = new ListNode(0);
                current.next = temp; 
                current = current.next;
                
            }
        }
        
        return result;
    }
}
