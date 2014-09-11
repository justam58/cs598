
public class Main {
	
	public static void main(String[] args) {
		LinkedList<Integer> myList = new LinkedList<Integer>();

		// Testing push and getLen
		System.out.println("Testing Push and GetLen");
		boolean ok = true;
		if(myList.toString() != "No Data"){
			ok = false;
			System.out.println("ERROR: Case 1 Failed");
		}
		if(myList.getLength() != 0){
			ok = false;
			System.out.println("ERROR: Case 1 len Failed");
		}
		myList.push(3);
		if(!myList.toString().equals("3")){
			ok = false;
			System.out.println("ERROR: Case 2 Failed");
		}
		if(myList.getLength() != 1){
			ok = false;
			System.out.println("ERROR: Case 2 len Failed");
		}
		myList.push(7);
		if(!myList.toString().equals("3 -> 7")){
			ok = false;
			System.out.println("ERROR: Case 3 Failed");
			System.out.println(myList.toString());
		}
		if(myList.getLength() != 2){
			ok = false;
			System.out.println("ERROR: Case 3 len Failed");
		}
		myList.push(2);
		if(!myList.toString().equals("3 -> 7 -> 2")){
			ok = false;
			System.out.println("ERROR: Case 4 Failed");
			System.out.println(myList.toString());
		}
		if(myList.getLength() != 3){
			ok = false;
			System.out.println("ERROR: Case 4 len Failed");
		}
		if(ok){
			System.out.println("GOOD");
		}
		
		
		
		// Testing remove and getLen
		System.out.println("Testing Remove and GetLen");
		ok = true;
		myList.remove(2);
		if(!myList.toString().equals("3 -> 7")){
			ok = false;
			System.out.println("ERROR: Case 1 Failed");
		}
		if(myList.getLength() != 2){
			ok = false;
			System.out.println("ERROR: Case 1 len Failed");
		}
		myList.push(2);
		myList.remove(7);
		if(!myList.toString().equals("3 -> 2")){
			ok = false;
			System.out.println("ERROR: Case 2 Failed");
		}
		if(myList.getLength() != 2){
			ok = false;
			System.out.println("ERROR: Case 2 len Failed");
		}
		myList.push(7);
		myList.remove(3);
		if(!myList.toString().equals("2 -> 7")){
			ok = false;
			System.out.println("ERROR: Case 3 Failed");
		}
		if(myList.getLength() != 2){
			ok = false;
			System.out.println("ERROR: Case 3 len Failed");
		}
		if(ok){
			System.out.println("GOOD");
		}
		myList.push(3);


		
		// Testing getNth
		System.out.println("Testing GetNth");
		ok = true;
		Node<Integer> result = myList.getNth(0);
		if(result != null){
			ok = false;
			System.out.println("ERROR: Case 1 Failed");
		}
		result = myList.getNth(1);
		if(result.data != 2){
			ok = false;
			System.out.println("ERROR: Case 2 Failed");
		}
		result = myList.getNth(2);
		if(result.data != 7){
			ok = false;
			System.out.println("ERROR: Case 3 Failed");
		}
		result = myList.getNth(3);
		if(result.data != 3){
			ok = false;
			System.out.println("ERROR: Case 4 Failed");
		}
		result = myList.getNth(4);
		if(result != null){
			ok = false;
			System.out.println("ERROR: Case 5 Failed");
		}
		if(ok){
			System.out.println("GOOD");
		}
		
		
		
		// Testing insert and getLen
		System.out.println("Testing Insert and GetLen");
		ok = true;
		myList.insert(0,8);
		if(!myList.toString().equals("2 -> 7 -> 3")){
			ok = false;
			System.out.println("ERROR: Case 1 Failed");
		}
		if(myList.getLength() != 3){
			ok = false;
			System.out.println("ERROR: Case 1 len Failed");
		}
		myList.insert(1,8);
		if(!myList.toString().equals("8 -> 2 -> 7 -> 3")){
			ok = false;
			System.out.println("ERROR: Case 2 Failed");
		}
		if(myList.getLength() != 4){
			ok = false;
			System.out.println("ERROR: Case 2 len Failed");
		}
		myList.remove(8);
		myList.insert(2,8);
		if(!myList.toString().equals("2 -> 8 -> 7 -> 3")){
			ok = false;
			System.out.println("ERROR: Case 3 Failed");
		}
		if(myList.getLength() != 4){
			ok = false;
			System.out.println("ERROR: Case 3 len Failed");
		}
		myList.remove(8);
		myList.insert(3,8);
		if(!myList.toString().equals("2 -> 7 -> 8 -> 3")){
			ok = false;
			System.out.println("ERROR: Case 4 Failed");
		}
		if(myList.getLength() != 4){
			ok = false;
			System.out.println("ERROR: Case 4 len Failed");
		}
		myList.remove(8);
		myList.insert(4,8);
		if(!myList.toString().equals("2 -> 7 -> 3 -> 8")){
			ok = false;
			System.out.println("ERROR: Case 5 Failed");
		}
		if(myList.getLength() != 4){
			ok = false;
			System.out.println("ERROR: Case 5 len Failed");
		}
		myList.remove(8);
		myList.insert(5,8);
		if(!myList.toString().equals("2 -> 7 -> 3")){
			ok = false;
			System.out.println("ERROR: Case 5 Failed");
		}
		if(myList.getLength() != 3){
			ok = false;
			System.out.println("ERROR: Case 5 len Failed");
		}
		if(ok){
			System.out.println("GOOD");
		}
		
		// Testing count
		System.out.println("Testing Count");
		ok = true;
		myList.push(7);
		myList.push(7);
		myList.push(2);
		int resultInt = myList.count(0);
		if(resultInt != 0){
			ok = false;
			System.out.println("ERROR: Case 1 Failed");
		}
		resultInt = myList.count(2);
		if(resultInt != 2){
			ok = false;
			System.out.println("ERROR: Case 2 Failed");
		}
		resultInt = myList.count(7);
		if(resultInt != 3){
			ok = false;
			System.out.println("ERROR: Case 3 Failed");
		}
		resultInt = myList.count(3);
		if(resultInt != 1){
			ok = false;
			System.out.println("ERROR: Case 4 Failed");
		}
		if(ok){
			System.out.println("GOOD");
		}

		// Testing pop
		System.out.println("Testing Pop");
		ok = true;
		myList.pop();
		myList.pop();
		myList.pop();
		result = myList.pop();
		if(result.data != 3){
			ok = false;
			System.out.println("ERROR: Case 1 Failed");
		}
		result = myList.pop();
		if(result.data != 7){
			ok = false;
			System.out.println("ERROR: Case 2 Failed");
		}
		result = myList.pop();
		if(result.data != 2){
			ok = false;
			System.out.println("ERROR: Case 3 Failed");
		}
		result = myList.pop();
		if(result != null){
			ok = false;
			System.out.println("ERROR: Case 4 Failed");
		}
		if(ok){
			System.out.println("GOOD");
		}
	}
	
}
