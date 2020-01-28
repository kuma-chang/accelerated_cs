import java.lang.Math;
public class Example {

  static class Item {
    boolean b;
    float d;
    Item(boolean argb, float argd) {
      b = argb;
      d = argd;
    }
  }

  static class Link{
    Item itm;
    Link next;
    Link(Item argitm, Link argnext) {
      itm = argitm; 
      next = argnext;
    }
  }

  static float f(Link list)
  {
    float sum = 0;
    while (list != null) {
      sum += list.itm.b ? list.itm.d : 0.0;
      list = list.next;
    }
    return sum;
  }

  static public void main (String[] argv) {

    int n = Integer.parseInt(argv[0]);
    Link list = null;
    for (int i = 1; i <= n; i++) {
      Item itm = new Item(i%2 != 0, (float)Math.sqrt(i));
      list = new Link(itm, list);
    }
    float s = f(list);
    System.out.println ("sum = " + s);

  }
}

