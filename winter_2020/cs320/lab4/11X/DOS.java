public class DOS {

  public static void main(String argv[]) throws Exception {
    String filename = argv[0];
    String[] fields = filename.split("[.]");
		int degree;
    if (fields[1].equals("ig")) {
      Graph<Integer> g = GraphUtils.readIntegerGraph(fields[0]);
			BreadthFirstPaths<Integer> p = new BreadthFirstPaths<Integer>(g, Integer.parseInt(argv[1]));
			degree = p.distTo(Integer.parseInt(argv[2]));
			System.out.println("Degrees of separation: " + degree);
			String s = "Sample path: \n";
      for (int w : p.pathTo(Integer.parseInt(argv[2]))) 
				s += w + "\n";
			System.out.println(s);
    } else if (fields[1].equals("sg")) {
      Graph<String> g = GraphUtils.readStringGraph(fields[0],argv[1]);
			BreadthFirstPaths<String> p = new BreadthFirstPaths<String>(g, argv[2]);
			degree = p.distTo(argv[3]);
			System.out.println("Degrees of separation: " + degree);
			String s = "Sample path: \n";
      for (String w : p.pathTo(argv[3])) 
				s += w + "\n";
			System.out.println(s);
    }
  }
}
