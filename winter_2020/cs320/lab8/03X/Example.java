import java.util.*;
import java.util.function.*;

class Point {
  double x;
  double y;
  Point (double x, double y) {this.x = x; this.y = y;}

  double distance(Point other) {
    double delta_x = this.x - other.x;
    double delta_y = this.y - other.y;
    return Math.sqrt(delta_x * delta_x + delta_y * delta_y);
  }
}


class PSet {
  Predicate<Point> ps;    // representation of a point set
  private PSet(Predicate<Point> ps) {this.ps = ps;}

  boolean in(Point p) {
    return ps.test(p);
  }

  static PSet disk(Point center, double radius) {
    return new PSet(point -> center.distance(point) <= radius);
  }

  PSet intersect(PSet set) {
    return new PSet(point -> ps.test(point) && set.ps.test(point));
  }

  static PSet rect(Point corner1, Point corner2) {
    return new PSet(point -> (corner1.x <= point.x && point.x <= corner2.x && corner1.y <= point.y && point.y <= corner2.y) 
													|| (corner2.x <= point.x && point.x <= corner1.x && corner1.y <= point.y && point.y <= corner2.y) 
													|| (corner2.x <= point.x && point.x <= corner1.x && corner2.y <= point.y && point.y <= corner1.y) 
													|| (corner1.x <= point.x && point.x <= corner2.x && corner2.y <= point.y && point.y <= corner1.y)); 
    //throw new Error();
  }

  PSet union(PSet set) {
    throw new Error();
  }

  PSet complement() {
    throw new Error();
  }

  PSet reflectx() { 
    throw new Error();
  }
}
  

class Example {
  public static void main(String argv[]) {
    double x = Double.parseDouble(argv[0]);
    double y = Double.parseDouble(argv[1]);
    Point p = new Point(x,y);
    PSet myregion = PSet.disk(new Point(0,0),2).intersect(PSet.disk(new Point(0,2),2));
    System.out.println(myregion.in(p));
  }
}
