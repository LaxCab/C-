/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flug.cpp
 * Author: Joel
 * 
 * Created on 14. Oktober 2018, 14:16
 */

#include "Flug.h"
#include "Passagier.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

Flug::Flug() {
}

void Flug::addPassagier(std::string name) {
    Passagier p(name);
    passagierListe.push_back(p);
}

std::vector<Passagier> Flug::getPassengerList() {
    return passagierListe;
}

const int Flug::getMAX_SEATS() {
    return MAX_SEATS;
}

void Flug::removePassagier(int toremove) {
    std::vector<Passagier> myList = getPassengerList();
    bool found = false;
    
    
    for (int i = 0; i < myList.size(); i++) {
        if(toremove == myList[i].getBuchungsnummer()){
            found = true;
            Passagier todelete = myList[i];
            myList.erase(myList.begin() + i);
            passagierListe = myList;
            
            std::cout << "Folgende Buchung wurde erfolgreich storniert:" << std::endl
                      << "Name: " << todelete.getName() << std::endl
                      << "Buchungsnummer: " << todelete.getBuchungsnummer() << std::endl;
        }
    }
        if(!found){
            std::cout << "Keine Buchung mit der Buchungsnummer " << toremove << " vorhanden." << std::endl;
    }
}

void Flug::saveBookings() {
    std::ofstream file;
    file.open("C:/Users/Joel/Desktop/Bookings.txt");
    std::string tosave = "Name;Buchungsnummer";
    
    for (int i = 0; i < passagierListe.size(); i++) {
        tosave = tosave + "\n" + passagierListe[i].getName() + ";" + std::to_string(passagierListe[i].getBuchungsnummer());
    }
    int plaetzefrei = MAX_SEATS - passagierListe.size();
    for (int i = 0; i < plaetzefrei; i++) {
        tosave = tosave + "\n(-);(-)";
    }

    file << tosave;
    file.close();
}

void Flug::loadBookings() {
  std::ifstream file;
    std::string tosave;
    file.open("C:/Users/Joel/Desktop/Bookings.txt");
    if(file.is_open()){
        
        clearBookings();
        int counter=0;
        
        while(std::getline(file,tosave)){
            if(!(tosave=="Name;Buchungsnummer")){
                std::string name = tosave.substr(0,tosave.find(";"));
                std::string nr = tosave.substr(tosave.find(";")+1,tosave.length());
                
                //std::cout << name << "_" << nr << std::endl;
                
                if(((!(name == "(-)"))
                   ||(!(nr == "(-)")))
                   &&(counter<MAX_SEATS)){
                    Passagier p(name, nr);
                    passagierListe.push_back(p);
                    counter++;
                }
            } 
        }
        file.close();
    
}else{
        std::cerr << "Fehler beim Öffnen der Datei!";}
}


void Flug::clearBookings() {
    getPassengerList().clear();
}
