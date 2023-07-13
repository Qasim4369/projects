var mysql = require("mysql");

var connection = mysql.createConnection({
    host: 'localhost',
    database: 'project',
    user: 'root',
    password: 'password'
});

module.exports = connection;