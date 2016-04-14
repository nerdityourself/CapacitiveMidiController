

CONTROLLER MIDI CAPACITIVO - INDICAZIONI SOFTWARE


- Il file CapacitiveMidiController.ino contiene nei commenti informazioni per la
comprensione del codice e la sua personalizzazione.

- In questo tutorial il controller MIDI comunica con il software Ableton Live su Windows 10
  Per avere i dettagli su come configurare il vostro PC guardate i nostri tutorial sul canale Youtube
  su come connettere Arduino ad Ableton Live sulla piattaforma desiderata.
  
  Di seguito alcune indicazioni:
  
*** Mac OS X ***
  
- Deve essere scaricato il software Hairless MIDI http://projectgus.github.io/hairless-midiserial/
  che fa da ponte fra i messaggi seriali ricevuti da Arduino e il software di editing e produzione musicale
  In questo caso Ableton ma in generale permette la comunicazione con qualsiasi software gestisca
  controller MIDI.

- Devono essere attivato sul MAC il canale di comunicazione MIDI, Drive IAC
  Per farlo andare in Applicazioni > Utility > Configurazioni MIDI Audio > Finestra > Mostra finestra MIDI
  premere su Driver IAC e, nella finestra che si apre, spuntare la casella "Device is online"
 
- In Hairless MIDI dovete selezionare la porta a cui è connesso Arduino, e come MIDI IN e MIDI OUT
  il Driver IAC Bus 1
  
- Verificate che, tra le preferenze di Hairless MIDI, il baudrate per la comunicazione seriale sia lo stesso 
  che è impostato nel software di Arduino (ad esempio se Serial.begin(115200), allora deve essere impostato 115220 anche su Hairless MIDI )
  
- In Ableton Live, andare in Preferenze e nella sezione "MIDI SYNC", mettere a ON le voci "Track" e "Remote" 
  in corrispondenza di "IN: Driver IAC Bus 1" 

- Per mappare una qualsiasi azione eseguibile in Ableton su un brano, ad un tasto del controller, andate nella 
  sezione mappatura MIDI. Si accede premendo il tasto "MIDI" in alto a destra.
  Entrati in questa sezione basterà premere sull'azione che volete mappare e dopo sul tasto del controller, per mappare
  il tasto premuto all'azione scelta.

- Per suonare le note di uno strumento MIDI che avete importato nella colonna "MIDI" non serve nessuna mappatura
  (questo perchè è stata messa a ON la voce "Track" nelle preferenze MIDI). Basterà premere i tasti del controller e verranno
  riprodotte le note che avete associato ai tasti nel vostro codice su Arduino. 

- Se Ableton non dovesse vedere il controller o vi fossero problemi nella ricezione dei messaggi, verificate che tutto
  sia impostato correttamente nel software Hairless MIDI, e che i messaggi vengano effettivamente ricevuti da questo
  verificando, nella parte bianca del software che appaiano i messaggi ricevuti, e che le spie presenti
  sull'interfaccia diventino verdi ogni volta che viene ricevuto un messaggio.



 *** Windows ***
 
 - L'unica differenza rispetto a quanto detto per Mac OS X è che su Windows non sono presenti nativamente dai canali MIDI da attivare (ovvero qualcosa di analogo a Drive IAC).
   Quindi prima di tutto deve essere scaricato un driver che abbia questa funzione. Consigliamo il driver loopMIDI http://www.tobias-erichsen.de/software/loopmidi.html
   Una volta scaricato basta lanciarlo e verrà aperta la porta loopMIDI Port 1. 
   loopMIDI deve essere lanciato sempre, prima di utilizzare gli altri strumenti, per attivare il canale di comunicazione MIDI!
   Una volta attivato il canale troverete, fra le scelte di MIDI IN e MIDI OUT su Hairless MIDI, l'opzione loopMIDI Port 1.  
  

NerdItYourself 