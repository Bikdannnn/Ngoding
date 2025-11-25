public abstract class Bentuk {
    private String warna;

    public Bentuk(String warna) {
        this.warna = warna;
    }

    public abstract double hitungLuas();

    public void tampilWarna() {
        System.out.println("Warna: " + warna);
    }
}