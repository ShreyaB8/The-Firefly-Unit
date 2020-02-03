var express = require('express');
var router = express.Router();

/* GET adminlogin page. */
router.get('/', function(req, res, next) {
  res.render('adminlogin');
});

/* GET admin page. */
router.post('/admin', function(req, res) {
  res.render('admin');
});

/* GET machinehealth page. */
router.post('/machhealth', function(req, res) {
  res.render('machinehealth');
});

/* GET Userlist page. */
router.get('/userlist', function(req, res) {
  var db = req.db;
  var collection = db.get('userdata'); //make sure collection name and ejs file name is not the same
  collection.find({},{},function(e,docs){
      res.render('userlogs', {
          "userlogs" : docs
      });
  });
});


router.get('/machinelogs', function(req, res) {
  var db = req.db;
  var collection = db.get('machinelogs'); //make sure collection name and ejs file name is not the same
  collection.find({},{},function(e,docs){
      res.render('machinehealth', {
          "machinelogs" : docs
      });
  });
});

router.post('/addrfid', function(req, res) {

  // Set our internal DB variable
  var db = req.db;

  // Set our collection
  var collection = db.get('userdata');

  // Submit to the DB
  collection.insert({
      "User" : "RA1811004010166",
      "MachineUsed" : "1",
      "Time": "13:28",
      "Date": "1/2/20"

  }, function (err, doc) {
      if (err) {
          // If it failed, return error
          res.send("There was a problem adding the information to the database.");
      }
      else {
          // And forward to success page
          res.send('userlogs.ejs');
      }
  });

});
router.post('/addrfid2', function(req, res) {

  // Set our internal DB variable
  var db = req.db;
  
  // Set our collection
  var collection = db.get('userdata');

  // Submit to the DB
  collection.insert({
      "User" : "RA1911018010071",
      "MachineUsed" : "2",
      "Time": "13:10",
      "Date": "1/2/20"

  }, function (err, doc) {
      if (err) {
          // If it failed, return error
          res.send("There was a problem adding the information to the database.");
      }
      else {
          // And forward to success page
          res.send('userlogs.ejs');
      }
  });

});

router.post('/addrfid3', function(req, res) {

  // Set our internal DB variable
  var db = req.db;
  
  // Set our collection
  var collection = db.get('userdata');

  // Submit to the DB
  collection.insert({
      "User" : "RA1811004010166",
      "MachineUsed" : "2",
      "Time": "13:10",
      "Date": "1/2/20"

  }, function (err, doc) {
      if (err) {
          // If it failed, return error
          res.send("There was a problem adding the information to the database.");
      }
      else {
          // And forward to success page
          res.send('userlogs.ejs');
      }
  });

});


module.exports = router;
