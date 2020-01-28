class NegExp extends Exp {
  private Exp self;
  NegExp (Exp self) {this.self = self;}


	void emit() {
      System.out.println("NEG");
			self.emit();
	}

  int eval() {
    return -eval();
  }
}
