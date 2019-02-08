
#TODO:

- definir les messages envoyes (board et move)
- ecrire send et receive
- caser le parser
- gerer deux clients sur le meme jeu (_le plus gros qui reste_)

##Messages

send board to clients
- list of pieces, first white then black, separated by '!' symbol
- each piece 3 characters:
* name of piece (one letter/number, _undetermined as of yet_)
* position (one letter one number OR two numbers, _either classic chess representation or matrix position_)
- padding since message of defined length (_determine symbol_)

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
