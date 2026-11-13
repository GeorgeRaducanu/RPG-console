# Design overview

## Implemented

- **Dependency Injection** — `App` primește `std::istream` și `std::ostream`
  și le transmite către `ConsoleUI`. Permite testarea fără consola reală. (not DP)

## Patterns

- **Factory Method** [x] — fabrici concrete creează personaje, inamici și iteme.
- **Strategy** [x] — selectează algoritmul de atac pentru Warrior, Mage și Archer.
- **Command** [x] — `App` este Invoker-ul, păstrează `AttackCommand`, iar
  `AttackReceiver` execută `Attack`; `UseItemCommand` execută folosirea
  Potion-ului printr-un receiver separat.
- **State** — separă meniul, explorarea, lupta și finalul jocului.
- **Observer** — transmite evenimente precum damage, moarte și level-up.
- **Decorator** — adaugă efecte precum Poison și Buff.
