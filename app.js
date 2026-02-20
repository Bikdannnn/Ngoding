const express = require('express')
const expressLayouts = require('express-ejs-layouts');
const app = express()
const port = 3000

app.set('view engine', 'ejs');
app.use(expressLayouts);

app.use(express.static('public'));

app.use((req, res, next) => {
    console.log('Time:', Date.now());
    next();
});

app.get('/', (req, res) => {

    const mahasiswa = [
        { nama: 'Wildan', 
          email: 'wildan@gmail.com',
        },
        { nama: 'anis', 
          email: 'anis@gmail.com',
        },
        { nama: 'gibran', 
          email: 'gibran@gmail.com',
        },
        { nama: 'raka', 
          email: 'raka@gmail.com',
        }
    ];
    
    res.render('index', { 
        nama: 'Wildan Humaidi', 
        title: 'Home Page',
        mahasiswa,
        layout : 'Layout/main-layout'
    });
});

app.get('/about', (req, res) => {
    res.render('about', { 
        title: 'About Page', 
        layout : 'Layout/main-layout' });
})

app.get('/contact', (req, res) => {
    res.render('contact', { 
        title: 'Contact Page', 
        layout : 'Layout/main-layout' });
})

app.get('/product/:id', (req, res) => {
    res.send(`Product ID: ${req.params.id} <br> Category: ${req.query.category}`);
})

app.use('/', (req, res) => {
    res.status(404);
    res.send('Halaman tidak ditemukan: 404');
});

app.listen(port, () => {
    console.log(`Server berjalan di port http://localhost: ${port}`)
})