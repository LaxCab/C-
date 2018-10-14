/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passagier.h
 * Author: Joel
 *
 * Created on 14. Oktober 2018, 14:17
 */

#ifndef PASSAGIER_H
#define PASSAGIER_H
#include <string>


class Passagier {
public:
    Passagier();
    Passagier(std::string);
    Passagier(std::string,std::string);
    std::string getName();
    int getBuchungsnummer();
private:
    std::string Name;
    int Buchungsnummer;
    int getNewBookingnumber();
};

#endif /* PASSAGIER_H */

