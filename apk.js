const validator = require('validator');
const chalk = require('chalk');

console.log(chalk.red('Hello world varian merah'));
console.log(chalk.blue('Hello') + chalk.black.italic(' World') + chalk.red('!'));

console.log(`
CPU: ${chalk.red('90%')}
RAM: ${chalk.green('40%')}
DISK: ${chalk.yellow('70%')}
`);
