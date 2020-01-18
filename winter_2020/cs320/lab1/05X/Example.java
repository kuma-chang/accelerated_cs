import java.io.*;
import java.nio.file.*;
import java.util.*;

class Example {
  public static void main (String argv[]) throws IOException {
    int[] is = readIntArray(argv[0]);
	
	//Assign b, min and s from the command line arguments
	int num_bin = Integer.parseInt(argv[1]);
	int min = Integer.parseInt(argv[2]);
	int step = Integer.parseInt(argv[3]);
	
	//Creat an array to record each count for each bin
	int[] ans = new int[num_bin+2];
	
	//Set all elements in ans to zero
	for (int i = 0; i < (num_bin + 2); i++)
			ans[i] = 0;

	//Go through is[] and count which bin does each data belong
	for(int i: is)
	{
			int dif = ((i - min) / step) + 1;
			if (dif <= 0)
					ans[0]++;
			else if (dif > num_bin)
					ans[num_bin + 1]++;
			else
					ans[dif]++;
	}

	//Print out the table
    for (int i = 0; i <= num_bin + 1; i++)
	{
			if (i == 0)
					System.out.println("x < " + min + ": " + ans[i]);

			else if (i == (num_bin + 1))
					System.out.println("x >= " + (min + (step*num_bin)) + ": " + ans[i]);
			else
					System.out.println((min + (step*(i-1))) + " <= x < " + (min + (step*i)) + ": " + ans[i]);
	}
  }

  private static int[] readIntArray(String filename) throws IOException {
    try (BufferedReader f = Files.newBufferedReader(Paths.get(filename));
	 Scanner sc = new Scanner(f)) {
      int n = sc.nextInt();
      int[] is = new int[n];
      for (int i = 0; i < n; i++)
			  is[i] = sc.nextInt();
      return is;
    }
  }
}


