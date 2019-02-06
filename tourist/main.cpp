//
//  main.cpp
//  tourist
//
//  Created by Mandip on 2/6/19.
//  Copyright © 2019 Mandip. All rights reserved.
//

#include <map>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Welcome to the program\n";
    int choice;
    int sum = 0;
    int sum_region = 0;
    float percentage;
    
    /*array for months*/
    std::string months[11] = {"january","february","march","april","may","june","july","august","september","october","november"};
    
    
    /*array for region*/
    std::string regions[5] = {"america","north asia"," south asia","sea","europe"};
    
    /*map for month*/
    std::map<std::string, int> month_d;
    
    month_d["january"] = 0;
    month_d["february"] = 1;
    month_d["march"] = 2;
    month_d["april"] = 3;
    month_d["may"] = 4;
    month_d["june"] = 5;
    month_d["july"] = 6;
    month_d["august"] = 7;
    month_d["September"] = 8;
    month_d["october"] = 9;
    month_d["november"] = 10;
    
    /*map for region*/
    
    std::map<std::string, int>region_d;
    region_d["america"] = 0;
    region_d["north asia"] = 1;
    region_d["south asia"] = 2;
    region_d["sea"] = 3;
    region_d["europe"] = 4;
    
    
    
    double tourist[5][11] = { {66989,58800,63522,52572,50578,56233,59258,48662,42906,53083,60398},
        {439263,496263,448872,437919,404418,401490,550233,588866,338923,329529,348543},
        {103184,82979,9974,121482,164574,130190,115028,107284,97421,119033,114255},
        {473005,440597,499023,516059,541795,493491,607295,447760,413205,471598,465946},
        {179863,173341,181949,14918,103923,86145,140263,167958,123101,149419,144980}
    };
    
    
    std::cout << "What is your choice?" << std::endl;
    std::cout << "[1]Total Tourist arriaval of a selected month" <<std::endl;
    std::cout << "[2]Percentage of tourist arrival from a region on a selected month"<<std::endl;
    std::cout << "[3]Quaterly average arrival of tourist from a selected region" <<std::endl;
    std::cout << "[4]Lowest tourist arrival from a selected region "<<std::endl;
    std::cout << "[5]Ratio of tourist arrival between North Asia and Sea" <<std::endl;
    std::cin >> choice;
    std::cout << "Your choice was: " << choice <<std::endl;
    
    std::string month_a;
    std::string region_a;
    
    switch (choice) {
        case 1:{
            
            std::cout << "Which month ? \n";
            std::cin >> month_a;
            
            for (int i = 0; i < 5; i++) {
                sum += tourist[i][month_d[month_a]];
            }
            std::cout << "Total arrival was: "<<sum<<std::endl;
            break;
        }
            
        case 2:{
            std::cout << "Which month ? \n";
            std::cin >> month_a;
            std::cout << "Which region ? \n";
            std::cin >> region_a;
            
            for (int i = 0; i < 11; i++) {
                sum_region += tourist[region_d[region_a]][i];
            }
            
            percentage = (tourist[region_d[region_a]][month_d[month_a]] / sum_region)*100;
            
            std::cout << "The percentage was: " << percentage <<"%"<<std::endl;
            break;
        }
            
            
        case 3:{
            int sum_q1 = 0;
            int sum_q2 = 0;
            int sum_q3 = 0;
            int sum_q4 = 0;
            double avg_q1;
            double avg_q2;
            double avg_q3;
            double avg_q4;

            
            std::cout << "Which month ? \n";
            std::cin >> month_a;
            std::cout << "Which region ? \n";
            std::cin >> region_a;
            
            for (int i=0; i < 11; i++){
                if (i < 3){
                    sum_q1 += tourist[region_d[region_a]][i];
                    avg_q1 = sum_q1 / 3;
                }
                if (2 < i && i < 6) {
                    sum_q2 += tourist[region_d[region_a]][i];
                    avg_q2 = sum_q2 / 3;
                    
                }
                if (5< i && i < 9) {
                    sum_q3 += tourist[region_d[region_a]][i];
                    avg_q3 = sum_q3 / 3;
                }
                if (8< i && i < 11){
                    sum_q4 += tourist[region_d[region_a]][i];
                    avg_q4 = sum_q4 / 2;
                }
            }
            
            double quaterly[4] = {avg_q1,avg_q2,avg_q3,avg_q4};
            
            
            std::cout << "The quarterly average is as :" << quaterly[0] <<", " << quaterly[1] << ", " << quaterly[2] << ", " << quaterly[3]<< std::endl;
        
            break;
        }
        case 4:{
            
            int lowest;
            int month_i;
        
            std::cout << "which region ?";
            std::cin >> region_a;
            
            lowest = tourist[region_d[region_a]][0];
            for (int i = 0; i < 11; i++){
                if (tourist[region_d[region_a]][i] < lowest){
                    lowest = tourist[region_d[region_a]][i];
                    month_i = i;
                    
                }
            }
            std::cout << "Lowest arrival: "<< lowest<<std::endl;
            std::cout << "Lowest arrival was on: "<<months[month_i]<<std::endl;
            break;
        }
        case 5:{
            break;
            
        }
    }
    
    
}

