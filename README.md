# Projet Initial de Système Embarqué - Projet Final

## Résumé du Projet

Ce projet consiste en la collaboration de deux robots pour effectuer un tracé précis d’un circuit.  
- **Robot 2** mesure les longueurs des segments en suivant un circuit prédéfini grâce au capteur Makerline et enregistre ces données en mémoire.  
- **Robot 1** reçoit ces données via un protocole infrarouge (Sirc) et dessine le tracé complet des segments.  
Des états spécifiques ont été implémentés pour permettre aux robots d’adapter leurs comportements selon les différentes étapes de l’épreuve.

---

## Classes Utilisées

### 1. Classe `Chronomètre`
**Description** :  
Cette classe programme le Timer1 du microcontrôleur pour mesurer le temps écoulé, utilisé dans diverses opérations de contrôle et de synchronisation du robot.

**Identifications Matérielles** :  
- Broches **D4** et **D5** : Utilisées pour Timer1.

---

### 2. Classe `Déplacement`
**Description** :  
Cette classe contrôle le suivi de ligne du robot 2 en utilisant le capteur Makerline. Elle ajuste la trajectoire et mesure les longueurs des segments avec le chronomètre.

**Identifications Matérielles** :  
- Broches **D4** et **D5** : Utilisées pour Timer1 du chronomètre.  
- Broches **PC2 à PC6** : Utilisées pour le capteur Makerline.  
- Broches **D6 et D7** : Utilisées pour les moteurs et le mouvement des roues.

---

### 3. Classe `Dessin`
**Description** :  
Cette classe génère un tracé basé sur les données des segments mesurés par le robot 2.

**Identifications Matérielles** :  
- Broches **C0** et **C1** : Réservées pour la mémoire.

---

### 4. Classe `Envoie`
**Description** :  
Implémente le protocole Sirc pour envoyer les données des segments mesurés par le robot 2 au robot 1.

---

### 5. Classe `Infrarouge`
**Description** :  
Permet au robot 1 de recevoir les données envoyées par le robot 2 via le protocole infrarouge.

**Identifications Matérielles** :  
- Broche **PD3** : Connectée au récepteur infrarouge.

---

### 6. Classe `Makerline`
**Description** :  
Gère les comportements spécifiques en fonction des capteurs activés du suiveur de ligne Makerline.

**Identifications Matérielles** :  
- Broches **PC2 à PC6** : Réservées pour le suiveur de ligne.

---

### 7. Classe `Robot 1`
**Description** :  
Contrôle les états et les actions du robot 1 en fonction des différents stades de l’épreuve finale.  

**Identifications Matérielles** :  
- **D4, D5** : Timer1.  
- **PC2 à PC6** : Capteur Makerline.  
- **D6, D7** : Moteurs et mouvement des roues.  
- **PA0, PA1** : DEL.  
- **PA4, PA5** : Son.

---

### 8. Classe `Robot 2`
**Description** :  
Contrôle les états et les actions du robot 2 en fonction des différents stades de l’épreuve finale.

**Identifications Matérielles** :  
- **D4, D5** : Timer1.  
- **PC2 à PC6** : Capteur Makerline.  
- **D6, D7** : Moteurs et mouvement des roues.  
- **PA0, PA1** : DEL.  
- **PA4, PA5** : Son.  
- **C0, C1** : Mémoire.

---

### 9. Classe `SircProtocol`
**Description** :  
Implémente le protocole Sirc pour la transmission de données.

**Identifications Matérielles** :  
- **C0, C1** : Mémoire.  
- **D4, D5** : Timer1.

