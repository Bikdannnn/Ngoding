public class Lingkaran extends Bentuk {
    private double radius;

    public Lingkaran(String warna, double radius) {
        super(warna);
        this.radius = radius;
    }

    @Override
    public double hitungLuas() {
        return Math.PI * radius * radius;
    }
}