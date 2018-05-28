import java.util.Iterator;

public class Deque<Item> implements Iterable<Item>{
	private Node first,last; //64位系统,每个引用8bytes,此处共16bytes
	private int n; //4bytes
	
	private class Node{  //64位系统,对象头16bytes , 内部类开销8bytes
		private Item item;  //64位系统,8bytes
		private Node next;  //64位系统,8bytes
		private Node pre;  //64位系统,8bytes     所以,1个Node占用48bytes,n个Node就是48n bytes
	}
	
	// construct an empty deque
	public Deque() {
		first = null;
		last = null;
		n = 0;
	}
	
	//is Deque empty?
	public boolean isEmpty() {
		return n == 0;
	}
	
	// return the number of items on the deque
	public int size() {
		return n;
	}
	
	// add the item to the front
	public void addFirst(Item item) {
		if(item==null) throw new java.lang.IllegalArgumentException("there is nothing");
		Node oldfirst = first;
		first = new Node();
		first.item = item;
		first.next = oldfirst;
		//if(isEmpty())   just use n rather to call isEmpty()
		if(n==0) last = first;
		else oldfirst.pre = first;
		n++;
	}
	
	// add the item to the end
	public void addLast(Item item) {
		if(item==null) throw new java.lang.IllegalArgumentException("there is nothing");
		Node oldlast = last;
		last = new Node();
		last.item = item;
		last.pre = oldlast;
		if(n==0) first = last;
		else oldlast.next = last;
		n++;
	}
	   
	// remove and return the item from the front
	public Item removeFirst() {
		//if 'if' runs,the program would stop
		if(n==0) throw new java.util.NoSuchElementException("Deque is empty!!");
		Item temp = first.item;
		first = first.next;
		n--;
		//check if the Deque is empty after remove
		if(n==0) last = null;//first is null now 
		else first.pre = null;
		return temp;
	}
	
	// remove and return the item from the end
	public Item removeLast() {
		if(n==0) throw new java.util.NoSuchElementException("Deque is empty!!");
		Item temp = last.item;
		last = last.pre;
		n--;
		if(n==0)first = null;
		else last.next=null;
		return temp;
	}
	
	// return an iterator over items in order from front to end
	public Iterator<Item> iterator(){
		return new ListIterator();
	}
	private class ListIterator implements Iterator<Item>{ //对象头:16bytes 
		private Node current = first; //内部类额外开销8bytes,引用8bytes
		
		public boolean hasNext() {
			return current != null;
		}
		
		public void remove() {
			throw new java.lang.UnsupportedOperationException("you mustn't do this!");
		}
		
		public Item next() {
			if(current == null) throw new java.util.NoSuchElementException("no such element");
			Item temp = current.item;
			current = current.next;
			return temp;
		}
	}
	
	//main
	public static void main(String[] args) {
		Deque<String> deque = new Deque<String>();
		System.out.println(deque.size());
		deque.addFirst("haha");
		deque.addFirst("hehe");
		deque.addFirst("heihei");
		deque.addFirst("hiahia");
		deque.addFirst("houhou");
		System.out.println(deque.size());
		deque.removeFirst();
		System.out.println(deque.size());
		deque.removeLast();
		System.out.println(deque.size());
		Iterator<String> i = deque.iterator();
		while(i.hasNext()) System.out.println(i.next());
	}
}