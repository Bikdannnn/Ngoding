//Enkapsulasi adalah pengikatan data (variabel) dan metode (fungsi) yang beroperasi pada data tersebut 
//menjadi satu unit (kelas), serta menyembunyikan detail implementasi dari luar. Ini biasanya dicapai dengan 
//membuat variabel menjadi private dan menyediakan metode publik (public) getter (untuk membaca) dan setter (untuk memodifikasi).

class Mahasiswa {
    // Variabel (data) dibuat private
    private String nama;
    private final String nim;

    // Konstruktor
    public Mahasiswa(String nama, String nim) {
        this.nama = nama;
        this.nim = nim;
    }

    // Setter (Metode publik untuk memodifikasi data secara terkontrol)
    public void setNama(String namaBaru) {
        // Logika kontrol bisa ditambahkan di sini, misalnya validasi
        this.nama = namaBaru;
    }

    // Getter (Metode publik untuk mengakses/membaca data)
    public String getNama() {
        return nama;
    }

    public String getNim() {
        return nim;
    }
}

// Contoh Penggunaan
public class encapsulation {
    public static void main(String[] args) {
        Mahasiswa mhs = new Mahasiswa("Budi", "12345");
         
        // Mengakses data melalui getter
         System.out.println("Nama awal: " + mhs.getNama()); 

        // Memodifikasi data melalui setter
         mhs.setNama("Budi Santoso");
         System.out.println("Nama baru: " + mhs.getNama());
         
// Akses langsung ke mhs.nama akan gagal karena 'nama' private.
     }
 }