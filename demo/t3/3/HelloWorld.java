import java.util.Vector;
import javafx.util.Pair;

public class HelloWorld {

    Vector<Integer> intVec = new Vector<>(1);
    Vector<Float> floatVec = new Vector<>(1);
    Pair<Vector<Integer>, Vector<Float>> vecPair = new Pair<>(intVec, floatVec);

    public Vector<Integer> k(String s) { 
        System.out.println(s);
        return vecPair.getKey(); }
    public Vector<Float> h(String s) { 
        System.out.println(s);
        return vecPair.getValue(); }

    public String f() {

        System.out.println("hi");

        Vector<Integer> A = k("get vector");
        
        return "f";

    }

    public String g() {

        System.out.println("hi");

        Vector<Float> A = h("get vector");

        return "g";

    }

    public static void main(String[] args) {

        HelloWorld hw = new HelloWorld();

        System.out.println("f() returns "+hw.f());
        System.out.println("g() returns "+hw.g());

    }

}
