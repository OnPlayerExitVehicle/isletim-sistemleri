# 1. Grubunuzdaki tüm üyelerin adları
      B191210057 - ALİ NAZİF KOCA
      B191210009 - SALİH EŞME
      G191210050 - RAFET ERSOY
      G191210062 - BERKAY EROL

# 2. Gönderiminizdeki tüm dosyaların/dizinlerin bir listesi ve her birinin kısa bir açıklaması
  - bin
    - <b>main.exe</b>
  - include
    - <b>colors.h</b>    -> Komutların renklerinin ayarlanmasını sağlayan colors'un başlık dosyası
    - <b>hashtable.h</b> -> Build in komutlarının saklanması için hafıza yönetimini sağlayan hastable'ımızın başlık dosyası
    - <b>parser.h</b>    -> Dışardan girilen satırı komuta ve argümanlara ayıran parser'ımızın başlık dosyası
  - src
    - <b>colors.c</b>    -> Komutların renklerinin ayarlanmasını sağlayan colors'un kaynak dosyası
    - <b>hashtable.c</b> -> Build in komutlarının saklanması için hafıza yönetimini sağlayan hastable'ımızın kaynak dosyası
    - <b>main.c</b>      -> Ana kodların bulunduğu kaynak dosya
    - <b>parser.c</b>    -> Dışardan girilen satırı komuta ve argümanlara ayıran parser'ımızın kaynak dosyası
  - <b>README.md</b>
  - <b>makefile</b>      -> Projede yer alan dosyalarımızı derleyen ve çalıştırılabilir dosya hale getiren makefile dosyası

# 3. Programlarınızı derlemek için talimatlar
  - Linux dağıtımlarında komut penceresinden proje dizinine ulaşarak <b>make</b> komutuyla derlenebilir.

# 4. Programlarınızı/komut dosyalarınızı çalıştırma talimatları
  - <b>make</b> komutu derlendikten sonra çalışmasını sağlar. Aynı zamanda <b>bin</b> dizini içerisinden <b>main</b> ile de çalıştırılabilir.
# 5. Geliştirme sırasında karşılaştığınız zorluklar
  - Başlangıçta çıktıyı sadece tek kelime olarak alabiliyorduk, daha sonrasında <b>fgets()</b> fonksiyonunu kullanarak bu problemi çözdük.
  - <b>fgets()</b> kullanarak aldığımız string'lerin sonundaki '\n' karakteri dolayısıyla birkaç sefer hatayla karşılaştık. Daha sonra bu karakteri silerek problemi çözdük.
  - <b>cd</b> komutu içerisinde birkaç kez problem yaşadık. Daha sonrasında hata verip vermediğini test ederek bu problemi de çözüme ulaştırdık.
  - <b>parse()</b> fonksiyonu içerisinde iletişimsizlikten kaynaklı birkaç problem yaşadık. Daha sonrasında string'leri düzgün bir şekilde parse etmeyi başardık.
# 6. Programı yazmanıza yardımcı olması için kullandığınız kaynaklar 
  - https://man7.org/linux/man-pages
  - https://stackoverflow.com
  - http://www.csl.mtu.edu
  - https://www.geeksforgeeks.org
