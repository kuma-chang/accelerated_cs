/** Tokens for the simple expression language. 
 */

enum Token {
  LPAR("("),
  RPAR(")"),
  PLUS("+"),
  MINUS("-"),
  TIMES("*"),
  DIVIDE("/"),
  NUMBER("NUMBER"),
  EOF("end-of-input"),

  TRUE("T"),
  FALSE("F"),
  AND("&"),
  OR("|"),
  NOT("~"),
  LEQ("<=");

  final String rep;
    
  Token(String rep) {
    this.rep = rep;
  }
}


