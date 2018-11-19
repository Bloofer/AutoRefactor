public class refactored_HelloWorld {

    public void hw_printer() {
 
      System.out.println("Hello, World!");

      // do something
   
    }

    public int f() {

        int a;
        
        a = 0;

        hw_printer()

        System.out.println("Method f()!");

        return a;

    }

    public int g() {

        int a;
        
        a = 1;

        hw_printer()

        System.out.println("Method g()!");

        return a;

    }

    public static void main(String[] args) {

        HelloWorld hw = new HelloWorld();

        System.out.println("f() returns "+ f());
        System.out.println("g() returns "+ g());

    }

}
