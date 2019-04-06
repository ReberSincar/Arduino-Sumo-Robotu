# Arduino-Sumo-Robotu
C dili ile geliştirilmiş Sumo Robotu Arduino Projesi 
![1](https://user-images.githubusercontent.com/36922746/55672079-70fa3180-589f-11e9-8b03-3ba764ccacdf.png)
T.C.
FIRAT ÜNİVERSİTESİ
TEKNOLOJİ FAKÜLTESİ
YAZILIM MÜHENDİSLİĞİ BÖLÜMÜ
  
YMH325 – MİKROİŞLEMCİLER VE PROGRAMLAMA 
Ders Proje Dokümantasyonu
Arduiono ile Sumo Robotu Yapımı

15542501 - REBER SİNCAR

Aralık – 2018 
Projenin Amacı
Sumo robotlar, robotikle hobi olarak ilgilenenlerin Japon sumo güreşlerinden esinlenerek aynı güreşi robotlara yaptırmak istemeleriyle ortaya çıkmıştır.
Sumo robotlar otonom hareket yeteneğine sahip, elektronik devreler içeren, birbirleriyle mücadele etmek amacıyla tasarlanan, amaçlanan hareketler için programlanmış robotlardır. Farklı standart ve kategorilerde üretilirler.
Sumo robotları, Karşılaşma süresince sumo robotlar birbirlerini ringin çevresindeki çizginin dışına iterek atmaya çalışırlar. Robotlar kontrast sensörleri sayesinde çevresindeki rakibi algılar, ring dışına çıkarmaya çalışırlar. Robotlara, çevresini ve rakip robotu kısa sürede algılaması için muhtelif sensörler (IR, ultrasonic, lazer, vb) eklenmekte ve geliştirilmiş taktik algoritmalar da yüklenmektedir. Sumo robotların maçı kazanmasında, sahip olduğu mekanik, elektronik tasarım ve yüklü olduğu program algoritmaları etkili olur.




Teorik Bilgi 
Sumo robotlarda gövde tasarımı çok önemlidir. Yarışmalarda kurallar gereği rakip robota ve sahaya zarar verecek parçalar kullanılamaz. Gövdede kullanılan malzemeler ve robottaki yerleri ağırlık merkezi açısından önem taşır. Robotun ağırlık merkezi doğru ayarlanmadığı takdirde sahadan savrulması kolay olacaktır. Bunun haricinde gövdeye uygun motor tercihi yapılmalıdır. 
Robotun algoritmayı kurabilmesi için sensörlere ihtiyacı vardır. Ne tür sensör kullanacağımız, kaç adet kullanacağımız bize kalmış. Malzeme listesinde de gördüğünüz üzere rakip robotu algılamak için MZ80 mesafa sensörü kullandık.
Projede kullanılan sumo robot şasesi PLA malzemesi kullanılarak %30 dolulukla basıldı. 








Donanımsal Yapı
Kullanılan Malzemeler
Arduino Uno R3 SMD Klon CH340 Chip :  Arduino, Processing/Wiring dilini kullanarak çevre elemanları ile temel giriş çıkış uygulamalarını gerçekleştiren açık kaynaklı fiziksel programlama platformudur. Arduino ile bağımsız olarak interaktif uygulamalar gerçekleştirilebilir. Aynı zamanda Arduinoyu bilgisayar ile Flash, Processing, MaxMSP, C Sharp gibi bir çok yazılım üzerinden yada kendi yazdığınız yazılımlarla haberleştirerek de kullanabilir.
L298 DC ve Step Motor Sürücü Modülü : 24V’a kadar olan motorları sürmek için hazırlanmış olan bu motor sürücü kartı, iki kanallı olup, kanal başına 2A akım vermektedir.
Sumo Robot Şasesi : 3D Yazıcı ile bastırılmış %30 doluluk oranlı şase.
MZ80 Kızılötesi Mesafe Sensörü : 80cm Menzilli Kızılötesi Sensör birçok robot projesine uygun dijital çıkışlı, yüksek kaliteli, endüstriyel kızılötesi sensördür.
6V 250 Rpm Motor : DC motorlar robotlarda veya herhangi bir sistemde direkt ya da dişli kutularıyla  (redüktörlü ya da redüktörsüz olarak) birlikte kullanılabilirler.
Motor Uyumlu Tekerlek : 6V 250 Rpm Motorlarla uyumlu tekerlekler.
7.4v Lipo Batarya : Sistemin ihtiyacını sağlayacak olan batarya(pil) .

Devre Çizimi  
![2](https://user-images.githubusercontent.com/36922746/55672081-75264f00-589f-11e9-825e-0ed61146e55d.jpg)

Yazılımsal Yapı
// Arduino Sumo Robot Kodu
 
int IN1=5; //Motor Girişleri
int IN2=6;
int IN3=7;
int IN4=8;
int inputPin = 2; //Kızıl Ötesi Sensör Girişi
int val = 0; //Kızıl Ötesi Sensörden Okunacak Değer
 
void setup()
{
Serial.begin(9600); //Serial Portu başlatıyoruz sensörü okumak için
pinMode(IN1,OUTPUT); //Motorların çıkış olduğunu belirtiyoruz.
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(inputPin, INPUT); /*Mesafe sensörünün giriş olduğunu 						    belirtiyoruz.*/
 
}
 
void loop()
{
 
val = digitalRead(inputPin);/*Sensörümüzden gelen veriyi val 							değişkenine atadık.*/

Serial.println(val);  /*Serial Portuna Okuduğumuz Değeri yazdırdık.Bu 					adımlar sensörü kontrol etmek amaçlı 						kullanılmıştır.*/

if (val == 0) //Eğer Sensör Bir Cisim Algılarsa
{
//Motorları düz ilerleyecek şekilde ayarladık
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
}
else if (val == 1) //Eğer Algılamazsa
{
/*Motorların bir tanesini ileri gidecek şekilde çalıştırarak
Robotumuzun kendi etrafında dönmesini sağlıyoruz.*/
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
}
}


Fotoğraflar    

![3](https://user-images.githubusercontent.com/36922746/55672085-7a839980-589f-11e9-9d0e-220aefdc0331.jpg)
![4](https://user-images.githubusercontent.com/36922746/55672087-7d7e8a00-589f-11e9-82e2-a571f2f9922a.jpg)
![6](https://user-images.githubusercontent.com/36922746/55672088-80797a80-589f-11e9-9d4a-84ac13eedfe2.jpg)
![7](https://user-images.githubusercontent.com/36922746/55672089-82dbd480-589f-11e9-894a-b869b96cc9e8.jpg)
