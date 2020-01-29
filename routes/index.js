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

module.exports = router;
