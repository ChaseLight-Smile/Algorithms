package solution;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
public class TabReplace {
	
	public static void main(String[] args) throws Exception{
		File file1 = new File("");
	    File file2 = new File(""); 
	    FileInputStream fileInput = new FileInputStream(file1);
	    FileOutputStream fileOutput = new FileOutputStream(file2);
	    
	    InputStreamReader in = new InputStreamReader(fileInput);
	    OutputStreamWriter out = new OutputStreamWriter(fileOutput);
	    
	    BufferedReader reader = new BufferedReader(in);
	    BufferedWriter writer = new BufferedWriter(out);
	    
	    String content = null;
	    String new_content = "";
	    int length = 0 ;
	    while((content = reader.readLine()) != null){
	    	new_content = "";
	    	String[] str = content.split("\t");
	    	
	    	//将其重新组成一个新的字符串输出
	    	
	    	for(int i = 0 ; i < str.length ; i++){
	    		if(i == str.length - 1){
	    			new_content = new_content + str[i];
	    		}else{
	    			new_content = new_content + str[i] + " ";
	    		}
	    	}
	    	writer.write(new_content + "\n");
	    
	    }
	}
    
    
}
