# Design overview

## Implemented

- **Dependency Injection** — `App` primește `std::istream` și `std::ostream`
  și le transmite către `ConsoleUI`. Permite testarea fără consola reală. (not DP)

## Planned patterns

- **Factory Method** — creează personaje, inamici și iteme.
- **Strategy** — separă algoritmii de atac și skill-uri.
- **Command** — reprezintă acțiunile jucătorului.
- **State** — separă meniul, explorarea, lupta și finalul jocului.
- **Observer** — transmite evenimente precum damage, moarte și level-up.
- **Decorator** — adaugă efecte precum Poison și Buff.
