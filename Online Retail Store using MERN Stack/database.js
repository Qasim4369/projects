const sqlite3 = require('sqlite3').verbose();

// Create a new database connection
const db = new sqlite3.Database(':memory:'); // In-memory database for demonstration purposes

// Create a "products" table in the database
db.serialize(() => {
  db.run(`
    CREATE TABLE IF NOT EXISTS products (
      id INTEGER PRIMARY KEY AUTOINCREMENT,
      name TEXT,
      price REAL,
      image TEXT
    )
  `);

  // Insert sample products into the table
  db.run(`INSERT INTO products (name, price, image) VALUES ('Product 1', 10.99, '/images/product1.jpg')`);
  db.run(`INSERT INTO products (name, price, image) VALUES ('Product 2', 19.99, '/images/product2.jpg')`);
});

module.exports = db;
