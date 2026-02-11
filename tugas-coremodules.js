const fs = require('fs');
const readline = require('node:readline');
const { stdin: input, stdout: output } = require('node:process');

const rl = readline.createInterface({ input, output });

rl.question('siapa namamu?: ', (nama) => {
    rl.question(`Masukkan no HP anda: `, (nohp) => {
        const contact = { nama, nohp };
        const constacts = JSON.stringify(contact, null, 2);
        fs.writeFile('data/contacts.json', constacts, (err) => {
            if (err) throw err;
            console.log('Data berhasil disimpan!');
            rl.close();
        });
    });
});