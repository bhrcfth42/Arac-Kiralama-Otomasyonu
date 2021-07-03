# Arac-Kiralama-Otomasyonu

Bu ödevde aşağıda tanımlaması yapılan bir araç kiralama firmasında kullanılmak üzere bir otomasyon
sistemini c dilinde yazmanız isteniyor. Araç kiralama otomasyonunda araçlara, kişilere ve kiralama
işlemlerine ait bilgilerin düzenli olarak tutulması gerekmektedir. Başlangıçta araçlara ait bilgiler
girilecek ve bunlar arac.txt dosyasında kayıt edilecektir. Daha sonrasında kiralama işlemi yapılacağı
zaman ise müşteriye ait bilgiler alınıp musteri.txt dosyasında kaydedilecek ve sonrasında kiralama işlemi
için gerekli bilgiler alınıp kirala.txt dosyasında kaydedilecektir. Kodu yazarken arac, musteri ve
kiralama bilgilerini tutmak için struct yapısını kullanınız.

**1.** Araca ait bilgileri tutmak için bir struct yapısı oluşturunuz. Araca ait özellikler aşağıda
    verilmiştir.
**araç**
-^ plaka (Integer)^
-^ model^ (Char[50])^
-^ renk^ (Char[50])^
- ucret(Integer)
- musait(binary)
**2.** Müşterilere ait bilgileri tutmak için bir struct yapısı oluşturunuz.
**musteri**
-^ musteri_no (Integer)^
-^ isim (Char[50])^
- soyisim (Char[50])
- memleket(Char[50])
**3.** Kiralama işlemlerine ait bilgileri tutmak için bir struct yapısı oluşturunuz.
**kiralama**
-^ plaka (Integer)^
- musteri_no (Integer)
- kiralama_tarihi(Char[10])
- iade_tarihi(Char[10])
**4.** Main fonksiyonunda (program ilk çalıştığında) aşağıdaki seçenekler gelecektir. Örneğin
    kullanıcı klavyeden ‘1’ değerini girdiğinde araç_işlemleri menüsü açılacak daha sonra tekrar 1
    girdiğinde arac_ekle fonksiyonu çalışacaktır. Fonksiyonlara ait detaylar aşağıda açıklanmıştır.

```
Main fonksiyonu çalıştırıldığında ekrana gelecek menüler:
```
1. Arac_islemleri
2. Musteri_islemleri
3. Kiralama_islemleri
Yapmak istediğiniz işlemi giriniz:


**Klavyeden 1’e basıldığında açılacak alt menü:**

1.Araç Ekle^
2.Araç Listele^
3.Araç Ara^
4.Araç Sil^
5.Çıkış

**Klavyeden 2’e basıldığında açılacak alt menü:**

1.Musteri Ekle^
2.Musterileri Listele^
3.Müşteri Ara^
4.Müşteri Sil^
5.Çıkış

**Klavyeden 3’e basıldığında açılacak alt menü:**

1.Kirala^
2.İade^
3.Çıkış

**5.** Yapılacak işlemler için gerekli fonksiyonları oluşturunuz.

```
main () : Klavyeden alınacak değere göre istenen menüyü açacak ve gerekli fonksiyonu
çalıştıracaktır.
```
```
arac_ekle () : Klavyeden araca ait; plaka, renk, model, ücret(günlük kira bedeli) ve müsaitlik (1 ve
ya 0) bilgileri alınacak ve arac.txt dosyasına kaydedilecektir.
```
```
arac_listele () : arac.txt dosyasında kaydedilen tüm araçları listeleyecek
```
```
arac_ara () : arac.txt dosyasında araç varsa bilgilerini getirecek yoksa ekrana hata mesajı verecek
```
```
arac_sil () : Klavyeden aldığı plaka bilgisine göre arac.txt dosyasında o araca ait tüm bilgiler
silinecektir.
```
```
cikis () : Ekrana bir üst menüyü gösterecek ana menüde ise programı sonlandıracaktır.
```
```
musteri_ekle () : Klavyeden müşteriye ait no, isim, soyisim, memleket bilgisini alacak ve musteri.txt
dosyasında kaydedecektir.
```
```
musteri_listele : musteri.txt dosyasındaki tüm müşterilere ait bilgiler listelenecektir.
```
```
musteri_ara : musteri.txt dosyasındaki musteri adına göre arama yapılıp, müşteri bilgileri
listelenecektir.
```
```
musteri_sil : musteri_no ya göre musteri.txt dosyasından istenen müşteriye ait tüm bilgiler
silinecektir.
```
```
kirala () : Araç plakası ve müşteri no ve kiralama tarihi alınarak kirala.txt dosyasında
kaydedilecektir. Eğer aracın müsaitlik durumu 0 ise ekrana “Bu araç müsait değil”
şeklinde bir hata mesajı verecektir. Eğer müsaitlik durumu 1 ise o araç
kiralanabilecektir. Kayıt işlemi yapıldığında arac.txt dosyasında o araca ait müsait
durumu 0 yapılacaktır.
```
```
iade () : Müşteri aracı teslim ettiği zaman kullanıcıdan plaka bilgisi ve iade tarihi alınarak
kirala.txt dosyasında o araca ait iade tarihi girilecektir. Aracın kiralandığı tarih ile
aracın iade tarihi kullanılarak aracın müşteride kaldığı gün sayısı hesaplanacaktır. Daha
sonra hesaplanan gün sayısı ile o araca ait günlük kiralama ücreti çarpılıp kiralama
toplam ücreti hesaplanacaktır. Ayrıca arac.txt dosyasında o araca ait müsaitlik durumu
1 yapılacaktır.
```

# İçerik PDF Dosyası

[Ödev 2.pdf](https://github.com/bhrcfth42/Arac-Kiralama-Otomasyonu/files/6759077/Odev.2.pdf)
