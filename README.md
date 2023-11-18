## RFID-check-in-check-out-system-via-LINE
# บทคัดย่อ
  โครงงานนี้จัดทำขึ้นเพื่อเป็นส่วนหนึ่งของวิชา PHYSICAL COMPUTING เพื่อให้ได้ศึกษาหาความรู้ในเรื่องของการเขียนโปรแกรมภาษาC และการต่อบอร์ด Arduino ซึ่งโครงงานที่จะนำเสนอนี้เป็นโครงงานเป็นเครื่องมือที่ใช้ในการตรวจจับการสแกนของบัตรผ่าน การใช้RFID Modlue ในการอ่านค่าของตัวบัตรแล้วจะส่งข้อมูลกลับมาทางไลน์
หลักการทำงานของอุปกรณ์มีขั้นตอนการทำงานดังนี้ ตัวRFID Modlue จะจับสัญญาณของตัวบัตรที่เราเอามาสแกน จากนั้นจะนำข้อมูลที่อ่านได้มาเข้าสู่ตัว ESP8266 เพื่อที่จะประมวลผลแล้วส่งค่ากลับออกมาทางไลน์โดยที่อุปกรณ์นั้นได้มีการเข้ารหัสไวฟายเดียวกัน ผู้จัดทำหวังว่าการจัดทำโครงงานนี้จะมีข้อมูลที่เป็นประโยชน์ต่อผู้ที่สนใจศึกษาการพัฒนาเทคโนโลยีที่เกี่ยวข้องกับ IoT และบอร์ด Arduino ต่อไปในอนาคต
https://github.com/Icuptocilz/rfid-check-in-check-out-system-via-LINE/blob/39f6d317769f04cb9a91886fc73ac5f7c0c90e14/%E0%B8%9A%E0%B8%97%E0%B8%84%E0%B8%B1%E0%B8%94%E0%B8%A2%E0%B9%88%E0%B8%AD.pdf

# อุปกรณ์
อุปกรณ์ที่ใช้พัฒนาได้แก่

![image](https://miro.medium.com/v2/resize:fit:1024/1*Yu0w5T7AWg8WqjVFXwaQPg.jpeg)
- ESP8266
  
![image](https://m.media-amazon.com/images/I/71wuC+BKB4L.jpg)
- RFID Module
  
![image](https://inwfile.com/s-cq/pfcgbw.jpg)
- Jump Wire

![image](https://inwfile.com/s-cq/77kui9.jpg)
- Breadboard 400 holes 
 
# Youtube สาธิตการทำงาน
https://youtu.be/WK7JESd642E?si=0i-6S-8zKGwJxxPQ

# Code โปรแกรม
https://github.com/Icuptocilz/rfid-check-in-check-out-system-via-LINE/blob/2d72f1a2e89aab79d643639c529175cac77df3bb/code.ino

# Poster
https://github.com/Icuptocilz/rfid-check-in-check-out-system-via-LINE/blob/3f2464085217912dbc0cb97390b86c6c6ac24026/phycom_poster1.pdf


![phycom_poster1_page-0001](https://github.com/Icuptocilz/rfid-check-in-check-out-system-via-LINE/assets/112687372/1164767a-e3d8-44c8-8a7e-eb5ff0736c80)

# สมาชิกในกลุ่ม
นางสาวณกาล พลบุญ		    รหัสนักศึกษา 65070058

นายณภัทร พลดงนอก 		  รหัสนักศึกษา 65070061

นางสาวณัฐรดา กิจสมบูรณ์สุข	รหัสนักศึกษา 65070082

นางสาวณัฐณิชา ชื่นสบาย 	  รหัสนักศึกษา 65070072
