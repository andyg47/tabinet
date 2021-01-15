# tabinet
Tabinet / Tablanette / Tablic C++ Simple Implementation
I uploaded this on github because someone might need it for school, as a model, because I had this assignment myself and couldn't find this anywhere. 
I hope it is useful to you, and I hope the explanations are clear enough, as English is not my main language.
This is a simple implementation of the Tablanette game, played by the Eastern European set of rules. 
Perfect functionality, but be careful when picking cards to not input wrong index because there is no input validation there ( maybe I will add it in the future)
- 2 / 3 / 4 players
- first player can see the first 4 of his cards, if he likes them he can keep them. Otherwise they will be placed on the board.
- after the first player, everyone receives 6 cards, and they start playing taking turns
- during your turn you have to either take one or more cards from the board, or drop one card on the board
- after the start, the only way the board can get more cards is from players
- when the players run out of cards, they get 6 more cards each, or, if the pack does not have that many, the remaining cards are shared as equally as possible
- you can sweep the table for a "tabla" which is an additional point at the end
- 10s, Aces, Jacks, Queens and Kings are worth 1 point
- each collected club card is worth an additonal point
- 10 of Diamonds and 2 of Clubs are called "cows" and are worth 2 points
- the player with most collected cards receives an additional 3 points. If two have tied for the most cards, they both receive the points.
- Winner is the one with most points.