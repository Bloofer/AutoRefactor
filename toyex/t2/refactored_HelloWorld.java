public class refactored_HelloWorld {

    public void hw_printer() {
 
      System.out.println("Hello, World!");

      // do something
   
    }

    public int f() {

      hw_printer();

      return 0;

    }

    public int g() {
    
      hw_printer();

      return 1;
    
    }


    public static void main(String[] args) {

        refactored_HelloWorld hw = new refactored_HelloWorld();

        System.out.println("f() returns "+hw.f());
        System.out.println("g() returns "+hw.g());


    }

}
