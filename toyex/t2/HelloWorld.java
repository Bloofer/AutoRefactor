public class HelloWorld {

    public int f() {

      System.out.println("Hello, World!");

      // do something

      return 0;

    }

    public int g() {
    
      System.out.println("Hello, World!");
       
      // do something
      
      return 1;
    
    }

    

    public static void main(String[] args) {

        HelloWorld hw = new HelloWorld();

        System.out.println("f() returns "+hw.f());
        System.out.println("g() returns "+hw.g());


    }

}
