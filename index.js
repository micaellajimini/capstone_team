const express = require('express')
const request = require('request')
const config = require('./config_cap');

const TARGET_URL = 'https://notify-api.line.me/api/notify'

var app = express();

//router name set needed
app.get('/alarm',function(req,res){
	request.post({
		url: TARGET_URL,
		headers: {
			'Authorization': `Bearer ${config.TOKEN}`
		},
		form: {
			//change message
			message: 'messaging_test - jimin'
		}
	}, (error, response, body) => {
		console.log(body)
	})	
});

app.listen(8000, function(){
//	console.log(config.TOKEN);
	console.log('listening on port 8000!');		
});


