package SW;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.StringTokenizer;

import Person.Employee;
import Person.SW_Developer;
import Person.SW_Tester;
import Person.Staff;

public class HRSW {
	/*
	 *  파일 입출력
	 *  loadFromFile(String fileName)
	 *  	=> 파일입출력클래스와 StringTokenizer 클래스를 사용하여 불러옴.
	 *  saveToFile(String fileName)
	 *  	=> "/"를 구분자로 사용할 수 있도록 형식에 맞게 파일에 출력
	 */
	
	static String StringForSave = "";
	
	public static void loadFromFile(String fileName) {		// 시작시 실행됨
		BufferedReader read = null;
		String s = null;
		Employee tempEmployee = null;
		try {
			read = new BufferedReader(new FileReader(fileName));
			while((s = read.readLine()) != null) {
				StringTokenizer row = new StringTokenizer(s, "/");		// Data 파일에서는 "/"(슬래시)를 구분자로 사용함. 
				while(row.hasMoreTokens()) {
					Object tempobj[] = new Object[5];
					for(int i = 0; i < 5; i++) {
						tempobj[i] = row.nextToken();
					}
					if(tempobj[3].equals("Staff"))
						tempEmployee = new Staff(tempobj[0].toString(), tempobj[1].toString(), tempobj[2].toString());
					else if(tempobj[3].equals("SW Developer"))
						tempEmployee = new SW_Developer(tempobj[0].toString(), tempobj[1].toString(), tempobj[2].toString());
					else if(tempobj[3].equals("SW Tester"))
						tempEmployee = new SW_Tester(tempobj[0].toString(), tempobj[1].toString(), tempobj[2].toString());
					
					if(tempobj[4].equals("O")) {
						tempEmployee.setManager();
						UserTable.setDepartTable(tempobj[2].toString(), tempobj[1].toString());
					}
					
					UserTable.User.addElement(tempEmployee);
				}
			}
		}
		catch (IOException ioe) {
			ioe.printStackTrace();
		}
		finally {
			try {
				read.close();
			} catch (IOException ioe) {
				ioe.printStackTrace();
			}
		}
		
	}
	
	public static void saveToFile(String fileName) {		// 파일 저장 클릭시 실행
		BufferedWriter writer = null;
		
		try {
			writer = new BufferedWriter(new FileWriter(fileName));
			writer.write(StringForSave);
			StringForSave = "";
		}
		catch (IOException ioe) {
			ioe.printStackTrace();
		}
		finally {
			try {
				writer.close();
			} catch (IOException ioe) {
				ioe.printStackTrace();
			}
		}
	}
	
	public static void makeString(Object row[]) {
		for(int i = 0; i < 5 - 1; i++)
			StringForSave = StringForSave + row[i] + "/";
		StringForSave = StringForSave + row[5 - 1] + "\n";
	}
	
	public static void logging(String str) {
		BufferedWriter writer = null;
		
		try {
			writer = new BufferedWriter(new FileWriter("Log.txt", true));
			long time = System.currentTimeMillis(); 
			SimpleDateFormat dayTime = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
			String currentTime = dayTime.format(new Date(time));
			str = currentTime + str + "\n";
			writer.write(str);
		}
		catch (IOException ioe) {
			ioe.printStackTrace();
		}
		finally {
			try {
				writer.close();
			} catch (IOException ioe) {
				ioe.printStackTrace();
			}
		}
	}
	public static String loadLog() {
		BufferedReader read = null;
		String s = "";
		try {
			read = new BufferedReader(new FileReader("Log.txt"));
			while(true) {
				String line = read.readLine();
				if(line == null)
					break;
				s = s + line + "\n";
			}
		}
		catch (IOException ioe) {
			ioe.printStackTrace();
		}
		finally {
			try {
				read.close();
			} catch (IOException ioe) {
				ioe.printStackTrace();
			}
			
		}
		return s;
	}
}
