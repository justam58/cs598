
public class LinkedList<T> {
	
	private Node<T> head;
	private int length;
	
	public LinkedList(){
		head = new Node<T>();
		length = 0;
	}
	
	public void push(T newData){
		Node<T> current = head;
		while(current.next != null){
			current = current.next;
		}
		Node<T> newNode = new Node<T>(newData,null);
		current.next = newNode;
		length++;
	}
	
	public void remove(T removeData){
		Node<T> current = head;
		boolean found = false;
		while(current.next != null){
			if(current.next.data == removeData){
				found = true;
				current.next = current.next.next;
				break;
			}
			current = current.next;
		}
		if(found){
			length--;
		}
	}
	
	public int getLength(){
		return length;
	}
	
	public Node<T> getNth(int index){
		if(index > length){
			return null;
		}
		Node<T> current = head.next;
		int i = 1;
		while(current != null){
			if(i == index){
				break;
			}
			current = current.next;
			i++;
		}
		return current;
	}
	
	public void insert(int index, T newData){
		if(index > length+1 || index <= 0){
			return;
		}
		if(index == length+1){
			this.push(newData);
			return;
		}
		Node<T> current = head;
		int i = 1;
		while(current.next != null){
			if(i == index){
				Node<T> newNode = new Node<T>(newData,current.next);
				current.next = newNode;
				length++;
				break;
			}
			current = current.next;
			i++;
		}
	}
	
	public int count(T searchFor){
		Node<T> current = head.next;
		int result = 0;
		while(current != null){
			if(current.data == searchFor){
				result++;
			}
			current = current.next;
		}
		return result;
	}
	
	public Node<T> pop(){
		if(length == 0){
			return null;
		}
		if(length == 1){
			Node<T> result = head.next;
			head.next = null;
			length--;
			return result;
		}
		Node<T> current = head;
		while(current.next.next != null){
			current = current.next;
		}
		Node<T> result = current.next;
		current.next = null;
		length--;
		return result;
	}

	@Override
	public String toString() {
		if(length == 0){
			return "No Data";
		}
		String result = "";
		Node<T> current = head.next;
		while(current != null){
			result += current.data;
			if(current.next != null){
				result += " -> ";
			}
			current = current.next;
		}
		return result;
	}
	
}
