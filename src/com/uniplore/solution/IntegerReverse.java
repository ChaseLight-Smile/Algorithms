package com.uniplore.solution;

/**
 * 功能: 将任意32位的整型数反转，如果溢出，则返回0，LeetCode第七题
 * @author 朱君鹏
 *
 */
public class IntegerReverse {

	public int reverse(int x) {
        int absX = 0;
        if(x < 0){
            absX = Math.abs(x); //将其转换成无符号整数
        }else {
            absX = x;
        }
        
        int result = 0 ; 
        char[] xChar = String.valueOf(absX).toCharArray();  //转换成char类型数组
        for (int i = 0 ; i < (xChar.length)/2 ; i++) {
            char temp = 0 ;
            temp = xChar[i];
            xChar[i] = xChar[xChar.length-1-i];
            xChar[xChar.length-1-i] = temp;
            //将字符数组转换成整型
        }
        try{
            result = Integer.parseInt(String.valueOf(xChar));
        }catch (Exception e){
            return 0;
        }
        
        
        if (x < 0 ){
            x = -1 * result;
            return x;
        }else {
            x = result;
            return x;
        }
    }
}
