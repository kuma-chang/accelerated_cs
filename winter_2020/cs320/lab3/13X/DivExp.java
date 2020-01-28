class DivExp extends Exp {
  private Exp left;
  private Exp right;
  DivExp (Exp left, Exp right) {this.left = left; this.right = right;}

	void emit() {
			left.emit();
			right.emit();
      System.out.println("DIV");
	}

  int eval() {
    return left.eval() / right.eval();
  }
}
