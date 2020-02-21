class IdExp extends Exp {
    private String id;
  IdExp(String id) {this.id = id;}


	/*
	int eval(Env<Integer> env) throws Env.UndefinedId {
		return env.lookup(id);
	}
	*/

	void emit(Env<Integer> env, int depth) throws Env.UndefinedId{
		int v = depth - 1 - env.lookup(id);
		System.out.printf("DUP %d\n", v);
	} 

}

