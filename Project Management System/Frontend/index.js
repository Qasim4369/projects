const express = require('express');
const mysql = require('mysql');
const app = express();

// Create a MySQL connection
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: 'password',
  database: 'project',
});

// Connect to the database
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to the database: ', err);
    return;
  }
  console.log('Connected to the database');
});

// Set up routes
app.get('/', (req, res) => {
    res.sendFile(__dirname + '/views/index.html');
});

// Route to retrieve projects
app.get('/projects', (req, res) => {
  const query = 'SELECT * FROM Project';

  connection.query(query, (error, results) => {
    if (error) {
      console.error('Error retrieving projects: ', error);
      res.status(500).json({ error: 'Failed to retrieve projects' });
      return;
    }

    res.json(results);
  });
});

// Route to retrieve issues
app.get('/issues', (req, res) => {
  const query = 'SELECT * FROM Issue';

  connection.query(query, (error, results) => {
    if (error) {
      console.error('Error retrieving issues: ', error);
      res.status(500).json({ error: 'Failed to retrieve issues' });
      return;
    }

    res.json(results);
  });

  
});

app.get('/users', (req, res) => {
    const query = 'SELECT * FROM User';
  
    connection.query(query, (error, results) => {
      if (error) {
        console.error('Error retrieving users: ', error);
        res.status(500).json({ error: 'Failed to retrieve users' });
        return;
      }
  
      res.json(results);
    });
  
    
});
  

// Add more routes for other options (boards, reports, user management) if needed

// Start the server
const port = 3000; // Change to the desired port number
app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});
