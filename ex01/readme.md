# Capire come una classe figlia usa, estende e modifica una classe padre

## Cosa significa davvero “una classe figlia usa, estende e modifica una classe padre”

### 1. “USA” (riusa quello che esiste già)
ScavTrap non ricrea da zero:
_name
_hitPoints
_energyPoints
_attackDamage
takeDamage()
beRepaired()
👉 li eredita automaticamente da ClapTrap.
Sintassi chiave
```c++
class ScavTrap : public ClapTrap
```
Questa riga dice al compilatore:
“ScavTrap È un ClapTrap, con tutto quello che ClapTrap ha”
💡 Quindi:
```c++
ScavTrap s("Bob");

s.takeDamage(10);   // funzione di ClapTrap
s.beRepaired(5);    // funzione di ClapTrap
```
👉 senza riscriverle

### “ESTENDE” (aggiunge cose nuove)
ScavTrap fa cose che ClapTrap non fa.
Esempio richiesto dal subject:
```c++
void guardGate();

//Sintassi
ScavTrap.hpp
class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};
ScavTrap.cpp
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name
              << " is now in Gate keeper mode"
              << std::endl;
}
```
👉 ClapTrap non sa nemmeno che questa funzione esiste
👉 ma un ScavTrap sì

### “MODIFICA” (ridefinisce un comportamento)
Qui sta la parte più importante: override di attack()
In ClapTrap
```c++
void ClapTrap::attack(const std::string& target);
```
In ScavTrap
```c++
void ScavTrap::attack(const std::string& target);
```
👉 stessa firma
👉 classe diversa
👉 comportamento diverso
**⚠️ Concetto fondamentale**
Quando scrivi:
```c++
ScavTrap s("Jack");
s.attack("enemy");
```
**👉 NON viene chiamato ClapTrap::attack**
**👉 viene chiamato ScavTrap::attack**
Questo è **“modificare”** il comportamento.

## Come funziona davvero il costruttore (punto chiave dell’ex01)
ClapTrap ha già un costruttore
Esempio:
```c++
ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
}
```
ScavTrap DEVE chiamarlo
Non è opzionale.
**Sintassi corretta**
```c++
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "ScavTrap constructor called" << std::endl;
}
```
💡 Qui succede questo, in ordine:
* entra nel costruttore di ClapTrap
* inizializza _name
* poi ScavTrap modifica i valori
* risultato: oggetto coerente
**👉 Non ridichiari le variabili le riusi**

3️⃣ Override di attack() — sintassi
In ClapTrap.cpp
```c++
void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
        return;

    _energyPoints--;
    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}
```
In ScavTrap.cpp
```c++
void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
        return;

    _energyPoints--;
    std::cout << "ScavTrap " << _name
              << " fiercely attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}
```
👉 stesso schema
👉 messaggio diverso

### In C++ esistono tre livelli di accesso: private, protected e public.

- private: i membri sono accessibili solo all’interno della classe stessa.
- protected: i membri sono accessibili dalla classe e dalle sue classi derivate, ma non dall’esterno.
- public: i membri sono accessibili da qualsiasi parte del programma.

Nel modulo C++ 03, i membri di ClapTrap sono dichiarati come protected
per permettere alle classi derivate (come ScavTrap) di riutilizzarli e
modificarli, mantenendo comunque l’incapsulamento e impedendo l’accesso
diretto dal main.

**Perché protected è giusto qui?**
private: accessibile solo dentro ClapTrap
protected: accessibile dentro ClapTrap e dentro le classi derivate (ScavTrap)
public: accessibile da tutti

# 1️⃣ Cos’è davvero una classe derivata (non “in teoria”, ma in C++)
Quando scrivi:
```c++
class ScavTrap : public ClapTrap
```
stai dicendo al compilatore:
“ScavTrap contiene un ClapTrap ed è un ClapTrap”
Questo implica tre cose automatiche:
**ScavTrap eredita dati e funzioni di ClapTrap**
**ClapTrap viene costruita prima**
**ClapTrap viene distrutta dopo**

