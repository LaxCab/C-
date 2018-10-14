/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passagier.cpp
 * Author: Joel
 * 
 * Created on 14. Oktober 2018, 14:17
 */

#include "Passagier.h"
#include <iostream>
#include <string>
#include <cstdlib>

int count=0;

Passagier::Passagier() {
}

Passagier::Passagier(std::string name) {
    Name = name;
    Buchungsnummer = getNewBookingnumber();
}

int Passagier::getNewBookingnumber() {
    count++;
    return count;
}

std::string Passagier::getName() {
    return Name;
}

int Passagier::getBuchungsnummer() {
    return Buchungsnummer;
}

Passagier::Passagier(std::string name, std::string nr) {
    Name = name;
    Buchungsnummer = std::atoi(nr.c_str());    
}

