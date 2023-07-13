const express = require('express');
const mysql = require('mysql');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

// MySQL database configuration
const dbConfig = {
  host: 'localhost',
  user: 'root',
  password: 'password',
  database: 'project'
};

// Create a connection pool
const pool = mysql.createPool(dbConfig);

// Set up EJS as the view engine
app.set('view engine', 'ejs');

// Middleware for parsing URL-encoded request bodies
app.use(bodyParser.urlencoded({ extended: true }));

// Route handler for the login page
app.get('/', (req, res) => {
  res.render('login');
});

// Route handler for processing the login form submission
app.post('/login', (req, res) => {
  const { username, password } = req.body;

  // Query the database to check if the username and password match
  pool.query(
    'SELECT * FROM User WHERE Username = ? AND Password = ?',
    [username, password],
    (error, results) => {
      if (error) {
        console.error('Error executing query:', error);
        res.render('login', { error: 'An error occurred. Please try again.' });
        return;
      }

      if (results.length > 0) {
        // User authenticated successfully
        res.render('dashboard', { username });
      } else {
        // Invalid username or password
        res.render('login', { error: 'Invalid username or password.' });
      }
    }
  );
});

// Start the server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
