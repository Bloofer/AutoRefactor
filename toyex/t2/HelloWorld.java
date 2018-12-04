import java.util.Vector;

public class HelloWorld {


  public Vector<Integer> hi1(int x) { 
    System.out.println("Integer!");
    return null; }
  public Vector<Float> hi2(int x) { 
    System.out.println("Float!");
    return null; }
  public float hi3(int x) { return x * 2; }
  public float hi4(int x) { return x * 4; }
  public float hi5(int x, int y) { return x + y; }
  public float hi6(int x, int y) { return x * y; }

  ///// 바뀌기 전
  public int f() {
    System.out.println("hihihi");
    Vector<Integer> A = hi1(10);
    return 10;
  }
  public int g() {
    System.out.println("hihihi");
    Vector<Float> A = hi2(10);
    return 10;
  }

  ////// 바뀐 후
  public <T> Vector<T> fg(java.util.function.Function<Integer, Vector<T>> lambda) { // extract 된 것
    System.out.println("hihihi");
    Vector<T> A = lambda.apply(10);
    return A;
  }
  public int f2() { // f가 이렇게 바뀌어야 함.
    Vector<Integer> A = fg(x -> hi1(x));
    return 10;
  }
  public int g2() {
    Vector<Float> A = fg(x -> hi2(x));
    return 10;
  }

  //// ----------------------- 좀 더 간단한 케이스
  ///// 바뀌기 전
  public float ff() {
    float x;
    x = hi3(10); //System.out.println("hihihihihihi");
    return x;
  }
  public float gg() {
    float x;
    x = hi4(10); //System.out.println("hihihihihihi");
    return x;
  }
  ////// 바뀐 후
  public float ffgg(java.util.function.Function<Integer, Float> lambda) {
    System.out.println("hihihihihihi");
    float x = lambda.apply(10);
    return x;
  }
  public float ffgg2(java.util.function.Function<Integer, Float> lambda) {
    System.out.println("hihihihihihi");
    float x = lambda.apply(10);
    return x;
  }
  public float ff2() {
    float x = ffgg(a -> hi3(a));
    return x;
  }
  public float gg2() {
    float x = ffgg(a -> hi4(a));
    return x;
  }

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

  // T3 Multi-line patch case
  // 함수의 타입이 같고 다른 부분은 함수 호출 이름. hi3과 hi4 인경우.

  public float foo() {
    System.out.println("hihihihihihi");
    float x = hi3(10);
    float y = hi3(20);
    float z = hi3(30);
    return x + y + z;
  }
  public float goo() {
    System.out.println("hihihihihihi");
    float x = hi4(10);
    float y = hi4(20);
    float z = hi4(30);
    return x + y + z;
  }

  ////// 바뀐 후
  public float foogoo(java.util.function.Function<Integer, Float> lambda) { 
    System.out.println("hihihihihihi");
    float x = lambda.apply(10);
    float y = lambda.apply(20);
    float z = lambda.apply(30);
    return x + y + z;
  }

  public float ff3() {
    System.out.println("hihihihihihi");
    float x = hi3(10);
    return x;
  }
  public float gg3() {
    System.out.println("hihihihihihi");
    float x = hi4(10);
    return x;
  }

  // T3 Multi-line patch case - 인자 2개인 함수 패치
  // 함수의 타입이 같고 다른 부분은 함수 호출 이름. hi3과 hi4 인경우.

  public float foo2() {
    System.out.println("hihihihihihi");
    float x = hi5(1, 2);
    float y = hi5(3, 4);
    float z = hi5(5, 6);
    return x + y + z;
  }
  public float goo2() {
    System.out.println("hihihihihihi");
    float x = hi6(1, 2);
    float y = hi6(3, 4);
    float z = hi6(5, 6);
    return x + y + z;
  }

