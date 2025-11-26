function init() {
    let nama = 'Sandhika'; // Local variable
    function tampilNama() { // Inner function (closure)
        console.log(nama); // Mengakses variabel dari parent scope
    }
    return tampilNama;
}
const panggilNama = init();
panggilNama(); // Masih bisa akses 'Sandhika' meski init() sudah selesai.

