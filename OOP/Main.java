class Hewan {
    public void berbunyi() {
        System.out.println("Hewannya bersuara");
    }
}

class Buaya extends Hewan {
    @Override
    public void berbunyi() {
        System.out.println("Kalau aku chat ada yang marah ga?");
    }
}

public class Main {
    public static void main(String[] args) {
        Hewan bersuara = new Buaya();
        bersuara.berbunyi();
    }
}