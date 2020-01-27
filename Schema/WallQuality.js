var mongoose = require('mongoose');
var WallQualitySchema = new mongoose.Schema({
    TDS: parseFloat(),
    Turbity: parseFloat(),
    Pf: parseFloat(),
    Orp: parseFloat(),
    conductivity: parseFloat()

});
mongoose.model("wallq", WallQualitySchema);