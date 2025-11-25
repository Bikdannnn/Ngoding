public class Polimorfisme {
    public static void main(String[] args) {
        Bentuk lingkaran = new Lingkaran("Merah", 5.0);
        Bentuk persegi = new Persegi("Biru", 4.0);
        
        System.out.println("Luas lingkaran: " + lingkaran.hitungLuas());
        System.out.println("Luas persegi: " + persegi.hitungLuas());
        
        System.out.println("----------------------------------");

        Hewan kucing = new Kucing("Milo", 2);
        Hewan anjing = new Anjing("Rocky", 3);

        kucing.bersuara();
        anjing.bersuara();
    }
}