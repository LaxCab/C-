/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menue.cpp
 * Author: Joel
 * 
 * Created on 14. Oktober 2018, 14:16
 */

#include "Menue.h"
#include <iostream>
#include "Flug.h"
#include <vector>

Flug myFlight;

Menue::Menue() {
    myFlight.loadBookings();
    show();
}

void Menue::show() {
    std::cout   << "Menü:" << std::endl
                << "\t (a) Flug buchen" << std::endl
                << "\t (b) Flug stornieren" << std::endl
                << "\t (c) Anzeige aller Buchungen" << std::endl
                << "\t (d) Beenden" << std::endl
                << "Wähle eine Option: ";
    
    char auswahl;
    std::cin >> auswahl;
    
    switch(auswahl){
        case('a'):
            bookFlight();
            break;
        case('b'):
            cancelFlight();
            break;
        case('c'):
            showBookings();
            break;
        case('d'):
            endMenue();
            break;   
        default:
            std::cout << "Ungültige Eingabe!" << std::endl;
            show();
            break;
    }
}

void Menue::bookFlight() {
    std::cout << "Flug buchen:" << std::endl
              << "\t Name des Passagiers eingeben: ";
    
    std::string name;
    std::cin >> name;
    
    if(myFlight.getPassengerList().size() < myFlight.getMAX_SEATS()){
        myFlight.addPassagier(name);
        
        std::cout << "Buchung erfolgreich: " << std::endl
             << "Name: " << myFlight.getPassengerList().back().getName()  << std::endl
             << "Buchungsnummer: " << myFlight.getPassengerList().back().getBuchungsnummer() << std::endl;
        
    }
    else {
        std::cout << "Der Flug ist leider schon ausgebucht." << std::endl;        
    }
    show();
}

void Menue::cancelFlight() {
    std::cout << "Flug stornieren:" << std::endl
              << "\t Buchungsnummer eingeben: ";
    
    int nr;
    std::cin >> nr;
    
    myFlight.removePassagier(nr);
    
    show();
}

void Menue::showBookings() {
    std::cout << "Anzeige aller Buchungen:" << std::endl
              << "\tPosition\tName\t\tBuchungsnummer" << std::endl;
    
    std::vector<Passagier> myList = myFlight.getPassengerList();
    
    for (int i = 0; i < myList.size(); i++) {
        std::cout << "\t" << i + 1 << "\t"
             << "\t" << myList[i].getName() << "\t"
             << "\t" << myList[i].getBuchungsnummer() << std::endl;
        
    }
    
    int plaetzeuebrig = myFlight.getMAX_SEATS() - myList.size();
    
    for (int i = 0; i < plaetzeuebrig; i++) {
        std::cout << "\t" << i+1 + myList.size() << "\t"
             << "\t" << "leer" << "\t"
             << "\t" << "leer" << std::endl;

    }


    show();
}

void Menue::endMenue() {
    myFlight.saveBookings();
}




