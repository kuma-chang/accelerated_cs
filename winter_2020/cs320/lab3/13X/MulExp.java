class MulExp extends Exp {
  private Exp left;
  private Exp right;
  MulExp (Exp left, Exp right) {this.left = left; this.right = right;}


	void emit() {
      System.out.println("MUL");
			left.emit();
			right.emit();
	}



  int eval() {
    return left.eval() * right.eval();
  }
}
