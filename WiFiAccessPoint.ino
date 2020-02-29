#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

int pin = D4;

const char *ssid = "NaylaTools";
const char *password = "NAYLATOOLS";

ESP8266WebServer server(80);

void setup() {
  pinMode(pin, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Menyetwl Akses Poin");
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", localhost);
  server.begin();
  Serial.println("HTTP server Mulai");
}

void localhost() {
  if(server.arg("relay")=="on"){
    digitalWrite(pin, LOW);a
    server.send(200, "text/html", "<a href='?relay=off'><button>OFF</button></a>");
  }
  if(server.arg("relay")=="off"){
    digitalWrite(pin, HIGH);
    server.send(200, "text/html", "<a href='?relay=on'><button>ON</button></a>");
  }
  server.send(200, "text/html", "<a href='?relay=off'><button>OFF</button></a>");
}

void loop() {
  server.handleClient();
}
