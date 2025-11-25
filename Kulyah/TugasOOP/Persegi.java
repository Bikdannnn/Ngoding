public class Persegi extends Bentuk {
    private double sisi;

    public Persegi(String warna, double sisi) {
        super(warna);
        this.sisi = sisi;
    }

    @Override
    public double hitungLuas() {
        return sisi * sisi;
    }
}