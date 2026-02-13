const {tulisPertanyaan, simpanContact} = require('./contacts.js');
// const contact = require('./contacts.js');

const main = async () => {
    const nama = await tulisPertanyaan('siapa namamu?: ');
    const noHp = await tulisPertanyaan('berapa nomor teleponmu?: ');
    const email = await tulisPertanyaan('masukkan email kamu?: ');

    // const nama = await contact.tulisPertanyaan('siapa namamu?: ');
    // const noHp = await contact.tulisPertanyaan('berapa nomor teleponmu?: ');
    // const email = await contact.tulisPertanyaan('masukkan email kamu?: ');
    
    simpanContact(nama, noHp, email);
    //contact.simpanContact(nama, noHp, email);
};

main();

// const pertanyaan1 = () => {
//     return new Promise((resolve, reject) => {
//         rl.question('siapa namamu?: ', (nama) => {
//             resolve(nama);
//         });
//     });
// };

// const pertanyaan2 = () => {
//     return new Promise((resolve, reject) => {
//         rl.question('berapa nomor teleponmu?: ', (noHp) => {
//             resolve(noHp);
//         });
//     });
// };

// const pertanyaan3 = () => {
//     return new Promise((resolve, reject) => {
//         rl.question('masukkan email kamu?: ', (email) => {
//             resolve(email);
//         });
//     });
// };


// rl.question('siapa namamu?: ', (nama) => {
//     rl.question('berapa nomor teleponmu?: ', (noHp) => {
//         const contact = { nama, noHp };
//         const file = fs.readFileSync(filePath, 'utf-8');
//         const contacts = JSON.parse(file);
//         contacts.push(contact);
//         fs.writeFileSync(filePath, JSON.stringify(contacts));
//         console.log('terimakasih sudah memasukkan data');
//         rl.close();
//     });
// });