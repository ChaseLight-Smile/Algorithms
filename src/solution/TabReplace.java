package solution;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
/**
 * 功能: 实现将文本中的分隔符改成,分割，方便将数据导入到数据库中，采用","分割，而不是采用\t分割.
 * @author 朱君鹏
 *
 */
public class TabReplace {
	
	public static void main(String[] args) throws Exception{
		File file1 = new File("G:\\硕士研究生毕业设计\\TrafficManagementBurea\\plate-20170708\\plate-20170708.txt");
	    File file2 = new File("G:\\硕士研究生毕业设计\\TrafficManagementBurea\\plate-20170708\\plate-20170708-replace.txt"); 
	    FileInputStream fileInput = new FileInputStream(file1);
	    FileOutputStream fileOutput = new FileOutputStream(file2);
	    
	    InputStreamReader in = new InputStreamReader(fileInput);
	    OutputStreamWriter out = new OutputStreamWriter(fileOutput);
	    
	    BufferedReader reader = new BufferedReader(in);
	    BufferedWriter writer = new BufferedWriter(out);
	    
	    String content = null;
	    String new_content = "";
	    
	    //int length = 0 ;   //限制产生多少条数据，看数据究竟是什么样子
	    while((content = reader.readLine()) != null){
	    	new_content = "";
	    	//System.out.println(content);  //限制产生多少条数据，看数据究竟是什么样子
	    	//length++;                     //限制产生多少条数据，看数据究竟是什么样子
	    	
	    	//if(length == 10){             //限制只输出10条数据
	    		//break;                    
	    	//}                             //限制只输出10条数据
	    	
	    	String[] str = content.split("\t");
	    	
	    	//将其重新组成一个新的字符串输出
	    	
	    	for(int i = 0 ; i < str.length ; i++){
	    		if(i == str.length - 1){
	    			new_content = new_content + str[i];
	    		}else{
	    			new_content = new_content + str[i] + "|";
	    		}
	    	}
	    	writer.write(new_content + "\n");  
	    }
	    
	    writer.close();
	    reader.close();
	}
    
    
}
