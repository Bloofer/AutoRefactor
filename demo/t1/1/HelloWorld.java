public class refactored_HelloWorld {

    public void hw_printer() {
 
      System.out.println("Hello, World!");

      // do something
   
    }

    public int f() {

        int a = 0;

        for(int i=0; i<10; i++) {
            
            int log = i;
            
            System.out.println(i);
            System.out.println(i);
            System.out.println(i);
            System.out.println(i);
            System.out.println(i);

            hw_printer();

        }

        return a;

    }

    public float g() {

        float a = 1;

        for(int i=0; i<10; i++) {
            
            int log = i;
            
            System.out.println(i);
            System.out.println(i);
            System.out.println(i);
            System.out.println(i);
            System.out.println(i);

            hw_printer();

        }

        return a;

    }

    public static void main(String[] args) {

        HelloWorld hw = new HelloWorld();

        System.out.println("f() returns "+ f());
        System.out.println("g() returns "+ g());

    }

}
