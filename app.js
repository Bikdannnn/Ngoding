const express = require('express')
const app = express()
const port = 3000

// respond with "hello world" when a GET request is made to the homepage
app.get('/', (req, res) => {
  res.send('hello world')
})

app.get('/about', (req, res) => {
    res.send('Halaman About')
})

app.get('/contact', (req, res) => {
    res.send('Halaman Contact')
})

app.use('/', (req, res) => {
    res.status(404);
    res.send('Halaman tidak ditemukan: 404');
});

app.listen(port, () => {
    console.log(`Server berjalan di port http://localhost: ${port}`)
})