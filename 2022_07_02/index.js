//Node Modules
const express = require('express');
const bodyParser = require('body-parser');
const app = express();
app.use(bodyParser.json());
app.use(express.static('public'));

//Port config
const port = 4000;

//Get Call
app.get('/api', (req, res) => {
    res.setHeader('Content-Type', 'application/json');
    res.send(JSON.stringify({
        "response": "ok"
    }));
});

//Post Call
app.post('/api', (req, res) => {
    const data = req.body;
    const user = data["username"];
    const pass = data["password"];
    const token = data["token"];

    if (user == "adam" && pass == "szanto") {
        res.setHeader('Content-Type', 'application/json');
        res.send(JSON.stringify({
            "status": 200,
            "username": user,
            "password": pass,
            "token": token
        }));
    } else {
        res.setHeader('Content-Type', 'application/json');
        res.send(JSON.stringify({
            "status": 404
        }));
    }
    console.log(data);
});

//Server Listener
app.listen(port, () => {
    console.log(`Server started on port ${port}...`);
});
