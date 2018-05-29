package solution;
import java.io.*;

import org.junit.Test;

/**
 * 功能: 递归遍历整个计算机，将其中的文件输出，如果是文件夹，递归的遍历其中的内容，当然可以用程序删除所有的内容，在这里我没有尝试，如果你喜欢
 * 你可以做，可以基于此技术设计一个系统检索软件，像Everything那样，但是还要有正则查询功能
 */

public class FileOperation {

	//给定一个路径，递归的遍历其中所有的文件，采用递归算法，时间复杂度为O(n)
	public static void listFileRecursive(File[] files,int start , int end){
		if(start == end){   //start == end说明锁定了当前的一个文件或者文件夹
			if(files[start] != null && files[start].isDirectory()){  //判断当前位置究竟是文件还是文件夹，如果是文件夹
 				File[] files2 = files[start].listFiles(); //计算该文件夹的长度 
				int length = 0;
				if (files2 != null) {
					length= files2.length;
				}
				
				//System.out.println(length);
				if(length != 0){   //当前是一个文件夹，但是该文件夹为空时，不需要遍历
					listFileRecursive(files2, 0, length-1);  //递归的遍历该文件夹
				}else {
					return;
				}	
			}else{  //否则说明当前位置是文件，则输出其文件名，递归结束
				System.out.println(files[start].getName());
				return;
			}
		}else {  //否则进行递归
			//否则进行递归操作
			int mid = (start + end) /2 ;
			listFileRecursive(files, start, mid);  //采用分治策略，一分为二的解决问题，递归一半
			listFileRecursive(files, mid+1, end);  //采用分治策略，递归的寻找另外一半
		}
	}
	
	@Test
	public void testListFile(){
		//列出所有的根目录
		File[] roots = File.listRoots();  //得到所有可用的根路径，在Windows上得到C:\，D:\...
		int rootsLength = roots.length;
		//System.out.println(rootsLength);
		if(rootsLength != 0){
			for (File file : roots) {
				file = new File(file.getPath());  //根据根路径名构造File对象
				File[] files = file.listFiles();  //列出当前对象所有的文件和文件夹
				int length = files.length;  //计算其长度
				//System.out.println(length);
				if(length != 0){   //当前目录不为空时遍历当前File对象
					listFileRecursive(files, 0, length-1);  //递归的进行遍历输出结果
				}
			}
		}  //if结束
	}
}
