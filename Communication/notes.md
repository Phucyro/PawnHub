
#TODO:

- mettre en commun les differentes methodes de message-handling (dans mon tout beau parser, idealement)
- tester en reseau local (using hostname?)
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
launch game
loop:
- send board to both players
- request move from first player
- receive move from first player
- send updated board to both players
- request move from second player
- receive move from second player
end game
