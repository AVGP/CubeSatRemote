
/**
 * Module dependencies.
 */

var express = require('express')
  , routes = require('./routes')
  , mysql = require('mysql');

var app = module.exports = express.createServer();

// Configuration

app.configure(function(){
  app.set('views', __dirname + '/views');
  app.set('view engine', 'jade');
  app.use(express.bodyParser());
  app.use(express.methodOverride());
  app.use(app.router);
  app.use(express.static(__dirname + '/public'));
});

app.configure('development', function(){
  app.use(express.errorHandler({ dumpExceptions: true, showStack: true }));
});

app.configure('production', function(){
  app.use(express.errorHandler());
});


var client = mysql.createClient({
    user: process.env.MYSQL_USER ? process.env.MYSQL_USER : 'root',
    password: process.env.MYSQL_PASSWORD ? process.env.MYSQL_PASSWORD : 'sommer',
    database: process.env.MYSQL_DATABASE ? process.env.MYSQL_DATABASE : 'cubesat',
    port: process.env.MYSQL_PORT ? process.env.MYSQL_PORT : 3306,
    host: process.env.MYSQL_HOST ? process.env.MYSQL_HOST : 'localhost'
});


// Routes
app.get('/', routes.index);

app.get('/latestpackages', function(req, res){
    client.query(
        'select * from packet ORDER BY timestamp DESC LIMIT 10',
        function(err, results, fields){
            if(err){
                console.log('an error occurred' + err);
            }
            res.send(results);
        }
    );
});

app.get('/package/:id', function(req, res){
    client.query(
        'select * from packet where id = ?',
        [req.params.id],
        function(err, results, fields){
            if(err){
                console.log('an error occurred' + err);
            }
            res.send(results);
        }
        );
});




app.listen(3000, function(){
  console.log("Express server listening on port %d in %s mode", app.address().port, app.settings.env);
});
