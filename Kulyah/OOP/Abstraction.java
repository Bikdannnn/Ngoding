//Abstraksi adalah proses menyembunyikan detail implementasi dan hanya menampilkan fungsionalitas penting kepada pengguna. 
//Ini dicapai menggunakan kelas abstrak (abstract class) atau antarmuka (interface).

//Menggunakan Kelas Abstrak.  
//Kelas abstrak tidak dapat di-instantiate (dibuat objeknya) dan dapat berisi metode abstrak 
//(metode tanpa badan, yang harus diimplementasikan oleh subkelas non-abstrak).

// Kelas Abstrak
abstract class Pegawai {
    String nama;

    public Pegawai(String nama) {
        this.nama = nama;
    }

    // Metode abstrak: harus diimplementasikan oleh kelas anak
    public abstract double hitungGaji();

    // Metode konkret: memiliki implementasi
    public void tampilkanNama() {
        System.out.println("Nama Pegawai: " + nama);
    }
}

// Kelas Anak Konkret
class PegawaiTetap extends Pegawai {
    double gajiBulanan;

    public PegawaiTetap(String nama, double gajiBulanan) {
        super(nama);
        this.gajiBulanan = gajiBulanan;
    }

    // Implementasi metode abstrak dari kelas induk
    @Override
    public double hitungGaji() {
        return gajiBulanan;
    }
}

//Contoh Penggunaan
public class Abstraction {
    public static void main(String[] args) {

// Pegawai p = new Pegawai("Ali"); 
// Akan error karena Pegawai adalah abstrak
         
         PegawaiTetap pt = new PegawaiTetap("Ali", 5000000);
         pt.tampilkanNama();
         // Pengguna hanya perlu tahu cara memanggil hitungGaji(), 
         // tanpa tahu rumus spesifik di dalamnya
         System.out.println("Gaji: " + pt.hitungGaji()); 
     }
 }