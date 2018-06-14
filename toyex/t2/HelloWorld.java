public class HelloWorld {

    public int f() {

      // do something 1

      System.out.println("Hello, World!");

      int counter = 0;

      // do something 2

      return 0;

    }

    public int g() {
    
      // do something 1

      System.out.println("Hello, People!");
       
      int counter = 10;

      // do something 2

      return 1;
    
    }


    public static void main(String[] args) {

        HelloWorld hw = new HelloWorld();

        System.out.println("f() returns "+hw.f());
        System.out.println("g() returns "+hw.g());


    }

}
