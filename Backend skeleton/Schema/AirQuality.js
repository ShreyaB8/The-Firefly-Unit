var mongoose = require('mongoose');
var AirQualitySchema = new mongoose.Schema({
    co2: parseFloat(),
    methane: parseFloat(),
    co: parseFloat(),
    so2: parseFloat(),
    air_pressure: parseFloat()

});
mongoose.model("air", AirQualitySchema);