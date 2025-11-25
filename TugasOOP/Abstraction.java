public class Abstraction {
    public static void main(String[] args) {
        
        Lingkaran lingkaranMerah = new Lingkaran("Merah", 7.0);

        lingkaranMerah.tampilWarna();
        System.out.println("Luas lingkaran: " + lingkaranMerah.hitungLuas());
    }
}