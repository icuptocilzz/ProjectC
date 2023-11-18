#include <SPI.h>
#include "MFRC522.h"
#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>

boolean staruwork[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#define LINE_TOKEN  "JsTQziSW8ftrcimBgYUzrd2Bp0g5BhGy6ZcmLbYXbFU"   // TOKEN
#define SSID        "WIFI"   // ชื่อ Wifi
#define PASSWORD    "PASSWORD"   // รหัส Wifi

#define RST_PIN  D1
#define SS_PIN  D2


MFRC522 mfrc522(SS_PIN, RST_PIN);

String rfid_in = "";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("");
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting ",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  LINE.setToken(LINE_TOKEN);
  Serial.println("");
}

void loop() {
  Serial.println(" กรุณาสแกนบัตรเพื่อลงชื่อ เข้า/ออก งาน");
  // LINE.notify(" กรุณาสแกนบัตรเพื่อลงชื่อ เข้า/ออก งาน");
  // delay(5000);
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    LINE.notify("กำลังประมวลผล");
    rfid_in=rfid_read();
    Serial.print(" " + rfid_in);
    if(rfid_in=="D3 EE 89 FB"){
      if(staruwork[0]==0){
        staruwork[0]=1;
        Serial.println("  สวัสดีคุณอิ้น");
        Serial.println("  ลงชื่อ นางอิ้น เข้าทำงานสำเร็จ");
        LINE.notifyPicture("ลงชื่อ นางอิ้น เข้าทำงานสำเร็จ","https://cdn.discordapp.com/attachments/1167786480257736786/1167786620427173928/IMG_6484.jpg?ex=654f650a&is=653cf00a&hm=3b9e0888d1433ed8eb84a5e939b7043ea7b5ad4cc4a6697f4999e9d7c057cf19&");
      }
      else{
        staruwork[0]=0;
        Serial.println("  ลงชื่อ นางอิ้น ออกงานสำเร็จ");
        LINE.notifyPicture(" ลงชื่อ นางอิ้น ออกงานสำเร็จ","https://cdn.discordapp.com/attachments/1167786480257736786/1167786620427173928/IMG_6484.jpg?ex=654f650a&is=653cf00a&hm=3b9e0888d1433ed8eb84a5e939b7043ea7b5ad4cc4a6697f4999e9d7c057cf19&");
      }
      delay(2000);
    }
    else if(rfid_in=="B3 23 94 C5"){
      if(staruwork[1]==0){
        staruwork[1]=1;
        Serial.println("  นาย เรน เข้าทำงานสำเร็จ");
        LINE.notifyPicture(" นาย เรน เข้าทำงานสำเร็จ","https://cdn.discordapp.com/attachments/1167786480257736786/1167786620762726400/IMG_6440.jpg?ex=654f650a&is=653cf00a&hm=aac425ad8441b1f1389d73e30c10fe4cf7ed9f5898723cc6801f280f94702831&");
      }
      else{
        staruwork[1]=1;
        Serial.println("  นาย เรน ออกงานสำเร็จ");
        LINE.notifyPicture(" นาย เรน ออกงานสำเร็จ","https://cdn.discordapp.com/attachments/1167786480257736786/1167786620762726400/IMG_6440.jpg?ex=654f650a&is=653cf00a&hm=aac425ad8441b1f1389d73e30c10fe4cf7ed9f5898723cc6801f280f94702831&");
      }
      delay(2000);
    }
    else{
      Serial.println("  ไม่ทราบชื่อ");
    }
  }
  delay(1);
}

String rfid_read() {
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  return content.substring(1);
}