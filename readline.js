const fs = require('fs');
const readline = require('node:readline');
const { stdin: input, stdout: output } = require('node:process');

const rl = readline.createInterface({ input, output });

// rl.question('siapa namamu?: ', (answer) => {
//     console.log(`Thank you ${answer}`);
// rl.question(`dimana kamu tinggal ${answer}? :`, (answer2) => {
//     console.log(`oh jadi kamu tinggal di ${answer2}`);
//   rl.close();
// })});

const dirPath = './data';
if (!fs.existsSync(dirPath)) {
    fs.mkdirSync(dirPath);
}

const filePath = './data/contacts.json';
if (!fs.existsSync(filePath)) {
    fs.writeFileSync(filePath, '[]', 'utf-8');
}



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