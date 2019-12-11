var mqtt = require('mqtt');
var client  = mqtt.connect('mqtt://localhost:1883');
var path = require('path');
var MongoClient = require('mongodb').MongoClient;
var mongoose = require("mongoose");
var express = require("express");
var app = express();

// mongodb://shreya:123@host1:27017/SRC

mongoose.Promise = global.Promise;
mongoose.connect("mongodb://localhost:27017/SRC");

var bodyParser = require('body-parser');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

var CSVconverter = require('convert-csv-to-array');

//var  air = require('./Schema/AirQuality');
//var  wallq = require('./Schema/WallQuality');
var co2 = "src";
var co = "src";
var methane = "src";
var so2 = "src";
var air_pressure ="src";
var TDS = "src";
var Turbity = "src";
var Pf = "src";
var Orp = "src";
var conductivity = "src";


var AirQualitySchema = new mongoose.Schema({
    co2: parseFloat(),
    methane: parseFloat(),
    co: parseFloat(),
    so2: parseFloat(),
    air_pressure: parseFloat()

});

var WaterQualitySchema = new mongoose.Schema({
    TDS: parseFloat(),
    Turbity: parseFloat(),
    Pf: parseFloat(),
    Orp: parseFloat(),
    conductivity: parseFloat()

});

var air = mongoose.model("air", AirQualitySchema);
var water = mongoose.model("water", WaterQualitySchema);

client.on('connect', function () {
    client.subscribe('message', function (err) {
        if (!err) {
            client.publish('src', 'Server Online');
        }
    })
});

client.on('message', function (topic, message) {
    // message is Buffer
    console.log("triggered");
    client.publish('src', message);
    handleMessage(topic, message);
});

function handleMessage(topic, message) {

    var msg = message.toString();
    console.log('message: ' + msg);
    const arrayofObjects = CSVconverter.convertCSVToArray(msg, {
        separator: ',', // use the separator you use in your csv (e.g. '\t', ',', ';' ...)
    });
    co2 = arrayofObjects[0][0];
    co = arrayofObjects[0][1];
    methane = arrayofObjects[0][2];
    so2 = arrayofObjects[0][3];
    air_pressure = arrayofObjects[0][4];
    TDS = arrayofObjects[0][5];
    Turbity = arrayofObjects[0][6];
    Pf =arrayofObjects[0][7];
    Orp = arrayofObjects[0][8];
    conductivity = arrayofObjects[0][9];

    console.log('co: ' + co);
    console.log('co2:  ' + co2);
    console.log('methane:  ' + methane);
    console.log('so2:  ' + so2);
    console.log('air pressure:  ' + air_pressure);
    console.log('TDS:  ' + TDS);
    console.log('Turbity:  ' + Turbity);
    console.log('Pf:  ' + Pf);
    console.log('Orp:  ' + Orp);
    console.log('conductivity:  ' + conductivity);

    MongoClient.connect("mongodb://localhost:27017/SRC", function(err, db) {
        if (err) throw err;
        var dbo = db.db("SRC");
        var myair = {
            "co2": co2,
            "co": co,
            "methane": methane,
            "so2": so2,
            "air pressure": air_pressure

        };
        var mywater ={
            "TDS": TDS,
            "Tubity": Turbity,
            "Pf": Pf,
            "Orp": Orp,
            "conductivity": conductivity
        };
        dbo.collection("airs").insertOne(myair, function(err, res) {
            if (err) throw err;
            console.log("1 document for airs inserted");
            db.close();
        });
        dbo.collection("waters").insertOne(mywater, function(err, res) {
            if (err) throw err;
            console.log("1 document for waters inserted");
            db.close();
        });

    });
}


app.get("/", (req, res) => {
    res.sendFile(__dirname + "/frontend/testpage1.html");
});

app.post("/datatest1", (req, res) => {
    var myair = new air(req.body);
    myair.save()
        .then(item => {
            res.send("item saved to database");
        })
        .catch(err => {
            res.status(400).send("unable to save to database");
        });
    var mywater = new water(req.body);
    mywater.save()
        .then(item => {
            res.send("item saved to database");
        })
        .catch(err => {
            res.status(400).send("unable to save to database");
        });
});


app.listen(3000, () => {
    console.log("Server listening on port " + 3000);
});