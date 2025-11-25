public class Encapsulation {
    public static void main(String[] args) {
        Hewan hewan1 = new Hewan("Kucing", 3);

        System.out.println("Nama awal: " + hewan1.getNama());
        System.out.println("Usia awal: " + hewan1.getUsia());

        System.out.println("----------------------------------");

        hewan1.setNama("Anjing");
        hewan1.setUsia(5);

        System.out.println("Nama baru: " + hewan1.getNama());
        System.out.println("Usia baru: " + hewan1.getUsia());
        
        System.out.println("----------------------------------");
        
        System.out.println("Mencoba mengubah usia menjadi -2 (invalid)...");
        hewan1.setUsia(-2);
        System.out.println("Usia sekarang: " + hewan1.getUsia()); 
    }
}