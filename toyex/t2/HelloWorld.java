import java.util.Vector;

public class HelloWorld {


  public Vector<Integer> hi1(int x) { return null; }
  public Vector<Float> hi2(int x) { return null; }
  public float hi3(int x) { return x * 2; }
  public float hi4(int x) { return x * 4; }

  ///// 바뀌기 전
  public int f() {
    System.out.println("hihihi");
    Vector<Integer> A = hi1(10);
    return A.size();
  }
  public int g() {
    System.out.println("hihihi");
    Vector<Float> A = hi2(10);
    return A.size();
  }

  ////// 바뀐 후
  public <T> Vector<T> fg(java.util.function.Function<Integer, Vector<T>> lambda) { // extract 된 것
    System.out.println("hihihi");
    Vector<T> A = lambda.apply(10);
    return A;
  }
  public int f2() { // f가 이렇게 바뀌어야 함.
    Vector<Integer> A = fg(x -> hi1(x));
    return A.size();
  }
  public int g2() {
    Vector<Float> A = fg(x -> hi2(x));
    return A.size();
  }

  //// ----------------------- 좀 더 간단한 케이스
  ///// 바뀌기 전
  public float ff() {
    System.out.println("hihihihihihi");
    float x = hi3(10);
    return x;
  }
  public float gg() {
    System.out.println("hihihihihihi");
    float x = hi4(10);
    return x;
  }
  ////// 바뀐 후
  /* public float ffgg(java.util.function.Function<Integer, Float> lambda) {
    System.out.println("hihihihihihi");
    float x = lambda.apply(10);
    return x;
  }
  public float ff2() {
    float x = ffgg((a) -> hi3(a));
    return x;
  }
  public float gg2() {
    float x = ffgg((a) -> hi4(a));
    return x;
  } */

  //// ------------------------ 생성자가 있는 케이스
  ///// 바뀌기 전
  public int fff() {
    System.out.println("hihihi");
    Vector<Integer> A = new Vector<Integer>();
    return A.size();
  }
  public int ggg() {
    System.out.println("hihihi");
    Vector<Float> A = new Vector<Float>();
    return A.size();
  }

  ////// 바뀐 후
  public <T> Vector<T> fffggg() { // extract 된 것
    System.out.println("hihihi");
    Vector<T> A = new Vector<T>();
    return A;
  }
  public int fff2() { // f가 이렇게 바뀌어야 함.
    Vector<Integer> A = fffggg();
    return A.size();
  }
  public int ggg2() {
    Vector<Float> A = fffggg();
    return A.size();
  }


    public static void main(String[] args) {

        HelloWorld hw = new HelloWorld();
        char c = 0;
        long[] l = null;
        l = new long[] {123, 456, 789};

        System.out.println("f() returns "+hw.f());
        System.out.println("g() returns "+hw.g());


    }

}
