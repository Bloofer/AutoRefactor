public class HelloWorld {

    public void f(Car myCar) {

      // print vehicle speed

      int speed;

      speed = myCar.getSpeed();

      System.out.println("Speed of the vehicle : " + speed);

    }

    public void g(Truck myTruck) {
    
      // print vehicle speed

      int speed;

      speed = myTruck.getSpeed();

      System.out.println("Speed of the vehicle : " + speed);
    
    }

    public static void main(String[] args) {

        HelloWorld hw = new HelloWorld();
        Car c = new Car();
        Truck t = new Truck();

        hw.f(c);
        hw.g(t);

    }

}
