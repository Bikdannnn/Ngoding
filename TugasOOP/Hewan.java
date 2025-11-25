public class Hewan {
    private String nama;
    private int usia;

    public Hewan(String nama, int usia) {
        this.nama = nama;
        this.usia = usia;
    }

    public String getNama() {
        return nama;
    }

    public int getUsia() {
        return usia;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setUsia(int usia) {
        if (usia > 0) {
            this.usia = usia;
        }
    }

    void bersuara() {
        throw new UnsupportedOperationException("Not supported yet.");
    }

}