  ////// 바뀐 후
  public float foo2goo2(java.util.function.BiFunction<Integer, Integer, Float> lambda) { 
    System.out.println("hihihihihihi");
    float x = lambda.apply(1, 2);
    float y = lambda.apply(3, 4);
    float z = lambda.apply(5, 6);
    return x + y + z;
  }

  public float hi7(int x) { return 10; }
  public float hi8(int x) { return 20; }

  public float foo3() {
    System.out.print("hihihihihihi");
    float x = hi7(1);
    float y = hi7(1);
    float z = hi7(1);
    return x + y + z;
  }
  public float goo3() {
    System.out.print("hihihihihihi");
    float x = hi8(1);
    float y = hi8(1);
    float z = hi8(1);
    return x + y + z;
  }

  ////// 바뀐 후
  public float foo3goo3(java.util.function.Function<Integer, Float> lambda) { 
    System.out.print("hihihihihihi");
    float x = lambda.apply(1);
    float y = lambda.apply(1);
    float z = lambda.apply(1);
    return x + y + z;
  }

  public float foogoo3(int flag) { 
    System.out.print("hihihihihihi");
    float x = 0;
    float y = 0;
    float z = 0;
    if(flag == 0){
      x = hi7(1);
      y = hi7(1);
      z = hi7(1);
    } else if (flag == 1){
      x = hi8(1);
      y = hi8(1);
      z = hi8(1);
    }
    return x + y + z;
  }

  // T3 타입 패치

  ///// 바뀌기 전 TODO:
  public int fo() {
    System.out.println("hihihi");
    Vector<Integer> A = hi1(10);
    return 10;
  }
  public int go() {
    System.out.println("hihihi");
    Vector<Float> A = hi2(10);
    return 10;
  }

  ////// 바뀐 후
  public <T> int fogo(java.util.function.Function<Integer, Vector<T>> lambda) { // extract 된 것
    System.out.println("hihihi");
    Vector<T> A = lambda.apply(10);
    return 10;
  }

  

  // ePrint 실제 예제 타입 toyex TODO:
  public String epf() {
    System.out.print("hihihi");
    Vector<Integer> A = hi1(10);
    System.out.print("function f!");
    return "fffff";
  }

  public String epg() {
    System.out.print("hihihi");
    Vector<Float> A = hi2(10);
    System.out.print("function f!");
    return "ggggg";
  }

  ////// 바뀐 후
  public <T> String epfepg(java.util.function.Function<Integer, Vector<T>> fptr, String s) { // extract 된 것
    System.out.print("hihihi");
    Vector<T> A = fptr.apply(10);
    System.out.print("function f!");
    return s;
  }

  public String epfg(int flag) {
    System.out.print("hihihi");
    Vector A = null;
    if(flag == 0) A = hi1(10);
    else if(flag == 1) A = hi2(10);

    System.out.print("function f!");
    if(flag == 0) return "fffff";
    else if(flag == 1) return "ggggg";
    return "";
  }

    public static void main(String[] args) {

      float startTime = System.nanoTime();
        
        for(int i=0; i<1000; i++){

          HelloWorld hw = new HelloWorld();

          //float t1 = hw.foogoo3(0);
          //float t2 = hw.foogoo3(0);

          //String tmp1 = hw.epfg(0);
          //String tmp2 = hw.epfg(1);
          //System.out.println("epf() returns "+hw.epfepg((a) -> hw.hi1(a), "function f!"));
          //System.out.println("epg() returns "+hw.epfepg((a) -> hw.hi2(a), "function g!"));
          //String tmp3 = hw.epfepg((a) -> hw.hi1(a), "function f!");
          //String tmp4 = hw.epfepg((a) -> hw.hi2(a), "function g!");

          float t1 = hw.foo3goo3((a) -> hw.hi7(a));
          float t2 = hw.foo3goo3((a) -> hw.hi8(a));

        }

      float endTime = System.nanoTime();
      System.out.println(endTime - startTime);

    }

}
