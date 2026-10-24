# Game overview

## Scop

`Dungeon of Echoes` este un mini-RPG jucat în consolă. Jucătorul alege o clasă,
explorează opt camere și luptă cu inamicii întâlniți.

## Jucătorul

Jucătorul se numește `Hero` și poate alege una dintre clase:

- **Warrior**: mult HP, atac și apărare bune;
- **Mage**: HP și apărare mai mici, dar MP ridicat și skill-uri magice;
- **Archer**: valori echilibrate și skill-uri care pot aplica Poison.

Jucătorul are HP, MP, ATK, DEF, nivel, XP și inventar.

## Explorare

Dungeon-ul are opt camere parcurse în ordine:

1. Goblin
2. Cameră goală
3. Potion
4. Orc
5. Sword
6. Goblin
7. Elixir
8. Dragon

## Luptă

Lupta se desfășoară pe ture. Jucătorul poate:

- să atace;
- să folosească un skill;
- să folosească un item;
- să fugă, cu excepția luptei cu Dragonul.

Inamicii folosesc doar atacul simplu. Damage-ul obișnuit este calculat astfel:

```
max(1, ATK - DEF)
```

Jocul se termină cu **Game Over** când HP-ul lui Hero ajunge la zero.
Victoria apare după înfrângerea Dragonului.

## Iteme și progresie

- **Potion**: reface HP;
- **Sword**: crește permanent ATK;
- **Elixir**: crește temporar ATK.

În urma luptelor, Hero primește XP. La acumularea XP-ului necesar crește
nivelul, iar HP max, ATK și DEF sunt mărite.
