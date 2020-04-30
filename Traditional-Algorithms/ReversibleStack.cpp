/** 
C. Reversible Stack
单测试点时限: 3.0 秒
内存限制: 256 MB
出题人当然是希望出的题目看起来并非毫无意义，于是想方设法给题目配上一些背景故事，使得它看起来不那么无趣。但有时候适得其反。比如当你坐在考场中焦头烂额的时候，眼前又出现一大段的让你感到很困惑的中文，这时候你只会更加焦头烂额。
有这么一种栈，支持三种操作。
1.	1 X：在栈顶压入元素 X。
2.	2：弹出栈顶元素。
3.	3：翻转整个栈（栈顶元素到最下面，第二个元素到倒数第二，依次类推）。
要求在每次操作后输出栈顶的元素。如果操作后栈空，输出 −1。
输入
第一行一个整数 q。
接下来每一行为 1 X, 2, 3 这三种之一。1≤X≤109，可能会有相同的数出现。
输入保证操作序列合法：不会对空栈进行操作 2，但可能会进行操作 3。
部分分约定：
•	30%: 没有反转操作；
•	70%: 操作数量不超过 103；
•	100%: 操作数量不超过 3⋅105。
输出
输出 q 行，每行一个结果。
样例
Input
5
1 1
2
1 3
1 2
2
Output
1
-1
3
2
3
Input
11
1 1
1 2
1 3
1 4
1 5
3
2
2
2
2
2
Output
1
2
3
4
5
1
2
3
4
5
-1
*/

/** C++ STL实现
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    stack<int> s1;
    int n;
    int a;
    int b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1){
            cin>>b;
            s.push(b);
        }
        if(a==2){
            s.pop();
        }
        if(a==3){
            while(!s.empty()){
                s1.push(s.top());
                s.pop();
            }
            s=s1;
            while(!s1.empty()){
                s1.pop();
            }
        }
        if(!s.empty()){
            cout<<s.top()<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
    return 0;
}*/

//数组实现
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int size=0;
    int len,a,b,k;
    cin>>len;
    int *p=new int[len];
    memset(p,-1,len*sizeof(p));
    for(int i=0;i<len;i++){
        cin>>a;
        if(a==1){
            cin>>b;
            size++;
            p[size-1]=b;
            cout<<p[size-1]<<endl; 
        }
        if(a==2){
            p[size-1]=-1;
            size--;
            if(size==0){
                cout<<"-1"<<endl;
            }
            else{
                cout<<p[size-1]<<endl;
            }
        }
        if(a==3){
            if(size==0){
               cout<<"-1"<<endl;
            }
            else{
                for(int i=0;i<=(size-1)/2;i++){
                    k=p[i];
                    p[i]=p[size-1-i];
                    p[size-1-i]=k;
                }
				cout<<p[size-1]<<endl;
            }   
        }

    }
    return 0;
}
