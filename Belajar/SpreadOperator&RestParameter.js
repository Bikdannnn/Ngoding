// Spread Operator (...)
// Digunakan untuk "membuka" array atau object

// Contoh 1: Spread pada array
const arr1 = [1, 2, 3];
const arr2 = [4, 5, 6];
const gabung = [...arr1, ...arr2]; // [1, 2, 3, 4, 5, 6]
console.log(gabung);

// Contoh 2: Spread pada object
const obj1 = { nama: "Erik", umur: 20 };
const obj2 = { prodi: "IF", semester: 3 };
const gabungObj = { ...obj1, ...obj2 };
console.log(gabungObj);

// Rest Parameter (...)
// Digunakan untuk mengumpulkan argument menjadi array

// Contoh 1: Rest dalam function
function jumlah(...angka) {
    return angka.reduce((total, num) => total + num, 0);
}
console.log(jumlah(1, 2, 3, 4, 5)); // 15

// Contoh 2: Rest dengan parameter lain
function infoMhs(nama, umur, ...nilai) {
    console.log(`Nama: ${nama}`);
    console.log(`Umur: ${umur}`);
    console.log(`Nilai: ${nilai}`);
}
infoMhs("Erik", 20, 85, 90, 88);