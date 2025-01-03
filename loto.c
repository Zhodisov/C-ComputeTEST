#include <stdio.h>

struct motorisation {
  char motorisation[20], puissance[20];
  int couplemaxi, rapport, cylindre;
  char carburant[20];
};
struct consommations {
  int CO2, Consommation_combinee;
};
struct performances {
  int vitesse_maxi, zerotohundred, onethousand;
};
struct poids {
  int poidstotal, poidsmax, charge_utile;
};
struct autres {
  int places, portes, puissanceadmin;
};

int main() {
  struct motorisation Moteur = {
    "ECO-G 100 4x2",
    "74 (100)",
    "170",
    "6",
    "999",
    "Essence + GPL"
  };
  struct consommations Consommation = {
    "125/127",
    "7,8"
  };
  struct performances Performance = {
    "168",
    "13,8",
    "36,2"
  };
  struct poids Poids = {
    "2973",
    "685",
    "450"
  };
  struct autres Autres = {
    "5",
    "5",
    "5"
  };
  printf("Moteur : \n\n motorisation : %s\nPuissance maxi kW (ch) : %s\nCouple maxi Nm (m.kg) : %s \nNombre de rapports A.V. : %s\nCylindrée (cm3) : %s\nCarburant : %s\n\n\n Consommation :\n\nCO2 combiné WLTP min/max (g/km): %s\nConsommation combinée WLTP min/max (l/100km) : %s \n\n\nPerformance :\n\nVitesse maxi (km/h) : %s\n0 - 100 km/h (s) : %s\n1000 m D.A. (s) : %s\n\n\nPoids : \n\nPoids total roulant (kg) : %s\nPoids maxi remorquable non freiné (kg) : %s\nCharge utile (kg) : %s\n\n\nAutres :\n\nNombre de places : %s\nNombre de portes : %s\nPuissance administrative : %s\n\n\n", Moteur.motorisation, Moteur.puissance, Moteur.couplemaxi, Moteur.rapport, Moteur.cylindre, Moteur.carburant, Consommation.CO2, Consommation.Consommation_combinee,Performance.vitesse_maxi, Performance.zerotohundred, Performance.onethousand, Poids.poidstotal, Poids.poidsmax, Poids.charge_utile, Autres.places, Autres.portes, Autres.puissanceadmin);


  return 0;
}
