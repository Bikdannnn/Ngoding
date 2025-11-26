// Destructuring Array
const [a, b, ...sisanya] = [1, 2, 3, 4, 5]; // a=1, b=2, sisanya=[3,4,5]

// Destructuring Function Arguments (Sangat berguna!)
function cetakMhs({ nama, umur }) {
    return `Halo ${nama}, umurmu ${umur}`;
}
const mhs1 = { nama: "Erik", umur: 20, prodi: "IF" };
console.log(cetakMhs(mhs1));


//contoh forin dan forof dengan destructuring

// for...in (iterasi property/key object)
const obj = { nama: "Erik", umur: 20, prodi: "IF" };
for (let key in obj) {
    console.log(`${key}: ${obj[key]}`);
}

// for...of (iterasi nilai array)
const arr = [1, 2, 3, 4, 5];
for (let nilai of arr) {
    console.log(nilai);
}

// for dengan if condition
for (let i = 0; i < 10; i++) {
    if (i % 2 === 0) {
        console.log(`${i} adalah bilangan genap`);
    }
}
