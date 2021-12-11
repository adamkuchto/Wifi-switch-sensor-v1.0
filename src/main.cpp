#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "define.c"
#include "connect.c"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
sensor_t sensor;

float TempReader()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  event.temperature;
      // Serial.print(F("Temperature: "));
      Serial.print(event.temperature);
      // Serial.println(F("°C"));
  delayMS = sensor.min_delay / 1000;
  return event.temperature;
}
float HumReader()
{
  sensors_event_t event;
  dht.humidity().getEvent(&event);
  event.relative_humidity;
      // Serial.print(F("Temperature: "));
      Serial.print(event.relative_humidity);
      // Serial.println(F("°C"));
      delayMS = sensor.min_delay / 1000;
  return event.relative_humidity;
}
void webpage(WiFiClient client, float temp, float hum)
{
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");
 client.println("<head>");
 client.println("<title> Czika's House  </title>");
 client.println("<meta charset='UTF-8'>");
 client.println("");

 client.println("<style>");
 client.println("");
 client.println("   body {");
 client.println("   font-size:100%;");
 client.println("   color:white;");
 client.println("   background-color: #111111;");
 client.println("   margin:10px;");
 client.println("   } ");
 client.println("  ");

 client.println("  #page {");
 client.println("width:100%;");
 client.println("  position: relative;");
 client.println("  min-height: 99vh;");
 client.println("}");
 client.println("");

 client.println("#content {");
 client.println("  padding-bottom: 2.5rem;    /* Footer height */");
 client.println("}");
 client.println("");
 client.println("   ");

 client.println("   h1 {color: white;}");
 client.println("   p { text-align:center; }");
 client.println("");

 client.println("   table {");
 client.println("   width=80%;");
 client.println("margin: 40px 40px 40px 40px;");
 client.println("   }");

 client.println("   tr{");
 client.println("border: 1px solid black;");
 client.println("padding: 20px 20px 20px 20px;");
 client.println("   }");

 client.println("   td{");
 client.println("padding: 10px 10px 10px 10px;");
 client.println("  text-align: center;");
 client.println("   }");

 client.println("   .wrapper {");
 client.println("display: grid;");
 client.println("/*grid-template-columns: 1fr 1fr 1fr;*/");
 client.println("");
 client.println("margin: 60px 20px 60px 20px;");
 client.println("}");

 client.println(".box {");
 client.println("  border-radius: 10px;");
 client.println("  border: 0.5px solid white;");
 client.println("  font-size: 150%;");
 client.println("  /*height: 120px;*/");
 client.println("  margin: 5px 5px 5px 5px;");
 client.println("}");
 client.println("");

 client.println(".button {");
 client.println("  background-color: #111111;");
 client.println("  border: none;");
 client.println("  color: white;");
 client.println("  padding: 16px 32px;");
 client.println("  text-align: center;");
 client.println("  text-decoration: none;");
 client.println("  display: inline-block;");
 client.println("  font-size: 16px;");
 client.println("  margin: 4px 2px;");
 client.println("  transition-duration: 0.4s;");
 client.println("  cursor: pointer;");
 client.println("  border-radius: 12px;");
 client.println("}");
 client.println("");

 client.println(".on {");
 client.println("  color: white; ");
 client.println("  border: 2px solid #3AAA35;");
 client.println("}");
 client.println("");

 client.println(".on:hover {");
 client.println("  background-color: #3AAA35;");
 client.println("  color: white;");
 client.println("}");
 client.println("");

 client.println(".off { ");
 client.println("  color: white; ");
 client.println("  border: 2px solid #f44336;");
 client.println("}");
 client.println("");

 client.println(".off:hover {");
 client.println("  background-color: #f44336;");
 client.println("  color: white;");
 client.println("}");
 client.println("");

 client.println("    .sensor {");
 client.println("  background-color: #230cf2;");
 client.println("  border: none;");
 client.println("  color: #f20c27;");
 client.println("  padding: 16px 32px;");
 client.println("  text-align: center;");
 client.println("  text-decoration: none;");
 client.println("  display: inline-block;");
 client.println("  font-size: 22px;");
 client.println("  margin: 4px 2px;");
 client.println("  transition-duration: 0.4s;");
 client.println("  cursor: pointer;");
 client.println("  border-radius: 2px;");
 client.println("}");
 client.println("");

 client.println(".status {");
 client.println("  color: white; ");
 client.println("  border: 5px solid #3AAA35;");
 client.println("  border-radius: 12px;");
 client.println("}");
 client.println("");
 client.println("");

 client.println("@media (min-width: 1050px){ /*screen and*/");
 client.println("  .wrapper {");
 client.println("grid-template-columns: repeat(2, 1fr);");
 client.println("  }");
 client.println("  ");

 client.println("@media (min-width: 1500px){");
 client.println("  .wrapper {");
 client.println("grid-template-columns: repeat(3, 1fr);");
 client.println("  }");
 client.println("}");
 client.println("");
 client.println(" </style>");

 client.println("");
 client.println("");
 client.println("</head>");
 client.println("<body> ");

 client.println("<div id='page'>");
 client.println("<div id='content'>");
 client.println("<hr/>* * * version 1.0 <hr>");
 client.println("<h1><center> Czika's house </center></h1>");


 client.println("<br><br><div id='m' class='box'><center>");
 client.println("<hr/><center>Switches</center><hr>");
 client.println("  <table><tr><td>Living room<br>");
 client.println("   <a href='/on1' class='button on'> Light On </a><br>");
 client.println("  <a href='/off1' class='button off'> Light Off </a></td><td>Bedroom<br>");
 client.println("   <a href='/on2' class='button on'> Light On </a><br>");
 client.println("  <a href='/off2' class='button off'> Light Off </a></td><td>Bathroom<br>");
 client.println("   <a href='/on3' class='button on'> Light On </a><br>");
 client.println("  <a href='/off3' class='button off'> Light Off </a></td><td>Kitchen<br>");
 client.println("   <a href='/on4' class='button on'> Light On </a><br>");
 client.println("  <a href='/off4' class='button off'> Light Off </a></td></tr>");
 client.println("   </a></td></tr>");
 client.println("</table></center></div>");
 
 client.println("<div id='m' class='box'>");
 client.println("<hr/><center>Sensors</center><hr>");
 client.println("  <center><table><tr><td>Temp");
 client.println("  <input id='senM1' class='sensor'  value='" + String(temp) + "' readonly></input></a></td>");
 client.println("  <td>Humidity");
 client.println("  <input id='senM2' class='sensor'  value='" + String(hum) + "' readonly></input></a></td></tr>");
 client.println("   </a></td></tr>");
 client.println("</table></center></div>");

 
 client.println("</div><footer><div></a><p></div></footer></div></body></html>");
}
void rocker()
{
            if (header.indexOf("GET /on1") >= 0) 
            {
              Serial.println("Salon light on");
              output1 = "on";
              digitalWrite(OutPut1, HIGH);
            } 
            else if (header.indexOf("GET /off1") >= 0) 
            {
              Serial.println("Salon light off");
              output1 = "off";
              digitalWrite(OutPut1, LOW);
            } 
            else if (header.indexOf("GET /on2") >= 0) 
            {
              Serial.println("Bedroom light on");
              output2 = "on";
              digitalWrite(OutPut2, HIGH);
            } 
            else if (header.indexOf("GET /off2") >= 0) 
            {
              Serial.println("Bedroom light off");
              output2 = "off";
              digitalWrite(OutPut2, LOW);
            }
            else if (header.indexOf("GET /on3") >= 0) 
            {
              Serial.println("Bathroom light on");
              output3 = "on";
              digitalWrite(OutPut3, HIGH);
            } 
            else if (header.indexOf("GET /off3") >= 0) 
            {
              Serial.println("Bathroom light off");
              output3 = "off";
              digitalWrite(OutPut3, LOW);
            }
            else if (header.indexOf("GET /on4") >= 0) 
            {
              Serial.println("Bathroom light on");
              output3 = "on";
              digitalWrite(OutPut4, HIGH);
            } 
            else if (header.indexOf("GET /off4") >= 0) 
            {
              Serial.println("Bathroom light off");
              output3 = "off";
              digitalWrite(OutPut4, LOW);
            }


            else if (header.indexOf("POST /temp") >= 0) 
            {
              Serial.println("get temp");
              TempReader();
            }
            
}
void set()
{
  Serial.begin(115200);
  pinMode(OutPut1, OUTPUT);
  pinMode(OutPut2, OUTPUT);
  pinMode(OutPut3, OUTPUT);
  pinMode(OutPut4, OUTPUT);
  digitalWrite(OutPut1, LOW);
  digitalWrite(OutPut2, LOW);
  digitalWrite(OutPut3, LOW);
  digitalWrite(OutPut4, LOW);
}
void connect()
{
   // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
}
void serialPrint()
{
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void setup() 
{
  set();
  connect();
  serialPrint();
  server.begin();
  dht.begin();
}

void loop()
{

  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) 
  {                                    // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) 
    { // loop while the client's connected       
      if (client.available()) 
      {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then                  // print it out the serial monitor
        header += c;
        if (c == '\n') 
        {
          if (currentLine.length() == 0) 
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            rocker();
            webpage(client, TempReader(), HumReader());
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } 
          else 
          { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } 
        else if (c != '\r') 
        {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
