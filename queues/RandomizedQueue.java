import java.util.Iterator;
import edu.princeton.cs.algs4.StdRandom;

//Additionally, your iterator implementation must support operations next() and hasNext() 
//in constant worst-case time;
public class RandomizedQueue<Item> implements Iterable<Item> {
	private Item[] randomq;
	private int n;
	
	// construct an empty randomized queue
	public RandomizedQueue() {
		randomq = (Item[]) new Object[1];
		n = 0;
	}
	// is the randomized queue empty?
	public boolean isEmpty() {
		return n == 0;
	}
	// return the number of items on the randomized queue
	public int size() {
		return n;
	}
	
	//resize the array
	private void resize(int size) {
		//temp is a "yinyong"
		Item[] temp = (Item[]) new Object[size]; 
		for(int i=0;i<n;i++) temp[i] = randomq[i];
		randomq = temp;
	}
	
	// add the item
	public void enqueue(Item item) {
		if (item==null) throw new java.lang.IllegalArgumentException("there is nothing");
		if(n==randomq.length) resize(2*n);
		randomq[n++] = item;
		
	}
	
	// remove and return a random item
	//exchange the chosen element with the last element
	//then,delete the last one
	//so that realize deleting the random element in the end of queue
	public Item dequeue() {
		//faster than call isEmpty()
		if(n==0) throw new java.util.NoSuchElementException("array is empty");
		int i = StdRandom.uniform(0,n);
		Item temp = randomq[i];
		// pay attention to the change of n
		if(i != --n) randomq[i] = randomq[n];
		randomq[n] = null;
		//here without n>0.wrong,try:add one,delete one
		if(n>0 && n==randomq.length/4) resize(randomq.length/2);
		return temp;
	}
	
	// return a random item (but do not remove it)
	public Item sample() {
		if(n==0) throw new java.util.NoSuchElementException("array is empty");
		return randomq[StdRandom.uniform(0,n)];
	}
	
	// return an independent iterator over items in random order
	public Iterator<Item> iterator(){
		return new RandomIterator();
	}
	
	// inner class
	private class RandomIterator implements Iterator<Item>{
		// m is as index,just like the pointer in Deque
		private int m;
		private Item[] iterq;
		private RandomIterator() {
			iterq = (Item[])new Object[n];
			for(int i=0;i<n;i++) iterq[i] = randomq[i];
			//random order
			StdRandom.shuffle(iterq);
		}
		
		public boolean hasNext() {
			return m < n;
		}
		
		public void remove() {
			throw new java.lang.UnsupportedOperationException("you mustn't do this!");
		}
		
		public Item next() {
			if(m>=n) throw new java.util.NoSuchElementException("no next element!");
			Item temp = iterq[m++];
			return temp;
		}
	}
	// unit testing (optional)
	public static void main(String[] args) {
		RandomizedQueue<String> rq = new RandomizedQueue<String>();
		System.out.println(rq.isEmpty());
		System.out.println(rq.size());
		rq.enqueue("haha");
		rq.enqueue("heihei");
		rq.enqueue("hiahia");
		rq.enqueue("hehe");
		rq.enqueue("houhou");
		System.out.println(rq.size());
		rq.dequeue();
		rq.dequeue();
		
		Iterator<String> iter = rq.iterator();
		while(iter.hasNext()) System.out.println(iter.next());
		System.out.println();
		Iterator<String> iter2 = rq.iterator();
		while(iter2.hasNext()) System.out.println(iter2.next());
	}
}