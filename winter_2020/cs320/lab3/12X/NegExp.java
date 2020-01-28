class NegExp extends Exp {
  private Exp self;
  NegExp (Exp self) {this.self = self;}

  int eval() {
    return -eval();
  }
}
