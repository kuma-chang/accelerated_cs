import java.util.*;
import java.util.stream.*;

class Example {

  public static void main(String argv[]) {
    int a[] =
      Arrays.stream(argv)
      .mapToInt(s -> Integer.parseInt(s))
      .toArray();

    System.out.println("part a:");
    int m = 
      Arrays.stream(a)         // generate stream from array
			.max()
			.getAsInt();
      //0; // replace this expression starting Arrays.stream(a)
    System.out.println(m);

    System.out.println("part b:");
    // fill in here with expresssion starting Arrays.stream(a)
		Arrays.stream(a)       
			.filter(x -> x % 3 == 1) 
			.distinct()
			.forEach(x -> System.out.println(x));  // print each one

    System.out.println("part c:");
    // fill in here with expresssion starting Arrays.stream(a)
		long index_0_1 = 
			IntStream.range(0, a.length)
					.filter(i -> 0 == a[i])
					.findFirst()
					.orElse(-1);
		int index_0_2 = 
			IntStream.range(0, a.length)
					.skip(index_0_1 + 1)
					.filter(i -> 0 == a[i])
					.findFirst()
					.orElse(-1);

		IntStream.range(0, index_0_2)
			.skip(index_0_1 + 1)
			.forEach(x -> System.out.println(a[x]));  // print each one


    System.out.println("part d:");
    // fill in here with expresssion starting Arrays.stream(a)
		Arrays.stream(a)         // generate stream from array
			.forEach(x -> IntStream.iterate(1, y -> y + 1)
					.takeWhile(y -> y <= x)             // cut stream off after values exceed x
					.forEach(y -> System.out.println(x))
					);  

    System.out.println("part e:");
		long count = Arrays.stream(a).count();
    int last = 
      Arrays.stream(a)         // generate stream from array
			.skip(count - 1)
			.findFirst()
			.getAsInt();
			//0; // replace this expression starting Arrays.stream(a)
    System.out.println(last);
  }
}
