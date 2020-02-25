import java.util.*;

class Range implements Iterable<Integer>{
  int low;
  int high;
  Range(int low, int high) {this.low = low; this.high = high;}

	public Iterator<Integer> iterator()
	{
		return new RangeIterator();
	}
	private class RangeIterator implements Iterator<Integer>
	{
		int curr;
		RangeIterator() {curr = low;};

		public boolean hasNext()
		{
			return curr < high;
		}
		public Integer next()
		{
			if (curr < high)
			{
				Integer s = curr;
				curr++;
				return s;
			}
			else
				throw new NoSuchElementException();
		}
	}

}

