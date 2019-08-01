#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

#define ssid "your_ssid"
#define password "ssid_password"
#define FIREBASE_HOST "firebase_url"
#define FIREBASE_AUTH "firebase_token"

const int LED1 = 2;
const int LED2 = 15;
const int LED3 = 5;
const int LED4 = 18;

String fireStatus = "";

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  Serial.println("Trying to connect");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
  }

  Serial.println("\nWifi connected");
  // Firebase.setString("LED_STATUS", "OFF");
}

void loop()
{
  // put your main code here, to run repeatedly:
  fireStatus = Firebase.getString("MinterinKosan/LED_STATUS");

  if (fireStatus == "1")
  {
    Serial.println("Led Turned ON");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }
  else if (fireStatus == "0")
  {
    Serial.println("Led Turned OFF");
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
}
