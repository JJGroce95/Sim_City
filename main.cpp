#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "industrial.h"
#include "pollution.h"
#include "residential.h"
#include "commercial.h"
using namespace std;

int getLimit()
{
    int resp;   //response
    cout << "|Enter how many iterations you want of the simulation:\t";
    cin >> resp;
    //Error check for input
    while(resp <= 0)
    {
        cout << "!!ERROR!!\tPlease enter a value greater than 0:\t";
        cin >> resp;
    }
    cout << "|Running simulation...." << endl;
    cout << "------------------------------" << endl;
    return resp;
}
void showPop(vector<vector<int>>initPop, vector<vector<char>> map)
{
    for (int i = 0; i < initPop.size(); i++) 
    { 
        for (int j = 0; j < initPop[i].size(); j++) 
		{
			if(initPop[i][j] == 0)
			{
				cout << map[i][j] << " ";
			}
			else
			{
			cout << initPop[i][j] << " "; 
			}
		}
		cout << endl;
    } 
}
void countZones(vector<vector<char>>map)
{  
    int     R=0, C=0, I=0;          //init counters of Res, Com, Ind cells
    for(int i = 0; i<map.size(); i++)
    {
        for(int j = 0; j<map[i].size();j++)
        {
            if(map[i][j] == 'R')   //if element == residential
            {
                R++;
            }
            else if(map[i][j] == 'I')   //if element == industrial
            {
                I++;
            }
            else if(map[i][j] == 'C') //if element == Commercial
            {
                C++;
            }
        }
    }
    //Map Data
    cout << "|Dimensions of Map:\t" << map.size() << " x " << map[0].size() << endl << endl;
    cout << "|Residential Zones:\t" << R << endl;
    cout << "|Industrial Zones:\t" << I << endl;
    cout << "|Commercial Zones:\t" << C << endl;
    cout << "------------------------------" << endl;
    
    
}
void totPop(vector<vector<int>>initPop, vector<vector<char>> map)
{
    int sumR = 0, sumC = 0, sumI = 0;
    
    for(int i = 0; i<initPop.size(); i++)
    {
        for(int j = 0; j<initPop[i].size();j++)
        {
            if(map[i][j] == 'R')
            {
                sumR+=initPop[i][j];
            }
            else if(map[i][j] == 'C')
            {
                sumC+=initPop[i][j];
            }
            else if(map[i][j] == 'I')
            {
                sumI+=initPop[i][j];
            }
        }
    }
    cout << "|Total Population:\t" << sumR+sumC+sumI << endl;
    cout << "|Residential:\t" << sumR << endl;
    cout << "|Commercial:\t" << sumC << endl;
    cout << "|Industrial:\t" << sumI << endl;
}

int main()
{
    Industrial Ind;
    Commercial Com;
    Residential Res;
    
    string line;
    int refresh = 0, limit = 0, //refresh, limit
    avWork = 0, goods = 0;      //available workers, goods

    //open file
    char filenm[50];
	char data[300];

	cout << "|Enter Configuration file: " << endl;
	cin >> filenm;

	ifstream infile;
	infile.open(filenm);
	//map vector to hold file
	vector<vector<char>> map;
    
    //vector takes the data from the CSV file, gets rid of the ',' and assigns to the map vector
    while (getline(infile, line)) 
    {
        vector<char> row;

        for (char &c : line) 
        {
            if (c != ',') 
            {
                row.push_back(c);
            }
        }

        map.push_back(row);
    }

    for (vector<char> &row : map) 
    {
        for (char &c : row) 
        {
            cout << c << ' ';
        }

        cout << endl;
    }
   
    //creation of population vector based on the dimensions of the map
    vector<vector<int>> initPop(map.size(),vector<int>(map[0].size(),0));
    
    //initialization of 'tempVec' so as to hold the next iteration of population
    vector<vector<int>> tempVec = initPop;
    
    //declare Pollution and send dimensions of population to the constructor
    Pollution Pol(initPop.size(), initPop[0].size());
    
    //count and cout zone #s
    countZones(map);
    
    limit = getLimit();
    while(refresh<limit+1)
    {
        cout << "\t|Day " << refresh << "|" << endl;
        cout << "|Avail Workers:\t" << avWork << endl;  
        cout << "|Goods:\t" << goods << endl;
 
        for(int i = 0; i<map.size(); i++)
        {


            for(int j = 0; j<map[i].size(); j++)
            {
                if(map[i][j] == 'R')    //if element == residential Cell
                {
                    //populate based on industrial requirements
                    Res.populate(i,j,initPop, map, tempVec, avWork);
                }
            }
            for(int j = 0; j<map[i].size(); j++)
            {
                if(map[i][j] == 'C')    //if element == commercial Cell
                {
                    //populate based on commercial requirements
                   Com.populate(i,j,initPop, map, tempVec, avWork, goods);
                }
            }
            for(int j = 0; j<map[i].size(); j++)
            {
                if(map[i][j] == 'I')    //if element == Industrial Cell
                {
                    //populate based on industrial requirements
                    Ind.populate(i,j,initPop, map, tempVec, avWork, goods);
                }
            }
            for(int j = 0; j<initPop[i].size(); j++)
            {
                Pol.populate(i, j, initPop);
            }
        }
        //updates pollution for next iteration
        Pol.update();
        showPop(initPop, map);
    
        //updates for next iteration
        initPop = tempVec;

        refresh++;
    }
    
    //display total of population, then population by zone type, then total pollution
    totPop(initPop, map);
    int showPollution = Pol.totalPollution();
    cout << "|Total Pollution\t" << showPollution << endl;
    cout << "-----------------------------------------" << endl;
    
    return 0;
}