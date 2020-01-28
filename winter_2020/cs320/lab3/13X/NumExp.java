class NumExp extends Exp {
  private int num;
  NumExp(int num) {this.num = num;}

	void emit() {
      System.out.println("PUSH " + num);
	}


  int eval() {
    return num;
  }
}

