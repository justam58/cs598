import java.util.Scanner;

public class Main2 {
	
	public enum Language { JAVA, C, UNKNOWN }

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextLine()){
			String line = sc.nextLine();
			if(javaOrC(line).equals(Language.JAVA)){
				line = toC(line);
				System.out.println(line);
			}
			else if(javaOrC(line).equals(Language.C)){
				line = toJava(line);
				System.out.println(line);
			}
			else{
				System.out.println("Error!");
			}
		}
		sc.close();
	}
	
	private static String toJava(String line) {
		String result = "";
		String[] parts = line.split("_");
		for(int i = 0; i < parts.length; i++){
			if(i == 0){
				result += parts[i];
			}
			else{
				if(parts[i].length() > 1){
					String sub = parts[i].substring(1);
					String head = parts[i].substring(0,1).toUpperCase();
					result += head + sub;
				}
				else{
					result += parts[i].toUpperCase();
				}
			}
		}
		return result;
	}

	private static String toC(String line) {
		String temp = "";
		String result = "";
		for(int i = 0; i < line.length(); i++){
			if(Character.isUpperCase(line.charAt(i))){
				result += "_" + temp.toLowerCase();
				temp = "";
			}
			temp += line.substring(i,i+1);
		}
		result += "_" + temp.toLowerCase();
		return result.substring(1);
	}

	public static Language javaOrC(String line){
		for(int i = 0; i < line.length(); i++){
			if(!Character.isLetter(line.charAt(i)) && line.charAt(i) != '_'){
				return Language.UNKNOWN;
			}
			if(i != line.length()-1){
				if(line.charAt(i) == '_' && line.charAt(i+1) == '_'){
					return Language.UNKNOWN;
				}
			}
		}
		if(line.equals(line.toLowerCase()) && line.charAt(0) != '_' && line.charAt(line.length()-1) != '_'){
			return Language.C;
		}
		if(!line.contains("_") && !Character.isUpperCase(line.charAt(0))){
			return Language.JAVA;
		}
		return Language.UNKNOWN;
	}

}
