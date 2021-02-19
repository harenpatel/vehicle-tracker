const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>
.card{
    max-width: 800px;
     min-height: 250px;
     background: #02b875;
     padding: 30px;
     box-sizing: border-box;
     color: #FFF;
     margin:20px;
     box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
</style>
<body>

<div class="card">
  <h4>Vehicle Tracker</h4><br>
  <h1>GPS Data:<span id="ADCValue">0</span></h1><br>
  <h2>Longitude:<span id="Longitude">0</span></h2><br>
  <h2>Latitude:<span id="Latitude">0</span></h2><br>
  <br><h4>Created By: Haren Patel</h4>
</div>

<script>

setInterval(function() {
  // Call a function repetatively with 5 Second interval
  getData();
}, 5000); //5000mS update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  var xLat = new XMLHttpRequest();
  var xLong = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("ADCValue").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();

  xLong.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Longitude").innerHTML = this.responseText;
    }
  };
  xLong.open("GET", "Longitude", true);
  xLong.send();

  xLat.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Latitude").innerHTML = this.responseText;
    }
  };
  xLat.open("GET", "Latitude", true);
  XLat.send();
}

</script>
</body>
</html>
)=====";
