const fs = require('fs');

const data = fs.writeFile('data/text.txt', 'Hello World', (e) => {
    console/log(e)})

console.log(data)