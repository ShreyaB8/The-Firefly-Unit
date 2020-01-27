var TeleSignSDK = require('telesignsdk');

//const customerId = "8E38A80C-2D31-4A41-B271-293B4AE2EC69";
var client = new TeleSignSDK("8E38A80C-2D31-4A41-B271-293B4AE2EC69" ,"zzHmYK++tblqW+UIUQUcJdDUEh0goVz2CGlQ8nib8H3XYrZg1ctUiNbhQku1Ef6ihdp3vPnRDkYE00iIZ/j57A==");

//const apiKey = "zzHmYK++tblqW+UIUQUcJdDUEh0goVz2CGlQ8nib8H3XYrZg1ctUiNbhQku1Ef6ihdp3vPnRDkYE00iIZ/j57A==";
//const rest_endpoint = "https://rest-api.telesign.com";
//const timeout = 10*1000; // 10 secs

/*const client = new TeleSignSDK( customerId,
    apiKey,
    rest_endpoint,
    timeout // optional
    // userAgent
);

const phoneNumber = "917550267844";
const message = "You're scheduled for a dentist appointment at 2:30PM.";
const messageType = "ARN";

console.log("## MessagingClient.message ##");

function messageCallback(error, responseBody) {
    if (error === null) {
        console.log(`Messaging response for messaging phone number: ${phoneNumber}` +
            ` => code: ${responseBody['status']['code']}` +
            `, description: ${responseBody['status']['description']}`);
    } else {
        console.error("Unable to send message. " + error);
    }
}
*/
//client.sms.message(messageCallback, phoneNumber, message, messageType);
callback = function(err, resBody){
    if(err){
        console.error(err);
    }
    else{
        console.log("success!!!");
        console.log(resBody);
    }
}
client.sms.message(callback, "917550267844", "yololololol", "MKT");