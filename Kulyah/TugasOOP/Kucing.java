public class Kucing extends Hewan {
    private String ras;

    public Kucing(String nama, int usia) {
        super(nama, usia);
        this.ras = ras;
    }

    public void bersuara() {
        System.out.println(getNama() + " mengeong...");
    }
}