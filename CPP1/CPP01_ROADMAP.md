# 🗺️ CPP01 Module - Complete Roadmap & Algorithm Guide

## 📋 Module Overview - CPP01

**Ana Konular:**
- Memory Allocation (Bellek Tahsisi)
- Pointers to Members (Üye İşaretçileri)
- References (Referanslar)
- Switch Statements

**Toplam Egzersiz Sayısı:** 6 (ex00 - ex06)

---

## ✅ Exercise 00: BraiiiiiiinnnzzzZ
**Durum:** ✅ TAMAMLANDI

**Öğrenilen Konseptler:**
- Stack vs Heap allocation
- Constructor / Destructor
- new / delete operatörleri
- Memory management temelları

---

## 🔄 Exercise 01: Moar brainz!

### 🎯 Amaç
Zombie'lerin bir **horde (horde = sürü)** oluşturmak. Yani birden fazla zombi'yi dinamik olarak (heap'te) bir dizi şeklinde ayırmak.

### 📝 Gereksinimler
1. `zombieHorde(int N, std::string name)` fonksiyonu yazılmalı
2. N tane Zombie nesnesi içeren bir **array** döndürmeli (heap'te)
3. Tüm zombiler aynı isimle başlatılmalı
4. Default constructor gerekli (parametresiz)
5. Setter fonksiyonu ile isimlerin atanması

### 🧩 Algorithm Yapılandırması

#### Adım 1: Zombie Sınıfını Güncelle
```
1. Default constructor ekle (parametresiz)
   └─> Zombie();
   
2. Setter fonksiyonu ekle
   └─> void setName(const std::string& name);
   
3. Mevcut parametreli constructor'ı koru
   └─> Zombie(const std::string& name);
```

#### Adım 2: zombieHorde Implementasyonu
```
Pseudo-code:
─────────────
FUNCTION zombieHorde(N, name):
    1. Heap'te N boyutunda Zombie dizisi ayır
       └─> new Zombie[N]
    
    2. FOR i = 0 to N-1:
           array[i].setName(name)
    
    3. Diziyi return et
```

#### Adım 3: Main'de Test
```
1. zombieHorde çağır (örn: 5 zombi)
2. Tüm zombileri announce ettir (loop)
3. Diziyi delete[] ile temizle (ÖNEMLI!)
```

### ⚠️ Kritik Noktalar
- Array silmek için `delete[]` kullan (tek delete değil!)
- Default constructor gerekli (çünkü `new Zombie[N]` önce boş objeler yaratır)
- İsimleri sonradan setName ile atıyoruz

### 📊 Bellek Diyagramı
```
Stack:                  Heap:
┌─────────┐            ┌──────────┐
│ horde   │──────────> │ Zombie 0 │ _name = "Foo"
│(pointer)│            ├──────────┤
└─────────┘            │ Zombie 1 │ _name = "Foo"
                       ├──────────┤
                       │ Zombie 2 │ _name = "Foo"
                       ├──────────┤
                       │   ...    │
                       └──────────┘
                       
delete[] horde; ← Tüm array'i temizler
```

---

## 🔗 Exercise 02: HI THIS IS BRAIN

### 🎯 Amaç
**Pointer** ve **Reference** arasındaki farkı anlamak.

### 📝 Gereksinimler
1. String değişken oluştur
2. String'in pointer'ını (`stringPTR`)
3. String'in reference'ını (`stringREF`)
4. Üçünün de:
   - Memory adreslerini yazdır
   - Değerlerini yazdır

### 🧩 Algorithm Yapılandırması

```
Pseudo-code:
─────────────
1. CREATE string = "HI THIS IS BRAIN"

2. CREATE pointer to string
   └─> string* stringPTR = &string

3. CREATE reference to string
   └─> string& stringREF = string

4. PRINT:
   - string'in adresi
   - stringPTR'nin tuttuğu adres
   - stringREF'in adresi
   
5. PRINT:
   - string'in değeri
   - stringPTR'nin gösterdiği değer (*stringPTR)
   - stringREF'in değeri
```

### 📊 Konsept Karşılaştırması

| Özellik | Pointer | Reference |
|---------|---------|-----------|
| Syntax | `string* ptr` | `string& ref` |
| Başlatma | `ptr = &str` | `ref = str` |
| Erişim | `*ptr` | `ref` |
| Değiştirilebilir | ✅ (başka yeri gösterebilir) | ❌ (tek sefer atanır) |
| NULL olabilir | ✅ | ❌ |
| Adres operatörü | `ptr` = adres | `&ref` = adres |

### 💡 Beklenen Çıktı
```
Memory address of string: 0x7fff5fbff8b0
Memory address held by stringPTR: 0x7fff5fbff8b0
Memory address held by stringREF: 0x7fff5fbff8b0

Value of string: HI THIS IS BRAIN
Value pointed to by stringPTR: HI THIS IS BRAIN
Value pointed to by stringREF: HI THIS IS BRAIN
```

---

## ⚔️ Exercise 03: Unnecessary violence

### 🎯 Amaç
**Class composition** ve **pointer to member** kavramlarını öğrenmek.

### 📝 Gereksinimler
1. `Weapon` sınıfı:
   - Private: `std::string _type`
   - Getter: `getType()` (const reference döner)
   - Setter: `setType()`

2. `HumanA` sınıfı:
   - Weapon'ı **reference** olarak tutar
   - Constructor'da Weapon alır
   - `attack()` fonksiyonu

3. `HumanB` sınıfı:
   - Weapon'ı **pointer** olarak tutar
   - Constructor'da Weapon almaz
   - `setWeapon()` ile sonradan silah verilir
   - `attack()` fonksiyonu (silah yoksa kontrol et!)

### 🧩 Algorithm Yapılandırması

#### Weapon Sınıfı
```
CLASS Weapon:
    PRIVATE:
        string _type
    
    PUBLIC:
        Weapon(type)
        getType() const -> const string&
        setType(newType)
```

#### HumanA (Reference kullanır)
```
CLASS HumanA:
    PRIVATE:
        string _name
        Weapon& _weapon  ← REFERENCE (initializer list'te başlatılmalı)
    
    PUBLIC:
        HumanA(name, weapon)
        attack() -> print "{name} attacks with their {weapon.getType()}"
```

**Neden Reference?**
- HumanA her zaman silahlıdır
- Constructor'da verilir, değiştirilemez
- NULL olamaz (güvenli)

#### HumanB (Pointer kullanır)
```
CLASS HumanB:
    PRIVATE:
        string _name
        Weapon* _weapon  ← POINTER (NULL olabilir)
    
    PUBLIC:
        HumanB(name) -> _weapon = NULL
        setWeapon(weapon) -> _weapon = &weapon
        attack():
            IF _weapon != NULL:
                print "{name} attacks with their {weapon->getType()}"
            ELSE:
                print "{name} has no weapon"
```

**Neden Pointer?**
- HumanB başlangıçta silahsız olabilir
- Sonradan `setWeapon` ile verilir
- NULL kontrolü gerekli

### 📊 Reference vs Pointer (Bu Egzersizde)

```
HumanA:                    HumanB:
┌──────────┐              ┌──────────┐
│ _name    │              │ _name    │
│ _weapon& │─────┐        │ _weapon* │──┐
└──────────┘     │        └──────────┘  │
                 ↓                       ↓
              ┌────────┐              ┌────────┐
              │ Weapon │              │ Weapon │ (veya NULL)
              └────────┘              └────────┘

- Must have weapon       - Can be weaponless
- Set in constructor     - Set later with setter
- Can't be changed       - Can be changed
```

### 💡 Main Test Örneği
```cpp
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
}
{
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
}
```

---

## 📄 Exercise 04: Sed is for losers

### 🎯 Amaç
File manipulation (dosya işlemleri) ve string replacement (string değiştirme).

### 📝 Gereksinimler
1. Program 3 parametre alır: `<filename> <s1> <s2>`
2. `<filename>` dosyasını okur
3. `<s1>` stringini `<s2>` ile değiştirir
4. Sonucu `<filename>.replace` dosyasına yazar
5. C fonksiyonları YASAK (fopen, fclose, vs.)
6. C++ streams kullanılmalı (`ifstream`, `ofstream`)

### 🧩 Algorithm Yapılandırması

#### Ana Akış
```
PROGRAM sed_is_for_losers(filename, s1, s2):
    
    1. VALIDATE inputs:
       ├─> IF arguments != 3: ERROR
       ├─> IF s1 is empty: ERROR
       └─> IF filename doesn't exist: ERROR
    
    2. OPEN input file (filename):
       └─> ifstream infile(filename)
    
    3. CREATE output file (filename + ".replace"):
       └─> ofstream outfile(filename + ".replace")
    
    4. READ entire file:
       └─> WHILE (getline(infile, line)):
           ├─> Replace all s1 with s2 in line
           └─> Write line to outfile
    
    5. CLOSE files (automatic with ifstream/ofstream)
```

#### String Replacement Algorithm
```
FUNCTION replaceAll(line, s1, s2):
    result = ""
    pos = 0
    
    WHILE (true):
        found = line.find(s1, pos)
        
        IF found == npos:
            result += line.substr(pos)
            BREAK
        
        result += line.substr(pos, found - pos)
        result += s2
        pos = found + s1.length()
    
    RETURN result
```

### ⚠️ Edge Cases (Özel Durumlar)

1. **s1 boş string:** Sonsuz döngü riski
2. **s1 içinde s2 var:** Kısmi eşleşme problemi
3. **Dosya açılamıyor:** Hata kontrolü
4. **Overlapping matches:** "aaa" içinde "aa" → "a" 

### 💡 Örnek
```
Input file (test.txt):
"Hello World, Hello Universe"

Command: ./replace test.txt "Hello" "Hi"

Output (test.txt.replace):
"Hi World, Hi Universe"
```

### 📊 Flow Diagram
```
┌─────────────┐
│   MAIN      │
└──────┬──────┘
       │
       ├─> Validate args
       │
       ├─> Open infile ───> ┌──────────┐
       │                    │ test.txt │
       │                    └──────────┘
       │
       ├─> Open outfile ──> ┌────────────────┐
       │                    │test.txt.replace│
       │                    └────────────────┘
       │
       └─> FOR each line:
           ├─> replaceAll(line, s1, s2)
           └─> Write to outfile
```

---

## 🗣️ Exercise 05: Harl 2.0

### 🎯 Amaç
**Function pointers** (fonksiyon işaretçileri) kullanmayı öğrenmek.

### 📝 Gereksinimler
1. `Harl` sınıfı:
   - 4 private fonksiyon: `debug()`, `info()`, `warning()`, `error()`
   - 1 public fonksiyon: `complain(std::string level)`
   
2. `complain()` fonksiyonu:
   - Level'e göre uygun fonksiyonu çağırır
   - **IF/ELSE zinciri YASAK**
   - **Function pointer array kullanılmalı**

### 🧩 Algorithm Yapılandırması

#### Harl Sınıfı Yapısı
```
CLASS Harl:
    PRIVATE:
        debug()   -> "I love having extra bacon..."
        info()    -> "I cannot believe adding extra bacon..."
        warning() -> "I think I deserve to have some extra bacon..."
        error()   -> "This is unacceptable! I want to speak..."
    
    PUBLIC:
        complain(level):
            1. Create array of function pointers
            2. Create array of level names
            3. Find matching level
            4. Call corresponding function via pointer
```

#### Function Pointer Implementation
```cpp
// Function pointer syntax:
void (Harl::*functionPtr)(void);

// Array of function pointers:
void (Harl::*functions[4])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};

// Calling through pointer:
(this->*functions[i])();
```

#### Complain Algorithm
```
FUNCTION complain(level):
    levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}
    functions[4] = {&debug, &info, &warning, &error}
    
    FOR i = 0 to 3:
        IF levels[i] == level:
            CALL (this->*functions[i])()
            RETURN
    
    PRINT "Invalid level"
```

### 📊 Function Pointer Diagram
```
levels[]           functions[]         Actual Functions
┌─────────┐       ┌──────────┐        ┌──────────────┐
│"DEBUG"  │──┐    │&debug    │───────>│ debug()      │
├─────────┤  │    ├──────────┤        ├──────────────┤
│"INFO"   │──┼───>│&info     │───────>│ info()       │
├─────────┤  │    ├──────────┤        ├──────────────┤
│"WARNING"│  │    │&warning  │───────>│ warning()    │
├─────────┤  │    ├──────────┤        ├──────────────┤
│"ERROR"  │  │    │&error    │───────>│ error()      │
└─────────┘  │    └──────────┘        └──────────────┘
             │
        Match index, call function
```

### 💡 Neden Function Pointer?
- **Kod tekrarı önler:** 4 if yerine 1 loop
- **Scalable:** Yeni level eklemek kolay
- **Elegant:** Daha temiz kod
- **Performance:** Switch/if'ten hızlı olabilir

---

## 🔊 Exercise 06: Harl filter

### 🎯 Amaç
**Switch statement** kullanarak log filtreleme yapmak.

### 📝 Gereksinimler
1. Program 1 parametre alır: log level
2. O level ve üstü seviyeleri yazdırır:
   - DEBUG: Tüm mesajları göster
   - INFO: INFO, WARNING, ERROR göster
   - WARNING: WARNING, ERROR göster
   - ERROR: Sadece ERROR göster
   - Diğer: "Probably complaining about insignificant problems"

### 🧩 Algorithm Yapılandırması

#### Switch Kullanımı (Fall-through)
```
FUNCTION filterLevel(level):
    
    index = findLevelIndex(level)
    
    SWITCH (index):
        CASE 0: // DEBUG
            print "[DEBUG]"
            debug()
            // FALL THROUGH (no break!)
        
        CASE 1: // INFO
            print "[INFO]"
            info()
            // FALL THROUGH
        
        CASE 2: // WARNING
            print "[WARNING]"
            warning()
            // FALL THROUGH
        
        CASE 3: // ERROR
            print "[ERROR]"
            error()
            BREAK
        
        DEFAULT:
            print "Probably complaining..."
```

#### Fall-through Mekanizması
```
Input: "INFO"
        │
        ▼
    ┌────────┐
    │ CASE 1 │ (INFO)  ← Buradan başla
    └────┬───┘
         │ (no break!)
         ▼
    ┌────────┐
    │ CASE 2 │ (WARNING) ← Buraya da gir
    └────┬───┘
         │ (no break!)
         ▼
    ┌────────┐
    │ CASE 3 │ (ERROR) ← Buraya da gir
    └────┬───┘
         │ (break!)
         ▼
     [END]
```

### 📊 Level Hierarchy
```
Priority: DEBUG < INFO < WARNING < ERROR

DEBUG    ─────────────────────────────┐
                                       │
INFO     ───────────────────────┐     │
                                 │     │
WARNING  ─────────────┐          │     │
                       │          │     │
ERROR    ─┐            │          │     │
          │            │          │     │
          ▼            ▼          ▼     ▼
        ERROR      WARNING      INFO  DEBUG
```

### 💡 Örnek Çıktılar
```bash
$ ./harlFilter "WARNING"
[WARNING]
I think I deserve to have some extra bacon for free.

[ERROR]
This is unacceptable! I want to speak to the manager now.

$ ./harlFilter "DEBUG"
[DEBUG]
I love having extra bacon...

[INFO]
I cannot believe adding extra bacon...

[WARNING]
I think I deserve...

[ERROR]
This is unacceptable!
```

---

## 📈 Öğrenme Yol Haritası

```
Week 1: Memory Fundamentals
├─ ex00: Stack/Heap, new/delete        ✅ DONE
└─ ex01: Array allocation, delete[]    ← NEXT

Week 2: References & Pointers
├─ ex02: Pointer vs Reference
└─ ex03: Pointer to members, composition

Week 3: Advanced C++
├─ ex04: File I/O, string manipulation
├─ ex05: Function pointers
└─ ex06: Switch statements, fall-through
```

---

## 🎯 Her Egzersiz İçin Checklist

### General (Tümü için)
- [ ] Makefile (NAME, CC, CFLAGS, all, clean, fclean, re)
- [ ] -Wall -Wextra -Werror -std=c++98
- [ ] .hpp dosyaları (header guard)
- [ ] Orthodox Canonical Form (ex01'den itibaren gerekebilir)
- [ ] Memory leak yok (valgrind test)

### ex01 Specific
- [ ] Default constructor
- [ ] setName() fonksiyonu
- [ ] zombieHorde() implementation
- [ ] delete[] kullanımı
- [ ] N zombi create edilmesi

### ex02 Specific
- [ ] Pointer tanımı
- [ ] Reference tanımı
- [ ] Adresleri yazdırma
- [ ] Değerleri yazdırma

### ex03 Specific
- [ ] Weapon sınıfı (getter const ref)
- [ ] HumanA (reference member)
- [ ] HumanB (pointer member, NULL check)
- [ ] attack() implementations

### ex04 Specific
- [ ] 3 parametre kontrolü
- [ ] File existence check
- [ ] ifstream/ofstream kullanımı
- [ ] String replacement (tüm oluşumlar)
- [ ] .replace uzantılı dosya

### ex05 Specific
- [ ] 4 private complaint fonksiyonu
- [ ] Function pointer array
- [ ] complain() implementation
- [ ] No if/else chain

### ex06 Specific
- [ ] Switch statement
- [ ] Fall-through mechanism
- [ ] Level filtering
- [ ] Default case

---

## 🚀 Başlangıç Stratejisi

### En Kolay → En Zor Sıralama
1. ✅ **ex00** - Temel (DONE)
2. 🟢 **ex02** - Kolay (Sadece pointer/ref göster)
3. 🟡 **ex01** - Orta (Array allocation)
4. 🟡 **ex03** - Orta (Reference vs pointer)
5. 🟠 **ex05** - Zor (Function pointers)
6. 🟠 **ex04** - Zor (File I/O, string manipulation)
7. 🔴 **ex06** - En zor (Switch + filtering logic)

### Önerilen Sıralama (Öğrenme odaklı)
1. ex00 ✅
2. **ex01** (Array ile devam)
3. **ex02** (Reference öğren)
4. **ex03** (Reference pratiği)
5. **ex04** (File I/O)
6. **ex05** (Function pointer)
7. **ex06** (Switch)

---

## 📚 Ek Kaynaklar

### Önemli C++ Konular (Bu modülde)
- `new` vs `new[]`
- `delete` vs `delete[]`
- Reference initialization (initializer list)
- Pointer to member functions
- Fall-through in switch
- `ifstream` / `ofstream` / `getline`
- `string::find()` / `string::substr()`

### Debug Komutları
```bash
# Compile
make

# Memory leak check
valgrind --leak-check=full ./program

# Clean
make fclean
```

---

## 🎓 Sonuç

CPP01 modülü, C++'ın **bellek yönetimi** ve **pointer/reference** konseptlerinde ustalaşmak için kritiktir. Her egzersiz bir öncekinin üzerine inşa edilir:

1. **ex00-01:** Memory allocation basics
2. **ex02-03:** Pointer vs Reference semantics
3. **ex04:** Practical file manipulation
4. **ex05-06:** Advanced C++ features (function pointers, switch)

**Şimdi sırada:** ex01 - Zombie Horde 🧟‍♂️🧟‍♀️

Her egzersiz için detaylı yardım isteyebilirsiniz!
