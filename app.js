var createError = require('http-errors');
var mqtt = require('mqtt');
var client  = mqtt.connect('mqtt://broker.hivemq.com');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

//modules for nexmo
const bodyParser = require('body-parser');
const ejs = require('ejs');
const Nexmo = require('nexmo');
const socketio = require('socket.io');

//mongodb connection
var monk = require('monk');
var db = monk('mongodb://localhost:27017/MachAuth');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

//Nexmo settings
const nexmo = new Nexmo({
  apiKey: 'ea2571bc',
  apiSecret: 'DsFW5oXYOc7dkXVc'
}, { debug: true });
const from = 917248683115
const to = 919871492867



// Make our db accessible to our router
//this absolutely has to be above the app.user('/')
app.use(function(req,res,next){
  req.db = db;
  next();
});

client.on('connect', () => {
  var message = '0';
  // client.subscribe('garage/close')
   // Inform controllers that garage is connected
   console.log("triggered");
   client.subscribe('siic/humi', message);
   console.log(message);
 })


//for humidity sensor text alert
client.on('message', (topic, message) => {
  var text =  'Alert!!!!! Humidity Crossed the threshold'
  if(topic === 'siic/humi') {
    console.log('received message %s %s', topic, message)
    nexmo.message.sendSms(from, to, text, (err, responseData) => {
      if (err) {
          console.log(err);
      } else {
          if(responseData.messages[0]['status'] === "0") {
              console.log("Message sent successfully.");
          } else {
              console.log(`Message failed with error: ${responseData.messages[0]['error-text']}`);
          }
      }
  })
   
  }
})
//for temperature sensor text alert
client.on('message', (topic, message) => {
  var text =     'Alert!!!!! Temperature crossed the threshold '
  if(topic === 'siic/temp') {
    console.log('received message %s %s', topic, message)
    nexmo.message.sendSms(from, to, text, (err, responseData) => {
      if (err) {
          console.log(err);
      } else {
          if(responseData.messages[0]['status'] === "0") {
              console.log("Message sent successfully.");
          } else {
              console.log(`Message failed with error: ${responseData.messages[0]['error-text']}`);
          }
      }
  })

  }
})

//for vibration sensor text alert
client.on('message', (topic, message) => {
  var text =    'Alert!!!!! Jerks detected!!! '
  if(topic === 'siic/vibr') {
    console.log('received message %s %s', topic, message)
 
    nexmo.message.sendSms(from, to, text, (err, responseData) => {
      if (err) {
          console.log(err);
      } else {
          if(responseData.messages[0]['status'] === "0") {
              console.log("Message sent successfully.");
          } else {
              console.log(`Message failed with error: ${responseData.messages[0]['error-text']}`);
          }
      }
  })
  }
})

app.use('/', indexRouter);
app.use('/users', usersRouter);



// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
