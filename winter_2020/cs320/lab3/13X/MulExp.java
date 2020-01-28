class MulExp extends Exp {
  private Exp left;
  private Exp right;
  MulExp (Exp left, Exp right) {this.left = left; this.right = right;}


	void emit() {
			left.emit();
			right.emit();
      System.out.println("MUL");
	}



  int eval() {
    return left.eval() * right.eval();
  }
}
