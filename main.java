
class Rekening {
    private String nomorRekening;
    private String namaPemilik;
    private Double saldo;

    public Rekening(String nomorRekening, String namaPemilik, Double saldo) {
        this.nomorRekening = nomorRekening;
        this.namaPemilik = namaPemilik;
        this.saldo = saldo;
    }

    public Rekening(String nomorRekening) {
        this(nomorRekening, "Wildan", 0.0);
    }

    public void setor(Double jumlah) {
        saldo += jumlah;
        System.out.println(nomorRekening + " saldo telah di tambahkan, saldo sekarang: " + saldo);
    }

    public void tarik(Double jumlah) {
        if (saldo >= jumlah) {
            saldo -= jumlah;
            System.out.println(nomorRekening + " saldo telah dikurang, saldo sekarang: " + saldo);
        } else {
            System.out.println("Saldo tidak cukup untuk melakukan penarikan.");
        }
    }

    public void tampilkanNamaPemilik() {
        System.out.println("Nama Pemilik: " + namaPemilik);
    }
}

public class main {
    public static void main(String[] args) {
        Rekening rekening1 = new Rekening("001");
        rekening1.setor(1000.0);
        rekening1.tarik(500.0);
        rekening1.tampilkanNamaPemilik();
    }
}