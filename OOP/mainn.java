public class mainn {

    static class Produk {
        protected String nama;
        protected double harga;

        public Produk(String nama, double harga) {
            this.nama = nama;
            this.harga = harga;
        }

        public void tampilkanInfo() {
            System.out.println("----------------------------------------");
            System.out.println("Nama Produk  : " + nama);
            System.out.println("Harga Satuan : Rp " + String.format("%,.2f", harga));
        }

        public double hitungTotalHarga(int jumlah) {
            return harga * jumlah;
        }
    }

    static class Makanan extends Produk {
        private String tanggalKadaluarsa;

        public Makanan(String nama, double harga, String tanggalKadaluarsa) {
            super(nama, harga);
            this.tanggalKadaluarsa = tanggalKadaluarsa;
        }

        @Override
        public void tampilkanInfo() {
            super.tampilkanInfo();
            System.out.println("Jenis        : Makanan");
            System.out.println("Tgl. Kadaluarsa: " + tanggalKadaluarsa);
        }
    }

    static class Elektronik extends Produk {
        private int garansi; 

        public Elektronik(String nama, double harga, int garansi) {
            super(nama, harga);
            this.garansi = garansi;
        }

        @Override
        public void tampilkanInfo() {
            super.tampilkanInfo();
            System.out.println("Jenis        : Elektronik");
            System.out.println("Garansi      : " + garansi + " bulan");
        }
    }

    public static void main(String[] args) {
        Produk[] daftarProduk = new Produk[3];

        daftarProduk[0] = new Makanan("Roti Tawar", 15500.0, "15/11/2025");
        daftarProduk[1] = new Elektronik("Kipas Angin", 250000.0, 12);
        daftarProduk[2] = new Makanan("Susu Kotak", 5000.0, "01/01/2026");

        int[] jumlahBeli = {2, 1, 10};

        System.out.println("DAFTAR PEMBELIAN TOKO SINAR JAYA");

        for (int i = 0; i < daftarProduk.length; i++) {
            Produk produkSaatIni = daftarProduk[i];
            int jumlah = jumlahBeli[i];
            
            produkSaatIni.tampilkanInfo(); 
            
            double totalHarga = produkSaatIni.hitungTotalHarga(jumlah);
            
            System.out.println("Jumlah Beli  : " + jumlah);
            System.out.println("Total Harga  : Rp " + String.format("%,.2f", totalHarga));
        }
    }
}