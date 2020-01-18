class Example {
  public static void main (String argv[]) {
    if (argv.length !=1)
      usage();
    int n = 0;
    try {
      n = Integer.parseInt(argv[0]);
    } catch (NumberFormatException e) {
      usage();
    }
    for (int i = 1; i <= n; i++)
	{
			if (i%3 == 0 && i%5 == 0)
					System.out.println("FlimFlam");
			else if (i%3 == 0)
					System.out.println("Flim");
			else if (i%5 == 0)
					System.out.println("Flam");
			else
					System.out.println(Integer.toString(i));
	}
  }

  private static void usage() {
    System.err.println("usage: java Example count string");
    System.exit(1);
  }
}


