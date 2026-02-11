const fs = require('fs');
const readline = require('node:readline');
const { stdin: input, stdout: output } = require('node:process');

const rl = readline.createInterface({ input, output });

rl.question('siapa namamu?: ', (nama) => {
    rl.question(`Masukkan no HP anda: `, (nohp) => {
        const contact = { nama, nohp };
        const file = fs.readFileSync('data/contacts.json', 'utf-8');
        const contacts = JSON.parse(file);

        contacts.push(contact);

        fs.writeFileSync('data/contacts.json', JSON.stringify(contacts));
        console.log('Terima kasih sudah memasukkan data!');
        rl.close();
    });
});