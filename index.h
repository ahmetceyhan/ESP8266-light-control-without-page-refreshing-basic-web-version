const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>

<div>
Room1: 
  <button type="button" onclick="sendData(0,'1')">LED ON</button>
  <button type="button" onclick="sendData(1,'1')">LED OFF</button><BR>
</div>

<div>
Room2: 
  <button type="button" onclick="sendData(0,'2')">LED ON</button>
  <button type="button" onclick="sendData(1,'2')">LED OFF</button><BR>
</div>

<div>
  Room 1 light is : <span id="ADCValue1">-</span><br>
  Room 2 light is : <span id="ADCValue2">-</span><br>
</div>
<script>
function sendData(led,type) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED?LEDstate="+led+"&LEDtype="+type, true);
  xhttp.send();
}

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData('1');
  getData('2');
}, 2000); //2000mSeconds update rate

function getData(type) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("ADCValue"+type).innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readADC?LEDtype="+type, true);
  xhttp.send();
}
</script>
</body>
</html>
)=====";
