const yargs = require('yargs/yargs');
const { hideBin } = require('yargs/helpers');
const { simpanContact, listContact, detailContact, deleteContact } = require('./contacts');



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
}
}).demandCommand()

//menampilkan semua nama & noHp contact
.command( {
    command: 'list',
    describe: 'Menampilkan semua contact',
    handler() {
        listContact();
    }
})


//menampilkan detail contact
.command( {
    command: 'detail',
    describe: 'Menampilkan detail contact berdasarkan nama',
    builder: {
        nama: {
            describe: 'Nama Lengkap',
            demandOption: true,
            type: 'string',
        }
    },

handler(argv) {
        detailContact(argv.nama);
    }
})

//menghapus contact berdasarkan nama
.command( {
    command: 'delete',
    describe: 'Menghapus contact berdasarkan nama',
    builder: {
        nama: {
            describe: 'Nama Lengkap',
            demandOption: true,
            type: 'string',
        }
    },
    handler(argv) {
        deleteContact(argv.nama);
    }
})

.parse();