const yargs = require('yargs/yargs');
const { hideBin } = require('yargs/helpers');
const { demand } = require('yargs');
const { simpanContact } = require('./contacts');
const {simpanContact} = require('./contacts.js');



yargs(hideBin(process.argv))
    .command( {
    command: 'add',
    describe: 'Menambahkan Contact Baru',
    builder: {
        nama: {
            describe: 'Nama Lengkap',
            demandOption: true,
            type: 'string',
        },
        email: {
            describe: 'Email',
            demandOption: false,
            type: 'string',
        },
        noHp: {
            describe: 'Nomor Handphone',
            demandOption: true,
            type: 'string',
        },
    },
    handler(argv) {
        simpanContact(argv.nama, argv.noHp, argv.email);
}})

.parse();