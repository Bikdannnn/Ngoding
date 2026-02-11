const readline = require('node:readline');
const { stdin: input, stdout: output } = require('node:process');

const rl = readline.createInterface({ input, output });

// rl.question('siapa namamu?: ', (answer) => {
//     console.log(`Thank you ${answer}`);
// rl.question(`dimana kamu tinggal ${answer}? :`, (answer2) => {
//     console.log(`oh jadi kamu tinggal di ${answer2}`);
//   rl.close();
// })});

rl.question('siapa namamu?: ', (nama) => {
    rl.question(`dimana kamu tinggal ${nama}? :`, (alamat) => {
        console.log(`Halo ${nama}, jadi kamu tinggal di ${alamat}`);
        rl.close();
    });
});