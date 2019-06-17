const String MAIN_page = R"=(
<!DOCTYPE html>
<html>

<head>
    <meta charset='utf-8'>
    <title>Administrador RFID</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
</head>

<body>
    <div class="container">
        <header>
            <p>Administracion RFID NFC </p>
        </header>

        <nav>
            <div id="navbar" class="tab">
                <p id="titulo">Administracion RFID NFC </p>
                <button class="tablinks" onclick="cambiarTab(event, 'agregar')" id="defaultOpen">Agregar</button>
                <button class="tablinks" onclick="cambiarTab(event, 'Paris')">Borrar</button>
                <button class="tablinks" onclick="cambiarTab(event, 'Tokyo')">Listar</button>
                <div class="menu" ontouchend="myFunction()">
                    <div></div>
                    <div></div>
                    <div></div>
                </div>
            </div>
        </nav>

        <main>
            <div id="agregar" class="tabcontent">
                <h2 style="margin-top: 0%">Agregar nueva llave</h2>
                <label>Acerque la llave a la cerradura</label>
                <br><br>
                <label>UID de nueva llave: </label>
                <br>
                <input id="uid" type="text" readonly placeholder="No se detecta llave cerca">
                <br><br>
                <button type="button" onclick="agregar()" class="button">Agregar</button>
                <br><br><br>
                <label id="estado"></laebl>
            </div>

            <div id="Paris" class="tabcontent">
                <h3>Paris</h3>
                <p>Paris is the capital of France.</p>
            </div>

            <div id="Tokyo" class="tabcontent">
                <h3>Tokyo</h3>
                <p>Tokyo is the capital of Japan.</p>
            </div>
        </main>

        <footer>
            <p>&copy; Universidad de El Salvador Micro Programacion Copyright 2019.</p>
        </footer>
    </div>

    <script>
        setInterval(() => getUID(), 1000);
        function agregar() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("estado").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "agregar", true);
            xhttp.send();
        }

        function getUID() {
            console.log("hola");
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("uid").value = this.responseText;
                    console.log(this.responseText);
                }
            };
            xhttp.open("GET", "getuid", true);
            xhttp.send();
        }



        function cambiarTab(evt, cityName) {
            var i, tabcontent, tablinks;
            tabcontent = document.getElementsByClassName("tabcontent");

            for (const tab of tabcontent) {
                tab.style.display = "none";

            }

            tablinks = document.getElementsByClassName("tablinks");
            for (i = 0; i < tablinks.length; i++) {
                tablinks[i].className = tablinks[i].className.replace(" active", "");
            }
            document.getElementById(cityName).style.display = "block";
            evt.currentTarget.className += " active";
        }
        document.getElementById("defaultOpen").click();

        function myFunction() {
            var x = document.getElementById("navbar");
            if (x.className === "tab") {
                x.className += " responsive";
            } else {
                x.className = "tab";
            }
        }
    </script>

    <style>
        .menu div {
            width: 30px;
            height: 4px;
            background-color: black;
            margin: 6px 0;
        }
        
        .menu {
            display: none;
            margin: 4%;
        }
        
        #titulo {
            display: none;
        }
        
        body {
            margin: 0%;
            font-family: Arial, Helvetica, sans-serif;
        }
        
        .container {
            display: grid;
            grid-template-areas: "header header header" "nav content content" "nav footer footer";
            grid-template-columns: 2fr 10fr 1fr;
            grid-template-rows: 1fr 10fr 1fr;
            width: 100%;
            height: 100vh;
        }
        
        header {
            grid-area: header;
            background-color: #000000;
            color: rgb(248, 246, 239);
            font-size: 125%;
            text-align: center;
        }
        
        nav {
            grid-area: nav;
            background-color: #2b2a2a;
        }
        
        main {
            grid-area: content;
            background-color: #e1e2e1;
            align-content: center;
        }
        
        footer {
            grid-area: footer;
            color: rgb(248, 246, 239);
            background-color: #1c1b1b;
            text-align: center;
        }
        
        .tabcontent {
            background-color: #f5f5f6;
            width: 80%;
            height: 70%;
            margin: auto;
            margin-top: 5%;
            padding: 2%;
            text-align: center;
            -webkit-animation: fadeEffect 1s;
            animation: fadeEffect 1s;
        }

        .tabcontent input[type=text] {
            width: 50%;
            padding: 1% 3%;
            margin: 1% 0;
            box-sizing: border-box;
            border: 2px solid #29434e;
            border-radius: 4px;
            font-size: 100%;
            text-align: center;
        }

        .button {
            background-color: #819ca9; 
            color: black; 
            border: 2px solid #29434e;
            padding: 2% 5%;
            text-align: center;
             text-decoration: none;
            display: inline-block;
             font-size: 100%;
             margin: 0.5% ;
             transition-duration: 0.4s;
             cursor: pointer;
             user-select: none;
        }

        .tab button {
            display: block;
            background-color: inherit;
            color: rgb(248, 246, 239);
            padding: 22px 16px;
            width: 100%;
            border: none;
            outline: none;
            text-align: left;
            cursor: pointer;
            transition: 0.3s;
            font-size: 125%;
        }

        /* Change background color of buttons on hover */
        
        .tab button:hover {
            background-color: #607d8b;
            color: black;
        }
        /* Create an active/current "tab button" class */
        
        .tab button.active {
            background-color: #8eacbb;
            color: black;
        }
        
        @media only screen and (max-width: 400px) {
            .container {
                display: grid;
                grid-template-areas: " nav " " content " " footer ";
                grid-template-columns: 1fr;
                grid-template-rows: 1fr 10fr 1fr;
                width: 100%;
                height: 100vh;
            }
            header {
                display: none;
            }
        }
        
        @media only screen and (max-width: 400px) {
            .tab button:not(:first-child) {
                display: none;
            }
            .tab .menu {
                float: right;
                display: block;
                position: absolute;
                right: 0;
                top: 0;
            }
            .tab.responsive {
                position: relative;
            }
            .tab.responsive button {
                float: none;
                display: block;
                text-align: left;
            }
            #titulo {
                color: rgb(248, 246, 239);
                text-align: center;
                font-size: 120%;
                float: none;
                display: block;
                width: 75%;
                margin: 0%;
                padding: 5%;
            }
        }

        @media only screen and (max-width: 400px){
            .tabcontent input[type=text] {
                width: 80%;
             }
             .button:active {
                 background-color: #29434e;
                 color: white;
                 box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24),0 17px 50px 0 rgba(0,0,0,0.19);
             }
        }
        
        @media only screen and (min-width: 401px){
            .button:hover {
             background-color: #29434e;
             color: white;
             box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24),0 17px 50px 0 rgba(0,0,0,0.19);
            }
        }

        @-webkit-keyframes fadeEffect {
            from {
                opacity: 0;
            }
            to {
                opacity: 1;
            }
        }
        
        @keyframes fadeEffect {
            from {
                opacity: 0;
            }
            to {
                opacity: 1;
            }
        }
    </style>
</body>

</html>
)=";
