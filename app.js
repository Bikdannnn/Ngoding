const express = require('express')
const app = express()
const port = 3000

// respond with "hello world" when a GET request is made to the homepage
app.get('/', (req, res) => {

    // res.json({
    //     nama : 'Wildan',
    //     email: 'wildan@gmal.com',
    //     noHp: '081234567890',
    // });

    //res.send('hello world')

    res.sendFile('./index.html', { root: __dirname });
});

app.get('/about', (req, res) => {
    res.sendFile('./about.html', { root: __dirname });
})

app.get('/contact', (req, res) => {
    res.sendFile('./contact.html', { root: __dirname });
})

app.use('/', (req, res) => {
    res.status(404);
    res.send('Halaman tidak ditemukan: 404');
});

app.listen(port, () => {
    console.log(`Server berjalan di port http://localhost: ${port}`)
})