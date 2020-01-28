class NegExp extends Exp {
  private Exp self;
  NegExp (Exp self) {this.self = self;}


	void emit() {
			self.emit();
      System.out.println("NEG");
	}

  int eval() {
    return -eval();
  }
}
