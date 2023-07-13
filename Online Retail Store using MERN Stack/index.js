const express = require('express');
const app = express();
const port = 3000;
const path = require('path');

// Set up middleware
app.use(express.urlencoded({ extended: true }));
app.use(express.static('public'));

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));
// Database integration
const db = require('./database');

// Home route
app.get('/', (req, res) => {
  // Retrieve products from the database
  db.all('SELECT * FROM products', (err, products) => {
    if (err) {
      console.error(err);
      return res.sendStatus(500);
    }
    res.render('home', { products });
  });
});

// Set up routes
app.get('/', (req, res) => {
  const sql = 'SELECT * FROM products';
  db.all(sql, (err, rows) => {
    if (err) {
      console.error(err);
      return res.sendStatus(500);
    }
    res.render('home', { products: rows });
  });
});

app.get('/product/:id', (req, res) => {
  const productId = req.params.id;
  const sql = 'SELECT * FROM products WHERE id = ?';
  db.get(sql, [productId], (err, row) => {
    if (err) {
      console.error(err);
      return res.sendStatus(500);
    }
    if (!row) {
      return res.sendStatus(404);
    }
    res.render('product', { product: row });
  });
});

app.post('/cart/add', (req, res) => {
  const productId = req.body.productId;
  const sql = 'SELECT * FROM products WHERE id = ?';
  db.get(sql, [productId], (err, row) => {
    if (err) {
      console.error(err);
      return res.sendStatus(500);
    }
    if (!row) {
      return res.sendStatus(404);
    }
    req.session.cart = req.session.cart || [];
    req.session.cart.push(row);
    res.redirect('/cart');
  });
});

app.get('/cart', (req, res) => {
  const cartItems = req.session.cart || [];
  res.render('cart', { cartItems });
});

app.get('/checkout', (req, res) => {
  const cartItems = req.session.cart || [];
  res.render('checkout', { cartItems });
});

app.post('/checkout', (req, res) => {
  // Process the checkout
  req.session.cart = [];
  res.render('order-confirmation');
});

// Start the server
app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});