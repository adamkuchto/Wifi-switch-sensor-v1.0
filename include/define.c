#define OutPut1 12
#define OutPut2 13
#define OutPut3 14
#define OutPut4 16
#define buildLed 2
#define DHTPIN 4 
#define DHTTYPE    DHT11

unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;
const long timeoutTempRead = 5000;//18000;
WiFiServer server(80);

String header;
String output1 = "off";
String output2 = "off";
String output3 = "off";
String output4 = "off";


