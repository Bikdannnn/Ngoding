const chalk = require('chalk');
const fs = require('fs');
const validator = require('validator');

// const readline = require('node:readline');
// const { stdin: input, stdout: output } = require('node:process');

// const rl = readline.createInterface({ input, output });

const dirPath = './data';
if (!fs.existsSync(dirPath)) {
    fs.mkdirSync(dirPath);
}

const filePath = './data/contacts.json';
if (!fs.existsSync(filePath)) {
    fs.writeFileSync(filePath, '[]', 'utf-8');
}

const tulisPertanyaan = (pertanyaan) => {
    return new Promise((resolve, reject) => {
        rl.question(pertanyaan, (jawaban) => {
            resolve(jawaban);
        });
    });
};

const simpanContact = (nama, noHp, email) => {
    const contact = { nama, noHp, email };
        const file = fs.readFileSync(filePath, 'utf-8');
        const contacts = JSON.parse(file);

        //cek duplikar
        const duplicate = contacts.find((contact) => contact.nama === nama);
        if (duplicate) {
            console.log(chalk.red('Contact sudah terdaftar,') + chalk.bgRedBright('gunakan nama lain!'));
            return false;
        }

        //cek email
        const validEmail = validator.isEmail(email);
        if (email && !validEmail) {
            console.log(chalk.red('Email tidak valid!'));
            return false;
        }

        //cek noHp
        const validNoHp = validator.isMobilePhone(noHp, 'id-ID');
        if (!validNoHp) {
            console.log(chalk.red('Nomor Handphone tidak valid!'));
            return false;
        }

        contacts.push(contact);


        fs.writeFileSync(filePath, JSON.stringify(contacts));
        console.log('terimakasih sudah memasukkan data');
};


module.exports = { simpanContact }; 