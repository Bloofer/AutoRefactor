public class HelloWorld {

    public int aa, bb;

    public HelloWorld(int a, int b){
      aa = a;
      bb = b;
      // do not
    }

    public int f(int flag) {

      assert flag >= 0 && flag <= 1;

      System.out.println("Hello, World!");

      // do something

      String s = new String();
      if(flag == 0) s = "i is 0";
      else if(flag == 1) s = "i is 1";
      
      String[] resourceHashValues = null;
      if(flag == 0) resourceHashValues = new String[] { "4f966289091f00667f68d2b2a8a676179d06ed77",
      "6d6f9b8b0fa664b92d368af85c9a08b8b05f661e", "971271aad01ded9cb244f0aa58d3448677f6530d",
      "d926d5ce461bc8c6174c1ded2497c8b88141a846", "025711b07d0af0b4ea1393b3d534314d4f338838" };

      int a;

      //System.out.println(resourceHashValues[4]);
      System.out.println(aa);
      System.out.println(bb);

      /* String[] resourceHashValues = new String[] { "4f966289091f00667f68d2b2a8a676179d06ed77",
				"6d6f9b8b0fa664b92d368af85c9a08b8b05f661e", "971271aad01ded9cb244f0aa58d3448677f6530d",
				"d926d5ce461bc8c6174c1ded2497c8b88141a846", "025711b07d0af0b4ea1393b3d534314d4f338838" }; */

      return 0;

    }

    public boolean a1(){
      return false;
    }
    public byte a2(){
      return 0;
    }
    public char a3(){
      return 0;
    }
    public short a4(){
      return 0;
    }
    public long a5(){
      return 0;
    }
    public float a6(){
      return 0;
    }
    public double a7(){
      return 0;
    }

    public int g() {
    
      System.out.println("Hello, World!");
       
      // do something
      
      return 1;
    
    }


    public static void main(String[] args) {

        HelloWorld hw = null;
        if(true) hw = new HelloWorld(3,4);

        System.out.println("f() returns "+hw.f(0));
        System.out.println("g() returns "+hw.g());


    }

}
