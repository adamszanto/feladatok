const write = (res) => {
    const status = res["status"];
    const token = res["token"];
    const output = document.getElementById('out');

    if (status == 200 && token == false) {
        sessionStorage.setItem("username", res["username"]);
        sessionStorage.setItem("password", res["password"]); 
        output.innerHTML = "Sikeresen bejelentkeztél";
    } else if (status == 200 && token == true) {
        localStorage.setItem("username", res["username"]);
        localStorage.setItem("password", res["password"]);
        output.innerHTML = "Sikeresen bejelentkeztél, adataid elmentve";
    } else {
        output.innerHTML = "A bejelentkezés sikertelen volt";
    }
}

const post = (data, url) => {
    const request = {
        method: 'POST',
        body: JSON.stringify(data),
        headers: {
            'Content-Type': 'application/json'
        }
    }

    fetch(url, request)
        .then(res => res.json())
        .then(res => write(res));
}

const send = () => {
    const url = `${window.location.href}api`;
    const user = document.getElementById('user').value;
    const pass = document.getElementById('password').value;
    const token = document.getElementById('token').checked;

    const body = {
        "username": user,
        "password": pass,
        "token": token
    }

    post(body, url)
}

const getData = (mode) => {
	if (mode == "session") {
		const username = sessionStorage.getItem("username");
		const password = sessionStorage.getItem("password");
		document.getElementById('userholder').innerHTML = `A felhasználóneved: ${username}`;
		document.getElementById('passholder').innerHTML = `A jelszavad: ${password}`;
		document.getElementById('mode').innerHTML = "Nincs mentve a böngészőbe az adataid"
	} else if (mode == "local") {
		const username = localStorage.getItem("username");
		const password = localStorage.getItem("password");
		document.getElementById('userholder').innerHTML = `A felhasználóneved: ${username}`;
		document.getElementById('passholder').innerHTML = `A jelszavad: ${password}`;
		document.getElementById('mode').innerHTML = "Adataid mentve"
	}
}
