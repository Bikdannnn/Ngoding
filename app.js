const fs = require('fs');

// const data = fs.writeFile('data/text.txt', 'Hello World', (e) => {
//     console/log(e)})

// console.log(data)

fs.readFile('data/text.txt', 'utf-8', (err, data) => {
    if (err) {
        console.log(err);
    } else {
        console.log(data);
    }
})