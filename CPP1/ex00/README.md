# 🧟 CPP01 - Exercise 00: BraiiiiiiinnnzzzZ

## 📚 İçindekiler
1. [Proje Amacı](#-proje-amacı)
2. [Temel Kavramlar](#-temel-kavramlar)
3. [Sektörel Terimler Sözlüğü](#-sektörel-terimler-sözlüğü)
4. [Constructor (Kurucu) Nedir?](#-constructor-kurucu-nedir)
5. [Destructor (Yıkıcı) Nedir?](#-destructor-yıkıcı-nedir)
6. [Stack vs Heap](#-stack-vs-heap)
7. [Proje Dosyaları ve İşleyiş](#-proje-dosyaları-ve-işleyiş)
8. [Kodun Çalışma Sırası](#-kodun-çalışma-sırası)
9. [Memory Management (Bellek Yönetimi)](#-memory-management-bellek-yönetimi)
10. [42 Norm Kuralları](#-42-norm-kuralları)

---

## 🎯 Proje Amacı

Bu proje, C++'ta **memory allocation (bellek tahsisi)** konseptini öğretmek için tasarlanmıştır. Özellikle:

- **Stack** ve **Heap** arasındaki farkı anlamak
- **Constructor** ve **Destructor** kullanımını öğrenmek
- **Memory leak (bellek sızıntısı)** problemlerini önlemeyi öğrenmek
- C++'ta nesne yaşam döngüsünü (object lifetime) kavramak

---

## 🧠 Temel Kavramlar

### Zombie Sınıfı Ne İş Yapar?

`Zombie` sınıfı, bir zombi karakterini temsil eder. Her zombinin:
- Bir **ismi** (`_name`) vardır
- Kendini **tanıtma** (`announce()`) yeteneği vardır
- **Doğduğunda** (constructor) ve **öldüğünde** (destructor) bunu ekrana yazdırır

---

## 📖 Sektörel Terimler Sözlüğü

### 🔹 Class (Sınıf)
**Tanım:** Veri ve fonksiyonları bir araya getiren kullanıcı tanımlı bir veri tipidir.
```cpp
class Zombie { // Bu bir sınıf tanımıdır
    // Veri üyeleri (data members)
    // Fonksiyon üyeleri (member functions)
};
```

### 🔹 Object (Nesne)
**Tanım:** Bir sınıftan türetilen somut bir örnektir (instance).
```cpp
Zombie z("Foo"); // z bir Zombie nesnesidir
```

### 🔹 Member Variable (Üye Değişken)
**Tanım:** Bir sınıfın içinde tanımlanan değişkenlerdir. Nesnenin durumunu (state) saklar.
```cpp
private:
    std::string _name; // Bu bir üye değişkendir (member variable)
```

### 🔹 Member Function (Üye Fonksiyon)
**Tanım:** Bir sınıfın içinde tanımlanan ve o sınıfın verilerine erişebilen fonksiyonlardır.
```cpp
void announce(void); // Bu bir üye fonksiyondur
```

### 🔹 Private / Public
**Private:** Sınıf dışından erişilemeyen üyeler
**Public:** Sınıf dışından erişilebilen üyeler
```cpp
private:
    std::string _name; // Sadece sınıf içinden erişilebilir
public:
    void announce(void); // Dışardan çağrılabilir
```

### 🔹 Scope (Kapsam)
**Tanım:** Bir değişkenin veya nesnenin geçerli olduğu kod bölgesidir.
```cpp
void randomChump(std::string name) {
    Zombie z(name); // z'nin scope'u bu fonksiyondur
} // Fonksiyon bitince z otomatik olarak yok edilir
```

### 🔹 Pointer (İşaretçi)
**Tanım:** Bir bellek adresini tutan değişkendir.
```cpp
Zombie* ptr; // ptr, bir Zombie nesnesinin adresini tutabilir
ptr = new Zombie("Foo"); // new ile heap'te yer ayırıp adresini döndürür
```

### 🔹 Reference (Referans)
**Tanım:** Var olan bir değişkene alternatif bir isimdir. Değişkenin kendisidir (kopyası değil).
```cpp
const std::string& name // name parametresi referans olarak alınır
// Avantaj: Kopyalama maliyeti olmaz, performans artar
```

### 🔹 Memory Leak (Bellek Sızıntısı)
**Tanım:** `new` ile ayrılan belleğin `delete` ile serbest bırakılmaması durumudur.
```cpp
Zombie* z = new Zombie("Foo");
// delete z; // Bu satır olmazsa MEMORY LEAK olur!
```

### 🔹 Dynamic Allocation (Dinamik Bellek Tahsisi)
**Tanım:** Program çalışırken `new` operatörü ile heap'te bellek ayırmaktır.
```cpp
Zombie* z = new Zombie("HeapZombie"); // Dinamik olarak oluşturuldu
```

### 🔹 Automatic Storage (Otomatik Depolama)
**Tanım:** Stack üzerinde, scope bitince otomatik olarak yok edilen değişkenlerdir.
```cpp
Zombie z("StackZombie"); // Otomatik depolama
```

---

## 🏗️ Constructor (Kurucu) Nedir?

### Tanım
**Constructor**, bir sınıftan nesne oluşturulurken **otomatik olarak çağrılan** özel bir fonksiyondur.

### Özellikleri
- Sınıfla **aynı isme** sahiptir
- **Return type (dönüş tipi) yoktur**
- Nesne oluşturulurken başlangıç değerlerini atar
- **Overload edilebilir** (farklı parametrelerle birden fazla constructor olabilir)

### Constructor Türleri

#### 1️⃣ Default Constructor (Varsayılan Kurucu)
Parametresiz constructor:
```cpp
Zombie() { // Parametresiz
    _name = "Unknown";
}
```

#### 2️⃣ Parameterized Constructor (Parametreli Kurucu)
Parametre alan constructor:
```cpp
Zombie(const std::string& name) { // Parametreli
    _name = name;
}
```

#### 3️⃣ Initializer List (Başlatıcı Liste) Kullanımı
**En verimli ve önerilen yöntem:**
```cpp
Zombie::Zombie(const std::string& name) : _name(name) {
    // _name direkt olarak name ile başlatılır (atama değil!)
}
```

### Neden Initializer List?

**Kötü Yöntem (Assignment - Atama):**
```cpp
Zombie::Zombie(const std::string& name) {
    _name = name; // 1. Önce _name default construct edilir
                  // 2. Sonra name'den değer atanır (2 işlem!)
}
```

**İyi Yöntem (Initialization - Başlatma):**
```cpp
Zombie::Zombie(const std::string& name) : _name(name) {
    // _name doğrudan name ile oluşturulur (1 işlem!)
    // Daha hızlı ve verimli
}
```

---

## 💀 Destructor (Yıkıcı) Nedir?

### Tanım
**Destructor**, bir nesne yok edilirken **otomatik olarak çağrılan** özel bir fonksiyondur.

### Özellikleri
- İsmi sınıf ismiyle aynı ama başında **tilde (~)** vardır
- **Parametre almaz**
- **Return type yoktur**
- **Overload edilemez** (sadece bir destructor olabilir)
- **Resource cleanup (kaynak temizleme)** için kullanılır

### Ne Zaman Çağrılır?

```cpp
// STACK DURUMU
void foo() {
    Zombie z("Foo");
    // ...
} // Fonksiyon bitince destructor otomatik çağrılır

// HEAP DURUMU
Zombie* ptr = new Zombie("Bar");
delete ptr; // delete çağrıldığında destructor çalışır
```

### Örnek Destructor
```cpp
Zombie::~Zombie() {
    std::cout << _name << " destroyed." << std::endl;
    // Eğer sınıfta dinamik bellek ayrılmışsa burada temizlenir
}
```

---

## 🏔️ Stack vs Heap

### Stack (Yığın)

#### Özellikler
- **Otomatik yönetim**: Scope bitince otomatik temizlenir
- **Hızlı**: Bellek tahsisi çok hızlıdır
- **Sınırlı boyut**: Genelde 1-8 MB arası
- **LIFO** (Last In First Out): Son giren ilk çıkar

#### Kullanım
```cpp
void randomChump(std::string name) {
    Zombie z(name); // STACK'TE OLUŞTURULDU
    z.announce();
} // Scope bitince z otomatik yok edilir (destructor çağrılır)
```

####장点 (Avantajlar)
✅ Manuel `delete` gerekmez  
✅ Memory leak riski yok  
✅ Hızlı  

#### 단점 (Dezavantajlar)
❌ Scope dışına çıkamaz  
❌ Sınırlı boyut  

---

### Heap (Öbek)

#### Özellikler
- **Manuel yönetim**: `new` ile oluşturulur, `delete` ile silinir
- **Yavaş**: Stack'e göre daha yavaş
- **Büyük boyut**: RAM boyutuna kadar
- **Scope'tan bağımsız**: Fonksiyon bitince de yaşamaya devam eder

#### Kullanım
```cpp
Zombie* newZombie(std::string name) {
    return new Zombie(name); // HEAP'TE OLUŞTURULDU
    // Fonksiyon bitse de zombi yaşamaya devam eder
}

int main() {
    Zombie* z = newZombie("Foo");
    z->announce();
    delete z; // MANUEL SİLMEK ZORUNDASINIZ!
}
```

#### 장점 (Avantajlar)
✅ Büyük boyutlu nesneler için uygun  
✅ Scope'tan bağımsız yaşar  
✅ Fonksiyon dışına pointer döndürebilir  

#### 단점 (Dezavantajlar)
❌ Manuel `delete` gerekir  
❌ Memory leak riski var  
❌ Daha yavaş  

---

### Stack vs Heap Karşılaştırma Tablosu

| Özellik | Stack | Heap |
|---------|-------|------|
| **Bellek Yönetimi** | Otomatik | Manuel |
| **Hız** | Çok hızlı | Daha yavaş |
| **Boyut** | Sınırlı (MB) | Büyük (GB) |
| **Yaşam Süresi** | Scope içi | Program boyunca |
| **Temizlik** | Otomatik | `delete` gerekir |
| **Memory Leak Riski** | Yok | Var |
| **Kullanım** | `Zombie z("Foo")` | `new Zombie("Foo")` |

---

## 📂 Proje Dosyaları ve İşleyiş

### Dosya Yapısı

```
ex00/
├── Zombie.hpp        → Sınıf tanımı ve fonksiyon prototipleri
├── Zombie.cpp        → Constructor, Destructor, announce() implementasyonu
├── newZombie.cpp     → Heap'te zombi oluşturan fonksiyon
├── randomChump.cpp   → Stack'te zombi oluşturan fonksiyon
├── main.cpp          → Test kodu
└── Makefile          → Derleme dosyası
```

---

### 1️⃣ Zombie.hpp (Header File)

**Görev:** Sınıf yapısını ve fonksiyon prototiplerini tanımlar

```cpp
#ifndef ZOMBIE_HPP  // Include guard başlangıcı
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;  // Zombinin ismi (sadece sınıf içinden erişilebilir)

public:
    // Constructor: Zombi oluşturulurken çağrılır
    Zombie(const std::string& name);
    
    // Destructor: Zombi yok edilirken çağrılır
    ~Zombie();
    
    // Üye fonksiyon: Zombi kendini tanıtır
    void announce(void);
};

// Yardımcı fonksiyonlar (sınıf dışı)
Zombie* newZombie(const std::string& name);    // Heap'te zombi oluşturur
void randomChump(const std::string& name);     // Stack'te zombi oluşturur

#endif  // Include guard sonu
```

#### Include Guard Nedir?
```cpp
#ifndef ZOMBIE_HPP  // "ZOMBIE_HPP tanımlı değilse"
#define ZOMBIE_HPP  // "ZOMBIE_HPP'yi tanımla"
// ... kod ...
#endif              // "if bloğunun sonu"
```

**Amacı:** Bir header dosyasının aynı programda birden fazla kez include edilmesini önler.

**Örnek Problem:**
```cpp
// file1.cpp
#include "Zombie.hpp"  // İlk kez include edildi

// file2.cpp
#include "Zombie.hpp"  // İkinci kez include edildi
```

Include guard olmazsa, `Zombie` sınıfı 2 kez tanımlanmış olur → **Compile error!**

---

### 2️⃣ Zombie.cpp (Implementation File)

**Görev:** Constructor, Destructor ve announce() fonksiyonunu implement eder

```cpp
#include "Zombie.hpp"

// Constructor: Zombi oluşturulurken ismini atar
Zombie::Zombie(const std::string& name) : _name(name) {
    // Initializer list ile _name direkt başlatılır
    // İsteğe bağlı: Constructor içinde ek işlemler yapılabilir
}

// Destructor: Zombi silindiğinde mesaj verir 
Zombie::~Zombie() {
    std::cout << _name << " destroyed." << std::endl;
}

// Announce: Kendini tanıtır
void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
```

#### Constructor Detayları

**Syntax:**
```cpp
Zombie::Zombie(const std::string& name) : _name(name)
│        │                                  │      │
│        │                                  │      └─> Parametreden gelen değer
│        │                                  └─> Üye değişken
│        └─> Constructor ismi (sınıfla aynı)
└─> Sınıf scope'u (Zombie sınıfına ait)
```

**Neden `const std::string&`?**
- `const`: Parametrenin değiştirilmeyeceğini garanti eder
- `&`: Referans olarak alır (kopyalama yapmaz → performans)
- `std::string`: Tip

**Kıyaslama:**
```cpp
// Kötü: Kopyalama yapılır (yavaş)
Zombie::Zombie(std::string name)

// İyi: Referans alır (hızlı)
Zombie::Zombie(const std::string& name)
```

---

### 3️⃣ newZombie.cpp (Heap Allocation)

**Görev:** Heap'te bir zombi oluşturup pointer döndürür

```cpp
#include "Zombie.hpp"

Zombie* newZombie(const std::string& name) {
    // new operatörü:
    // 1. Heap'te Zombie boyutunda yer ayırır
    // 2. Constructor'ı çağırır
    // 3. Nesnenin adresini (pointer) döndürür
    return (new Zombie(name));
}
```

#### `new` Operatörü Nasıl Çalışır?

```cpp
Zombie* ptr = new Zombie("Foo");
```

**Adımlar:**
1. **Bellek tahsisi:** Heap'te `sizeof(Zombie)` kadar yer ayrılır
2. **Constructor çağrısı:** `Zombie::Zombie("Foo")` çalıştırılır
3. **Pointer döndürülür:** Oluşturulan nesnenin adresi `ptr`'ye atanır

**Pointer ile Erişim:**
```cpp
ptr->announce();  // -> operatörü ile üye fonksiyona erişim
(*ptr).announce(); // Alternatif syntax (yukarıdakiyle aynı)
```

---

### 4️⃣ randomChump.cpp (Stack Allocation)

**Görev:** Stack'te geçici bir zombi oluşturur ve announce eder

```cpp
#include "Zombie.hpp"

void randomChump(const std::string& name) {
    // Stack'te oluşturulur (new yok!)
    Zombie z(name);
    
    // Kendini duyurur
    z.announce();
    
    // Fonksiyon bitince 'z' otomatik olarak yok edilir
    // Destructor burada otomatik çağrılır
}
```

#### Stack Allocation Nasıl Çalışır?

```cpp
void randomChump(const std::string& name) {
    Zombie z(name); // Constructor çağrılır
    // z kullanılır...
} // Scope sonu → Destructor otomatik çağrılır
```

**Adımlar:**
1. **Stack'te yer ayrılır** (otomatik)
2. **Constructor çağrılır:** `Zombie::Zombie(name)`
3. **Fonksiyon işini yapar**
4. **Scope sonu:** `}` geldiğinde destructor otomatik çalışır
5. **Bellek serbest bırakılır** (otomatik)

---

### 5️⃣ main.cpp (Test Kodu)

```cpp
#include "Zombie.hpp"

int main() {
    // TEST 1: Stack Allocation
    std::cout << "--- STACK TEST (randomChump) ---" << std::endl;
    randomChump("StackZombie");     
    // randomChump fonksiyonu biter bitmez StackZombie yok edilir
    std::cout << std::endl;

    // TEST 2: Heap Allocation
    std::cout << "--- HEAP TEST (newZombie) ---" << std::endl;
    Zombie* heapZ = newZombie("HeapZombie");
    heapZ->announce();
    
    // Heap'teki zombi otomatik ölmez!
    // Manuel silmek ZORUNDASINIZ
    std::cout << "Deleting heap zombie manually..." << std::endl;
    delete heapZ; // Destructor burada çalışır

    return 0;
}
```

---

## 🔄 Kodun Çalışma Sırası

### Execution Flow (Çalışma Akışı)

```
1. main() başlar
   ↓
2. "--- STACK TEST (randomChump) ---" yazdırılır
   ↓
3. randomChump("StackZombie") çağrılır
   ↓
   3.1. Stack'te Zombie nesnesi oluşturulur
   3.2. Constructor çalışır: Zombie::Zombie("StackZombie")
   3.3. z.announce() çalışır
   3.4. "StackZombie: BraiiiiiiinnnzzzZ..." yazdırılır
   3.5. Fonksiyon biter
   3.6. Destructor otomatik çalışır: ~Zombie()
   3.7. "StackZombie destroyed." yazdırılır
   ↓
4. main()'e dönülür
   ↓
5. "--- HEAP TEST (newZombie) ---" yazdırılır
   ↓
6. newZombie("HeapZombie") çağrılır
   ↓
   6.1. Heap'te new Zombie("HeapZombie") çalışır
   6.2. Constructor çalışır: Zombie::Zombie("HeapZombie")
   6.3. Pointer döndürülür ve heapZ'ye atanır
   ↓
7. heapZ->announce() çalışır
   ↓
8. "HeapZombie: BraiiiiiiinnnzzzZ..." yazdırılır
   ↓
9. "Deleting heap zombie manually..." yazdırılır
   ↓
10. delete heapZ çalışır
    ↓
    10.1. Destructor çağrılır: ~Zombie()
    10.2. "HeapZombie destroyed." yazdırılır
    10.3. Bellek serbest bırakılır
    ↓
11. main() biter
    ↓
12. Program sonlanır
```

---

### Program Çıktısı

```
--- STACK TEST (randomChump) ---
StackZombie: BraiiiiiiinnnzzzZ...
StackZombie destroyed.

--- HEAP TEST (newZombie) ---
HeapZombie: BraiiiiiiinnnzzzZ...
Deleting heap zombie manually...
HeapZombie destroyed.
```

---

## 🧹 Memory Management (Bellek Yönetimi)

### RAII Prensibi
**RAII** (Resource Acquisition Is Initialization): Kaynak edinimi başlatmadır

**Prensipler:**
1. **Constructor'da kaynak edin** (bellek, dosya, socket)
2. **Destructor'da kaynak bırak** (delete, close)
3. **Scope bitince otomatik temizlik** (stack için)

### Memory Leak Örneği (YANLIŞ)

```cpp
void badFunction() {
    Zombie* z = new Zombie("Leak");
    z->announce();
    // DELETE YOK! → MEMORY LEAK!
} // Fonksiyon biter ama heap'teki zombi hala orada!
```

**Sonuç:** `z` pointer'ı yok olur ama heap'teki Zombie nesnesi kalır → **memory leak**

### Doğru Kullanım

```cpp
void goodFunction() {
    Zombie* z = new Zombie("Safe");
    z->announce();
    delete z; // ✅ Bellek serbest bırakıldı
}
```

### Delete Kullanımı

```cpp
Zombie* ptr = new Zombie("Foo");
delete ptr; // Destructor çağrılır + bellek serbest bırakılır
```

**Delete ne yapar?**
1. **Destructor'ı çağırır:** `~Zombie()`
2. **Belleği serbest bırakır:** Heap'teki alanı iade eder

---

### Stack vs Heap - Bellek Yönetimi

| Durum | Stack | Heap |
|-------|-------|------|
| **Oluşturma** | `Zombie z("Foo")` | `new Zombie("Foo")` |
| **Constructor** | Otomatik çağrılır | Otomatik çağrılır |
| **Destructor** | Scope bitince otomatik | `delete` ile manuel |
| **Temizlik** | Otomatik | Manuel (`delete`) |
| **Risk** | Yok | Memory leak riski |

---

## 📏 42 Norm Kuralları

### ✅ Bu Projede Uyguladığımız Kurallar

#### 1. Header Dosyası Standardı
```cpp
// ✅ Doğru
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
// ...
#endif

// ❌ Yanlış
#ifndef ZOMBIE_H
#define ZOMBIE_H
```

**Kural:** C++ projeleri için `.hpp` uzantısı kullanılır

#### 2. Include Guard İsimlendirmesi
```cpp
// ✅ Doğru
#ifndef ZOMBIE_HPP  // Büyük harf, dosya ismiyle aynı
#define ZOMBIE_HPP
```

#### 3. Private Member İsimlendirmesi
```cpp
// ✅ Doğru
private:
    std::string _name;  // Alt çizgi ile başlar

// ❌ Yanlış
private:
    std::string name;   // Alt çizgi yok
```

**Kural:** Private üye değişkenler `_` ile başlar

#### 4. Const Reference Kullanımı
```cpp
// ✅ Doğru (Performans için önerilen)
Zombie(const std::string& name);

// ⚠️ Çalışır ama verimsiz
Zombie(std::string name);  // Kopyalama yapılır
```

**Kural:** Büyük objeler için `const &` kullan (string, vector, vs.)

#### 5. Initializer List Kullanımı
```cpp
// ✅ Doğru (Verimli)
Zombie::Zombie(const std::string& name) : _name(name) {
}

// ⚠️ Çalışır ama verimsiz
Zombie::Zombie(const std::string& name) {
    _name = name;  // Atama (2 işlem)
}
```

#### 6. Makefile Standartları
```makefile
# Gerekli kurallar
NAME = zombie
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)
clean:
fclean: clean
re: fclean all
.PHONY: all clean fclean re
```

**Kural:** `-Wall -Wextra -Werror` bayrakları zorunlu

#### 7. C++98 Standardı
```cpp
// ✅ C++98 uyumlu
Zombie* z = new Zombie("Foo");

// ❌ C++11 (kullanılamaz)
auto z = new Zombie("Foo");
Zombie* z = nullptr;  // nullptr yok, NULL kullan
```

---

## 🎓 Öğrendiklerimiz

### Bu Projede Kazanılan Bilgiler

1. ✅ **Stack vs Heap** farkını anladık
2. ✅ **Constructor** ve **Destructor** yazdık
3. ✅ **Memory management** (new/delete) öğrendik
4. ✅ **Memory leak** nedir, nasıl önlenir öğrendik
5. ✅ **Scope** ve **lifetime** kavramlarını öğrendik
6. ✅ **Const reference** kullanımını öğrendik
7. ✅ **Initializer list** ile verimli başlatma yaptık
8. ✅ **Pointer** kullanımı pekiştirdik
9. ✅ **Include guard** yazdık
10. ✅ **42 Norm** kurallarına uyduk

---

## 🚀 İleri Seviye Konular

### Copy Constructor ve Assignment Operator
Bu projede kullanılmadı ama ileride gerekecek:

```cpp
// Copy Constructor
Zombie(const Zombie& other);

// Assignment Operator
Zombie& operator=(const Zombie& other);
```

**Orthodox Canonical Form:** Bir sınıfta olması gereken 4 temel fonksiyon
1. Default Constructor
2. Copy Constructor
3. Assignment Operator
4. Destructor

**Not:** CPP02'de bu konuları göreceğiz!

---

## 📝 Özet

### Projenin Özü

Bu proje, **memory management** (bellek yönetimi) temellerini öğretir:

- **Stack:** Otomatik, hızlı, sınırlı
- **Heap:** Manuel, esnek, dikkatli kullanılmalı
- **Constructor:** Nesne yaratılırken çalışır
- **Destructor:** Nesne yok edilirken çalışır
- **new/delete:** Heap'te yer ayırma ve serbest bırakma

### Altın Kurallar

1. 🥇 **Her `new` için bir `delete` olmalı**
2. 🥈 **Stack kullanabiliyorsan heap kullanma**
3. 🥉 **Scope bitince otomatik temizlik en güvenlidir**
4. 🎯 **Const reference performans için önemlidir**
5. 🔒 **Private member'lar `_` ile başlar**

---

## 🎯 Test ve Derleme

### Derleme
```bash
make
```

### Çalıştırma
```bash
./zombie
```

### Temizlik
```bash
make fclean
```

### Memory Leak Kontrolü (Linux)
```bash
valgrind --leak-check=full ./zombie
```

**Beklenen sonuç:** `no leaks are possible` mesajı

---

## 📚 Kaynaklar ve İleri Okuma

### Önerilen Konular
- **Smart Pointers** (C++11): `unique_ptr`, `shared_ptr`
- **RAII** (Resource Acquisition Is Initialization)
- **Rule of Three/Five**
- **Move Semantics** (C++11)
- **Memory Alignment**
- **Stack Overflow vs Heap Fragmentation**

### 42 Network İlgili Projeler
- **CPP00:** Class basics, stdio streams
- **CPP01:** Memory, pointers, references, switch ← **Şu an buradasınız**
- **CPP02:** Ad-hoc polymorphism, operator overloading
- **CPP03:** Inheritance
- **CPP04:** Subtype polymorphism, abstract classes, interfaces

---

## 🎉 Sonuç

Bu proje, C++'ta **bellek yönetimi** ve **nesne yaşam döngüsü** konularında sağlam bir temel oluşturur. Stack ve Heap'in farkını, Constructor/Destructor'ın ne zaman çalıştığını ve memory leak'lerin nasıl önleneceğini öğrenmiş oldunuz.

**Sonraki adım:** CPP01 - ex01 (Zombie Horde) 🧟‍♂️🧟‍♀️🧟

---

**Hazırlayan:** GitHub Copilot  
**Tarih:** 20 Ocak 2026  
**Proje:** 42 School - CPP Module 01 - Exercise 00
