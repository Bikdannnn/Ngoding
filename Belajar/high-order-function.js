//1. Konsep Utama HOF

//A. Menerima Fungsi sebagai Argumen

// Fungsi biasa (Callback)
function sapaPagi(nama) {
  console.log("Selamat Pagi, " + nama);
}

function sapaMalam(nama) {
  console.log("Selamat Malam, " + nama);
}

// Higher Order Function (menerima fungsi lain lewat parameter 'aksi')
function prosesSapaan(nama, aksi) {
  console.log("Memulai proses...");
  aksi(nama); // Menjalankan fungsi yang dikirim
}

// Penggunaan
prosesSapaan("Budi", sapaPagi); // Output: Selamat Pagi, Budi
prosesSapaan("Siti", sapaMalam); // Output: Selamat Malam, Siti


//B. Mengembalikan Fungsi (Function Factory)

// HOF yang mengembalikan fungsi
function buatPengali(faktor) {
  return function (angka) {
    return angka * faktor;
  };
}

const kaliDua = buatPengali(2);
const kaliLima = buatPengali(5);

console.log(kaliDua(10)); // Output: 20
console.log(kaliLima(10)); // Output: 50

//2. HOF yang Sering Digunakan (Built-in)

//A. Map

const angka = [1, 2, 3, 4];
// 'map' adalah HOF, fungsi di dalamnya adalah callback
const kuadrat = angka.map(x => x * x); 

console.log(kuadrat);
// Hasil: [1, 4, 9, 16]

//B. Filter
const angkaa = [1, 2, 3, 4, 5, 6];
// Menyaring hanya angka genap
const genap = angkaa.filter(x => x % 2 === 0);

console.log(genap);
// Hasil: [2, 4, 6]

//C. Reduce

const angkaaa = [1, 2, 3, 4];
// Menjumlahkan seluruh angka
const total = angkaaa.reduce((akumulator, nilaiSaatIni) => akumulator + nilaiSaatIni, 0);

console.log(total);
// Hasil: 10 (1+2+3+4)

