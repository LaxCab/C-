/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flug.h
 * Author: Joel
 *
 * Created on 14. Oktober 2018, 14:16
 */

#ifndef FLUG_H
#define FLUG_H
#include <vector>
#include "Passagier.h"


class Flug {
public:
    Flug();
    void addPassagier(std::string);
    void removePassagier(int);
    std::vector<Passagier> getPassengerList();
    const int getMAX_SEATS();
    void saveBookings();
    void loadBookings();
    void clearBookings();
private:
    std::vector<Passagier> passagierListe;
    const int MAX_SEATS = 5;
};

#endif /* FLUG_H */

