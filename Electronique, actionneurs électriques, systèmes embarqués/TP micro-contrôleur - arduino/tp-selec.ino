#include <LiquidCrystal.h>;
#include <TimerOne.h>;

LiquidCrystal lcd (18,17,16,15,14,19);

const int pinA = 0; // Pin signal A du encodeur
const int pinB = 1; // Pin signal B du encodeur
const int pinClic = 2; // Pin signal Button du encodeur
const int pinPWM = 23; // Pin du signal PWM

int c = 0; // Position do encodeur - compteur
int dernierA = 0; // État précédent de A
int dernierClic = 0; // État précédent de clic
int arret = 0; // Indique si on est dans la procedure de arrêt 
int demar = 0; // Indique si on est dans la procedure de démarrage 
int cint = 0; // Compteur interne du timer
int consigne = 0; // Consigne de la procedure de démarrage

void setup() {
  // lcd setup  
  lcd.begin(20,4);
  lcd.print("RIGUE et JEZLER");
  lcd.setCursor(0,1);

  // Setup des broches du encodeur
  pinMode(pinB,INPUT_PULLUP);
  pinMode(pinA,INPUT_PULLUP);
  pinMode(pinClic,INPUT_PULLUP);

  // Setup PWM
  analogWriteFrequency(pinPWM,25000); // broche 23 et 25 kHz
  analogWriteResolution(6); // 6 bits: 0 à 63

  // Mise à jour des varibles d'état de A et clic
  dernierA = digitalRead(pinA);
  dernierClic = digitalRead(pinClic);
  
  // Setup du timer
  Timer1.initialize(1000); // Initialisation du timer chaque 1000 micro seconds 
  Timer1.attachInterrupt(isr);
}

// Fonction de l'interruption
void isr () {
  int A = digitalRead(pinA); // lecture de la broche A
  int B = digitalRead(pinB); // lecture de la broche B
  int clic = digitalRead(pinClic); // lecture du button
  
  // 
  if (demar == 0 && arret == 0 && clic == HIGH) {
    if (dernierA != A && A == HIGH){ // On verifie s'il y a eu un changement en A et si A est HIGH
      if (B == LOW) {
        c ++; // sens horaire
      }  else if (B == HIGH){
        c --; // sens trigonometrique
      }
    }
  } 
 
  // On vérifie si les proceures de démarrage ou arrêt vont commencer en analysant si le signal 
  // clic est LOW et si le signal a changé (si il a changé, on vient appuyer le button)
  // Si c != 0 on ne peut que commencer la procedure d'arrêt 
  if ((clic == LOW && (clic != dernierClic)) && c != 0) {
    if (demar == 0) {
      arret = 1;
      consigne = c; // On enregistre la valeur de c à cet instant
    }
  // Si c == 0 on ne peut que commencer la procedure de démarrage 
  } else if ((clic == LOW && (clic != dernierClic)) && c == 0) {
    demar = 1;
  }

  // Procedure d'arrêt 
  if (arret == 1) {
    // On incrément le compteur interne du timer jusqu'à 100
    cint ++;
    if (cint == 100) {
      c--;
      // Si c == 0 la procedure d'arrêt est terminé 
      if (c == 0) {
        arret = 0;
      }
      cint = 0; // On met à 0 la valeur du compteur interne pour la prochaine iteration
    } 
  }

  // Procedure de démarrage 
  if (demar == 1) {
    // On incrément le compteur interne du timer jusqu'à 100
    cint ++;
    if (cint == 100) {
      c++;
      // Si c == consigne, c est arrivé à la valeur souhaitée la procedure d'arrêt est terminé
      if (c == consigne) {
        demar = 0;
      }
      cint = 0; // On met à 0 la valeur du compteur interne pour la prochaine iteration
    } 
    // On vérifie aussi à chaque iteration si le button a été appuyé
    // Dans ce cas, la procedure est fini
    if ((clic == LOW && (clic != dernierClic)) && c != 0) {
      demar = 0;
    }
  }

  // Mantenir le compteur entre 0 et 63
  if (c > 63) {
    c = 63;
  } else if (c < 0) {
    c = 0;
  }

  dernierA = A; // Mise à jour de la dernier valeur de dernierA
  dernierClic = clic; // Mise à jour de la dernier valeur de dernierClic
}

void loop() {
  // print du LCD
  lcd.print("   "); // Effacer les données précédentes 
  lcd.setCursor(0,1);
  lcd.print(c); // Affichage du compteur
  lcd.setCursor(0,1);


  // Signal PWM
  analogWrite(pinPWM, c);

  // Delay d'affichage do lcd
  delay(100);
  
}
