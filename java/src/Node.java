
public class Node<T> {
	
	public T data;
	public Node<T> next;
	
	public Node(T data, Node<T> next){
		this.data = data;
		this.next = next;
	}
	
	public Node(){
		this.data = null;
		this.next = null;
	}

	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}
	
}
