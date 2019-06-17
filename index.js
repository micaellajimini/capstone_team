const express = require('express')
const request = require('request')
const config = require('./config_cap');

const TARGET_URL = 'https://notify-api.line.me/api/notify'

var app = express();
var isdriver = 0;
var valid = 0;

//router name set needed
app.get('/alarm',function(req,res){
	console.log(req.query);
	if(req.query.sign == '0'){
		//send alarm
		request.post({
			url: TARGET_URL,
			headers: {
				'Authorization': `Bearer ${config.TOKEN}`
			},
			form: {
				//change message
				message: 'baby in the car!!!!'
			}
		}, (error, response, body) => {
			console.log(body)
		})	
	}
	if(req.query.sign == '1'){
		//send if driver exists
		res.send(String(isdriver));
	}
	if(req.query.sign == '2'){
		//send if check flag is valid
		res.send(String(valid));
	}
	if(req.query.sign == '3'){
		//i'm adult
		valid = 1;
	}
	
});

app.get('/driver',function(req,res){
		console.log("driver");
		console.log(req.query);
		if(req.query.sign == '0'){
			//driver exists
			isdriver = 0;			
		}
		else {
			isdriver = 1;
			valid = 0;
		}
});

app.listen(3000, function(){
//	console.log(config.TOKEN);
	console.log('listening on port 3000!');		
});


