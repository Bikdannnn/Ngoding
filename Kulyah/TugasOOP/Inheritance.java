public class Inheritance {
    public static void main(String[] args) {
       Kucing kucing1 = new Kucing("Milo", 2); 
        
        System.out.println("Nama kucing: " + kucing1.getNama());
        System.out.println("Usia kucing: " + kucing1.getUsia());

        kucing1.bersuara();

        System.out.println("\n----------------------------------");

        Anjing anjing1 = new Anjing("Rocky", 4);

        System.out.println("Nama anjing: " + anjing1.getNama());
        System.out.println("Usia anjing: " + anjing1.getUsia());

        anjing1.bersuara();
    }
}