# 2️⃣ Sintassi base dell’ereditarietà
```c++
class Derived : public Base
{
    // contenuto
};
```
Nel tuo progetto:
```c++
class ScavTrap : public ClapTrap
```
Perché public?
Perché vuoi che:
```c++
ScavTrap s;
ClapTrap* c = &s; // OK
```
👉 Questo è fondamentale per ex02 (polimorfismo)

# 3️⃣ Cosa eredita una classe figlia?
🔹 Eredita automaticamente:
tutti i membri protected
tutti i membri public
tutte le funzioni non private
🔹 NON eredita:
i membri private (esistono, ma non li puoi toccare)
i costruttori (devono essere chiamati)
il distruttore (ma viene eseguito!)

# 4️⃣ Costruttori: cosa cambia davvero
Regola ferrea del C++:
👉 Il costruttore della classe base viene SEMPRE chiamato per primo
Sintassi corretta
```c++
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
}
```
Se NON scrivi : ClapTrap(name):
viene chiamato il costruttore di default della base
se non esiste → errore di compilazione

# 5️⃣ Override delle funzioni 
Caso: attack()
In ClapTrap:
```c++
void attack(const std::string& target);
```
In ScavTrap:
```c++
void attack(const std::string& target);
```
**👉 stessa firma = override**
⚠️ In ex01 NON è ancora polimorfismo vero
È function hiding controllato

# 6️⃣ Virtual
**🔥 Perché il distruttore diventa virtual?**
Problema reale (senza virtual)
```c++
ClapTrap* ptr = new ScavTrap("Bob");
delete ptr;
```
Se il distruttore NON è virtual:
**viene chiamato solo ~ClapTrap()**
**~ScavTrap() NON viene chiamato**
**→ memory leak / UB**
Soluzione:
```c++
class ClapTrap
{
public:
    virtual ~ClapTrap();
};
```
👉 Ora il C++ dice:
“Se distruggi tramite un puntatore alla base, chiama il distruttore giusto”

⚠️ Regola d’oro (fondamentale)
**Se una classe ha anche solo UNA funzione virtuale, il distruttore DEVE essere virtuale**

# 7️⃣ Cosa cambia quando aggiungi virtual
Prima 
```c++
ClapTrap* c = new ScavTrap;
c->attack("enemy"); // ClapTrap::attack
//Dopo
virtual void attack(const std::string& target);
```
Ora:
```c++
ClapTrap* c = new ScavTrap;
c->attack("enemy"); // ScavTrap::attack
```
👉 Questo è **polimorfismo**

### Il problema reale senza virtual (questo è il punto chiave)
Guarda questo codice:
```c++
ClapTrap* ptr = new ScavTrap("Bob");
delete ptr;
```
⚠️ Domanda cruciale:
Quale distruttore viene chiamato?
❌ SENZA virtual
Il tipo del puntatore è ClapTrap*
Il compilatore chiama solo ~ClapTrap()
~ScavTrap() NON viene chiamato
👉 Risultato: distruzione incompleta → bug serio

### La soluzione: virtual
Dichiarazione corretta
```c++
class ClapTrap {
public:
    virtual ~ClapTrap();
};
```
Ora il C++ dice:
“Aspetta, questa funzione è virtuale: decido a runtime.”
Cosa succede ora?
```c++
delete ptr;
Ordine reale:
~ScavTrap()
~ClapTrap()
```
👉 distruzione completa e corretta

**Regola d’oro (da ricordare SEMPRE)**
🔥 Se una classe base è usata polimorficamente, il distruttore DEVE essere virtuale
In parole semplici:
```c++
se fai Base* = new Derived
virtual destructor obbligatorio
```
# Funzioni virtuali (non solo il distruttore)
Una funzione virtuale permette al C++ di scegliere a runtime quale versione chiamare.
Senza virtual
```c++
class ClapTrap {
public:
    void attack(const std::string& target);
};
ClapTrap* c = new ScavTrap;
c->attack("enemy"); // ClapTrap::attack
```
Con virtual
```c++
class ClapTrap {
public:
    virtual void attack(const std::string& target);
};
ClapTrap* c = new ScavTrap;
c->attack("enemy"); // ScavTrap::attack
```
👉 Questo è polimorfismo

```c++
```