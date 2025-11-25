//Pewarisan memungkinkan sebuah kelas (kelas anak/subkelas) untuk mewarisi properti dan metode dari kelas lain 
//(kelas induk/superkelas). Ini mempromosikan penggunaan kembali kode. Dalam Java, ini dilakukan dengan kata kunci extends.
//

// Kelas Induk (Superkelas)
class Hewan {
    String nama;

    public Hewan(String nama) {
        this.nama = nama;
    }

    public void makan() {
        System.out.println(nama + " sedang makan.");
    }
}

// Kelas Anak (Subkelas) - mewarisi dari Hewan
class Kucing extends Hewan {
    
    // Konstruktor kelas anak memanggil konstruktor kelas induk
    public Kucing(String nama) {
        super(nama); 
    }

    // Kucing memiliki metode tambahan
    public void mengeong() {
        System.out.println(nama + " mengeong: Meong!");
    }
}

// Contoh Penggunaan
public class inheritence {
public static void main(String[] args) {
Kucing leo = new Kucing("Leo");
         
// Menggunakan metode dari kelas induk (Hewan)
      leo.makan(); 
         
// Menggunakan metode dari kelas anak (Kucing)
       leo.mengeong(); 
     }
 }