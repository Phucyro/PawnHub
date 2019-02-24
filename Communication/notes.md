
#TODO:

- envoyer les messages de la meme maniere pour chaque partie (jeu/admin)
- idealement avoir une instance de controle admin qui gere les envois/receptions de messages
  - et laisse la main au controle de jeu quand un jeu est en cours
  - comment gerer le chat comme ca?
- mieux gerer les exceptions/erreurs de client/serveur (ex: mauvais hostname, deconnection)
- gerer deux clients sur le meme jeu (_le plus gros qui reste_)

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

##Two Clients on the Same Game

potentially threading rather than forking

identify two connected clients
pass control to game control instance
