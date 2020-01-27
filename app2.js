var mqtt = require('mqtt');
var client  = mqtt.connect('mqtt://broker.hivemq.com');
var path = require("path");
var MongoClient = require('mongodb').MongoClient;
var mongoose = require("mongoose");
var mongo = require('mongodb').MongoClient;
var objectId = require('mongodb').ObjectID;
var assert = require('assert');
var express = require("express");
var app = express();
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "html");
app.use(express.static(path.join(__dirname, "public")));

mongoose.Promise = global.Promise;
var url = 'mongodb://localhost:27017/MachAuth';
mongoose.connect(url);

var bodyParser = require('body-parser');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));


var _id = "machauth";
var user_name = "machauth";
var authority_extend = "mazauth";

var AdminDetailSchema = new mongoose.Schema({
    _id: { type: objectId, auto: true},    
    user_name: { type: String, required: true},
    authority_extend: {type: String, require: true}
});

var userlogs = mongoose.model("userlogs", AdminDetailSchema);
/*
var myadmin = new userlogs(req.body);
myadmin.save()
    .then(item => {
        res.send("item saved to database");
    })
    .catch(err => {
        res.status(400).send("unable to save to database");
    });
*/
app.get('/get-data', function(req, res, next) {
    var resultArray = [];
    mongo.connect(url, function(err, db) {
      assert.equal(null, err);
      var cursor = db.collection('userlogs').find();
      cursor.forEach(function(doc, err) {
        assert.equal(null, err);
        resultArray.push(doc);
      }, function() {
        db.close();
        res.render('userlogs', {items: resultArray});
      });
    });
  });

  /*
 <form method="GET" action="/getdata">
        <input type="submit" value="get logs" class="btn" id="submit" />
        </form>
*/
var admin = mongoose.model("admin", AdminDetailSchema);
module.exports = admin;

app.get("/", (req, res) => {
    res.sendFile(__dirname + "/views/adminlogin.html");
});
app.post("/admin", (req, res) => {
    res.sendFile(__dirname + "/views/admin.html");
});

app.post("/user", (req, res) => {
    res.sendFile(__dirname + "/views/userlogs.html");
});
app.post("/machhealth", (req, res) => {
    res.sendFile(__dirname + "/views/machinehealth.html");
});



app.listen(3000, () => {
    console.log("Server listening on port " + 3000);
});