package solution;

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
    
    /*  在Leetcode中没有通过测试的数据
     [1585,766,-448,1449,-821,-153,1442,292,851,1419,949,534,1245,-475,292,689,-147,614,93,906,1435,506,665,301,1368,1930,-943,287,-363,889,1908,-867,-689,-332,-783,550,1070,882,1584,1231,-685,1117,989,1012,720,384,-455,-828,280,-197,34,-199,1514,1672,1041,1413,304,380,-703,397,919,869,1323,-38,-444,-102,1500,-890,-58,1322,1219,1979,1048,1038,1247,775,1273,446,-753,249,1191,-79,680,-458,1276,1055,759,1615,1607,-91,-340,-248,589,1275,596,429,1653,1155,567,1320,734,-993,-572,-807,-825,866,155,1368,1370,-998,-408,1643,23,-538,-560,1055,1218,-90,1313,-598,-61,-109,-324,984,-196,1365,1914,-79,-798,1801,1045,1474,1666,-745,735,446,335,-605,738,-938,1710,1835,-424,1949,644,-823,356,1810,228,1887,1457,-291,99,840,72,1051,288,1609,-162,1719,816,329,-225,234,340,-469,-401,-266,406,-317,-821,1585,1130,1466,1992,654,486,-672,228,-733,1790,-678,703,-249,1732,-505,1491,488,472,-802,217,741,1938,1346,559,555,-676,-938,390,-481,439,1168,1405,226,996,-678,15,1044,570,881,1891,-190,1728,-545,1934,-440,1858,313,259,892,1683,1060,244,1009,1059,-19,550,579,296,1951,271,278,-737,1626,1327,-849,1357,-714,-944,1722,-305,1965,-309,1260,1913,872,263,-359,-749,1240,-765,336,1057,1193,1044,1849,-90,339,-502,-774,1250,-740,1587,-876,373,249,904,-106,1581,-440,13,1536,1570,88,512,-953,1756,-701,-229,19,1652,663,572,-990,-528,1146,-706,1548,-237,-667,1760,892,1253,1541,1516,-44,621,-928,998,1754,-782,-99,-857,909,141,577,-369,360,1085,-48,-354,1417,1665,-92,-345,1460,1314,1620,567,90,698,1669,1153,540,1072,1090,-501,863,195,700,-388,1577,543,1780,-496,1216,-148,529,1096,834,1757,737,-611,1314,1278,-646,345,-45,1710,1068,-301,-650,186,925,122,1901,117,-302,793,-460,732,1092,39,798,1660,190,1036,1327,-566,1309,392,81,123,31,-204,-952,-863,283,-592,510,-202,377,1330,-306,448,1413,1008,-731,1390,-589,-266,866,657,1358,1324,608,330,-565,-331,1878,-223,1475,-396,67,-64,1769,1206,7,-882,1732,749,285,1236,1651,1188,1207,-883,85,-804,326,1605,1432,1725,751,-938,988,1635,1590,-12,-673,-226,864,1423,-751,152,1585,1847,1146,89,803,-166,-334,535,1571,1828,-481,-967,380,1743,838,885,1261,-489,-494,910,1967,125,265,-709,1005,519,-887,962,-308,1437,733,1062,854,724,1231,-135,-368,173,871,-369,1552,-150,-598,-733,1669,1163,433,1882,238,610,671,269,348,398,-512,210,132,96,796,-179,1459,-951,322,-643,-450,1180,-55,85,1749,407,1885,926,-130,1016,1166,1798,-104,1917,272,1139,-900,1972,1338,1545,692,1859,-229,-352,1323,45,-615,-413,-314,-186,44,1069,-699,1666,1354,1882,711,1480,1016,1864,1864,208,-372,194,618,41,868,1268,1138,147,408,-962,180,733,1323,449,-690,-258,320,566,-767,-565,-591,1359,1492,1750,231,1990,448,666,-323,-338,-292,219,-495,852,-154,1252,-260,214,-944,59,684,1883,-269,1091,889,-42,314,-493,965,491,97,-246,1160,-863,1445,1011,366,1812,821,966,1450,-60,1654,470,558,1970,492,145,1089,1791,446,796,-654,456,-89,1928,470,840,1932,1266,-952,1493,473,629,-257,-949,-92,628,-615,1082,646,10,774,-423,-564,1245,-310,751,290,-181,1514,1941,70,808,1689,-242,90,1696,1559,-326,-587,600,595,222,468,589,611,-899,1827,1434,-300,805,-604,553,171,-884,370,1005,1076,1861,1016,-683,1534,1300,-267,1063,-544,-808,675,806,1378,1600,293,-171,1076,1501,125,1006,274,1893,1570,-758,561,1171,-1,1494,88,-600,73,-909,1278,-287,1588,1235,298,40,562,518,219,1209,1974,926,1026,-45,-837,1490,971,1219,1974,1367,-492,36,-614,1508,-857,111,659,117,1139,1874,-318,1109,-491,-423,1792,-342,1359,453,-760,-278,-603,1023,855,488,1503,527,-1,-402,719,189,1996,955,1299,-861,1597,1087,1058,-219,-821,-53,-653,62,264,-334,-98,-979,1611,-34,-522,-214,1123,1483,694,-307,-323,1997,346,-479,-935,-624,340,1752,210,1472,1413,1878,-533,-702,-649,559,818,461,1847,1419,753,324,970,-988,814,-908,-714,-112,-718,1448,1068,1307,-756,98,1118,1199,-604,-517,691,1203,1991,296,1426,188,-250,1373,1234,113,1889,38,-348,1743,1561,1973,-392,1580,-840,-378,-386,688,1188,639,-747,897,1892,116,-53,-724,-488,-830,1222,-668,1636,122,55,-792,1343,1147,465,812,-113,-394,-905,50,1969,-311,1742,-310,587,422,-331,625,-78,508,-257,-333,986,-479,1741,1004,118,1440,784,166,-408,1091,1931,-692,-738,687,-137,1812,1423,-88,38,-912,62,-891,10,-960,1249,-79,-353,526,1339,-660,1725,1734,1329,60,1794,1227,1660,-711,882,-389,-35,836,507,29,1159,-372,887,1712,1367,1722,1999,-888,-631,-5,1621,-597,582,1951,-745,514,411,1683,1547,-721,-221,485,-856,427,-310,-958,679,1604,-573,1641,1480,1403,1052,-305,358,1201,626,655,-414,1352,1563,1815,-615,1957,-757,-968,-307,74,-176,1744,1482,-65,819,1869,757,-118,-752,-460,-986,-107,-77,1909,-671,1363,1648,546,-592,-279,639,-771,-894,1987,-808,260,-272,-771,-316,-266,-41,38,-596,1071,-171,953,1887]
     */
}
