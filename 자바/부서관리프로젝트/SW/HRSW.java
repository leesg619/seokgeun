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
	 *  ���� �����
	 *  loadFromFile(String fileName)
	 *  	=> ���������Ŭ������ StringTokenizer Ŭ������ ����Ͽ� �ҷ���.
	 *  saveToFile(String fileName)
	 *  	=> "/"�� �����ڷ� ����� �� �ֵ��� ���Ŀ� �°� ���Ͽ� ���
	 */
	
	static String StringForSave = "";
	
	public static void loadFromFile(String fileName) {		// ���۽� �����
		BufferedReader read = null;
		String s = null;
		Employee tempEmployee = null;
		try {
			read = new BufferedReader(new FileReader(fileName));
			while((s = read.readLine()) != null) {
				StringTokenizer row = new StringTokenizer(s, "/");		// Data ���Ͽ����� "/"(������)�� �����ڷ� �����. 
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
	
	public static void saveToFile(String fileName) {		// ���� ���� Ŭ���� ����
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
