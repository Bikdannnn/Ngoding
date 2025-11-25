//Polimorfisme berarti "banyak bentuk". Dalam OOP, ini memungkinkan objek untuk mengambil banyak bentuk.
//Dua bentuk utamanya adalah:

//Override (Polimorfisme saat Runtime): Mendefinisikan ulang metode kelas induk di kelas anak.

//Overload (Polimorfisme saat Compile-time): Mendefinisikan beberapa metode dalam kelas yang sama 
//dengan nama yang sama tetapi dengan daftar parameter yang berbeda.

//A. Overriding (Runtime Polymorphism)

class Bentuk1 {
    public void gambar() {
        System.out.println("Menggambar sebuah bentuk.");
    }
}

class Lingkaran extends Bentuk1 {
    // Override: Mendefinisikan ulang metode gambar() dari kelas induk
    @Override 
    public void gambar() {
        System.out.println("Menggambar sebuah lingkaran.");
    }
}

class Persegi extends Bentuk1 {
    // Override: Mendefinisikan ulang metode gambar() dari kelas induk
    @Override
    public void gambar() {
        System.out.println("Menggambar sebuah persegi.");
    }
}

// Contoh Penggunaan
// public class TesPolimorfisme {
//     public static void main(String[] args) {
//         Bentuk b1 = new Bentuk();      // Objek Bentuk
//         Bentuk b2 = new Lingkaran();   // Objek Lingkaran diperlakukan sebagai Bentuk
//         Bentuk b3 = new Persegi();     // Objek Persegi diperlakukan sebagai Bentuk
//
//         b1.gambar(); // Output: Menggambar sebuah bentuk.
//         b2.gambar(); // Output: Menggambar sebuah lingkaran. (Metode kelas anak dipanggil!)
//         b3.gambar(); // Output: Menggambar sebuah persegi. (Metode kelas anak dipanggil!)
//     }
// }


//B. Overloading (Compile-time Polymorphism)

class Kalkulator {
    // Metode penjumlahan dengan dua integer
    public int jumlah(int a, int b) {
        return a + b;
    }

    // Overload: Metode penjumlahan dengan tiga integer (daftar parameter berbeda)
    public int jumlah(int a, int b, int c) {
        return a + b + c;
    }

    // Overload: Metode penjumlahan dengan dua double (tipe parameter berbeda)
    public double jumlah(double a, double b) {
        return a + b;
    }
}

// Contoh Penggunaan
// public class TesOverloading {
//     public static void main(String[] args) {
//         Kalkulator k = new Kalkulator();
//         System.out.println("Dua int: " + k.jumlah(5, 10));        // Memanggil metode pertama
//         System.out.println("Tiga int: " + k.jumlah(1, 2, 3));     // Memanggil metode kedua
//         System.out.println("Dua double: " + k.jumlah(2.5, 3.5));  // Memanggil metode ketiga
//     }
// }