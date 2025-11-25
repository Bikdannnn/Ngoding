public class Anjing extends Hewan {
    private String jenis;

    public Anjing(String nama, int usia) {
        super(nama, usia);
        this.jenis = jenis;
    }

    public void bersuara() {
        System.out.println(getNama() + " menggonggong...");
    }
}