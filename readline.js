const readline = require('node:readline');
const { stdin: input, stdout: output } = require('node:process');

const rl = readline.createInterface({ input, output });

rl.question('siapa namamu?: ', (answer) => {
rl.question(`dimana kamu tinggal ${answer}? :`, (answer2) => {
    console.log(`Thank you ${answer} yang tinggal di ${answer2}`)});

  rl.close();
});