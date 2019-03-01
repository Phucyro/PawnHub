
#TODO:

- mieux gerer les exceptions/erreurs de client/serveur (ex: mauvais hostname, deconnection)
- gerer tous les autres messages de jeu
  - faits: board, move, turn
  - en cours: game mode, player colour (biens recus mais probleme d'affichage)
  - a faire: promotion
  --> prevenir des changements faits dans Code (update de \_start(); methodes pures de Game: \_sendGameMode; methodes virtuelles mais definies: \_sendStart, \_sendPlayerColour, \_sendTurn) (methodes de Player: transferStart, transferCheck, transferCheckmate, transferStalemate, transferGameMode, transferColour, transferTurn)

- reine ne se deplace pas en horizontale de + d'une case

##Messages

padding symbol defined: '|'
- _cannot be used for anything else in messaging_
- for example, cannot be allowed in chat (though use is limited really - but still possible)

send board to clients
- list of pieces, first white then black, separated by '!' then '#'
- each piece 3 characters:
* name of piece (one letter)
* position (one letter one number _classic chess representation_)

send move to server
- 4 characters total, initial position and final position
- position: letter-number combination, classic chess representation
