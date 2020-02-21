class MulExp extends Exp {
  private Exp left;
  private Exp right;
  MulExp (Exp left, Exp right) {this.left = left; this.right = right;}


	void emit(Env<Integer> env, int depth) throws Env.UndefinedId{
    left.emit(env, depth);
    right.emit(env, depth + 1);
    System.out.println("MUL");
	} 

}

