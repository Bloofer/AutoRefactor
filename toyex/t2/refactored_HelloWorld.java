public class refactored_HelloWorld {

    public void doSomething1() {
    
      // do something 1
    
    }

    public void doSomething2() {
    
      // do something 2
    
    }

    public int f() {

      doSomething1();

      System.out.println("Hello, World!");

      int counter = 0;

      doSomething2();

      return 0;

    }

    public int g() {

      doSomething1();

      System.out.println("Hello, People!");
       
      int counter = 10;

      doSomething2();

      return 1;
    
    }


    public static void main(String[] args) {

        refactored_HelloWorld hw = new refactored_HelloWorld();

        System.out.println("f() returns "+hw.f());
        System.out.println("g() returns "+hw.g());


    }

}
