# homework1

# Corso Cyberfisico univr
- Autore: Moreno Bragaglio
- Data: 15/04/2018

# Esecuzione
L'esecuzione del programma avviene attraverso l'uso di un launch file situato in "launch/homework1.launch". Per eseguirlo basta lanciare il comando "roslaunch <nome_package> homework1.launch" da terminale.
Tale launcher si preoccupa di avviare tutti i nodi necessari.

# Progettazione
Sono stati implementati tre nodi server1, server2, client. I nodi server1 e server2 comunicano con il nodo client il quale a sua volta visualizza a video il risultato del programma. 

# server1.cpp
Nodo che pubblica un messaggio (campi: nome, età, corso di studi) alla frequenza di 1Hz sul topic "server1Topic". Tale messaggio è situato al path "msg/messaggio.msg". 

# server2.cpp
Nodo che pubblica (alla frequenza di 1Hz) sul topic "server2Topic" un messaggio composto da una carattere. Tale carattere, digitato da tastiera dall'utente, ha possibilità di essere:
	a - Print all message
	c - Print course of study
	e - Print age
	n - Print name	
	q - Exit
 
# client.cpp 
Nodo che:
	- Ascolta il topic "server1Topic" dal quale riceve la stringa completa.
	- Ascolta il topic "server2Topic" dal quale riceve il carattere per seleziona una parte (completa o no) di stringa.
	- Stampa il risultato a video alla frequenza di 1Hz.
