# oi-language

Oi Dilinin Temel Özellikleri
Yalın ve Anlaşılır Sözdizimi: Oi'nin sözdizimi, yeni başlayanlar için bile kolayca anlaşılabilir olacak.
Dinamik ve Statik Tip Desteği: Hem dinamik hem de statik tipleri destekleyecek.
Kolay Fonksiyon Tanımlama: Fonksiyonlar basit ve net bir şekilde tanımlanacak.
Modern Özellikler: Nesne yönelimli programlama, eşzamanlılık ve modüler yapı desteklenecek.
Oi Sözdizimi

## 1. Değişken Tanımlama ve Atama

### Dinamik Tip

```oi
var x = 10
var y = "Merhaba"
```
### Statik Tip

```oi
let z: num = 20
let msg: text = "Dünya"
```

## 2. Fonksiyonlar
```oi
fun toplama(a: num, b: num) -> num {
    return a + b
}

var sonuc = toplama(3, 5)
```

## 3. Kontrol Yapıları

### Koşullar

```oi
var num = 10
if num > 5 {
    print("Numara 5'ten büyük")
} else {
    print("Numara 5'ten küçük veya eşit")
}
```

### Döngüler

```oi
loop i in 1..10 {
    print(i)
}

loop while num > 0 {
    print(num)
    num = num - 1
}
```

## 4. Eşzamanlılık
```oi
spawn task calis() {
    print("Task çalışıyor")
}

var ch = chan num

spawn task gonder() {
    ch <- 10
}

var deger = <-ch
print(deger)
```

## 5. Nesne Yönelimli Programlama

```oi
class Araba {
    var marka: text
    var model: text

    init(marka: text, model: text) {
        self.marka = marka
        self.model = model
    }

    fun bilgi() -> text {
        return self.marka + " " + self.model
    }
}

var araba = Araba("Toyota", "Corolla")
print(araba.bilgi())
```

## 6. Modüller ve Paketler

```oi
import math

var sonuc = math.sqrt(16)
print(sonuc)
```

## Oi ile Bir Örnek Program

```oi
fun faktoriyel(n: num) -> num {
    if n == 0 {
        return 1
    }
    return n * faktoriyel(n - 1)
}

var sayi = 5
print("Faktoriyel \(sayi) = \(faktoriyel(sayi))")
```

## Özet
Oi dili, yalın ve kullanıcı dostu bir sözdizimine sahip olup, modern programlama ihtiyaçlarını karşılayacak şekilde tasarlanmıştır.