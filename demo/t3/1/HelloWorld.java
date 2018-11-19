import java.util.Vector;

public class HelloWorld {

    public float k(int x) { return x * 2; }
    public float h(int x) { return x * 4; }

    public float f() {

        float x;

        x = k(10);

        return x;

    }

    public float g() {

        float x;

        x = h(10);

        return x;

    }

    public static void main(String[] args) {

        HelloWorld hw = new HelloWorld();

        System.out.println("f() returns "+hw.f());
        System.out.println("g() returns "+hw.g());
        
    }

}
