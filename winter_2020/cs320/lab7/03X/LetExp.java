class LetExp extends Exp {
  private String x;
  private Exp d;
  private Exp e;
  LetExp(String x, Exp d, Exp e) {this.x = x; this.d = d; this.e = e;}

	/*
	int eval(Env<Integer> env)  throws Env.UndefinedId {
		int v = d.eval(env);
		return e.eval(env.extend(x,v));
	}
	*/

	void emit(Env<Integer> env, int depth) throws Env.UndefinedId{
		int v = depth;
		d.emit(env, depth);
		e.emit(env.extend(x,v), depth + 1);
		System.out.printf("SWAP %d\n", 1);
    System.out.println("POP");
	} 

	
}

