#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H
#include<iostream>
#include<vector>
using namespace std;

class Industrial
{
    public:
    void populate(int a, int b, vector<vector<int>> &initPop, vector<vector<char>> map, vector<vector<int>> &tempVec, int &avWork, int &goods)
    {
        if(initPop[a][b] == 0 && pLine(a,b,map) == true && avWork >=2)   
        {
            tempVec[a][b]++;
            avWork -=2;
            goods++;
        }
        else if(initPop[a][b]==0 && adjPop(a,b,initPop,1,1) == true && avWork >=2)
        {
            tempVec[a][b]++;
            avWork -=2;
            goods++;
        }
        else if(initPop[a][b]==1 && adjPop(a,b,initPop,1,2) == true && avWork >=2)
        {
            tempVec[a][b]++;
            avWork -=2;
            goods++;
        }
        else if(initPop[a][b]==2 && adjPop(a,b,initPop,2,4) == true && avWork >=2)
        {
            tempVec[a][b]++;
            avWork -=2;
            goods++;
        }
        else
        {
            return;
        }
    }
    
    bool pLine(int a, int b, vector<vector<char>> map)
    {
    //This setup does bound checking and prevents checking of..
    //..adjacent cells that do not exist
    
    //CORNERS
        //Top Left
        if(a==0 && b == 0)
        {
            if(indE(a, b, map) == true || indSE(a,b,map) == true || indS(a,b,map) == true)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        //Top Right
        else if(a == 0 && b == map[0].size()-1)
        {
            if(indS(a, b, map) == true || indSW(a,b,map) == true || indW(a,b,map) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //Bottom Right
        else if(a == map.size()-1 && b == map[0].size()-1)
        {
            if(indN(a, b, map) == true || indNW(a,b,map) == true || indW(a,b,map) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //Bottom Left
        else if(a == map.size()-1 && b == 0)
        {
            if(indE(a, b, map) == true || indNE(a,b,map) == true || indN(a,b,map) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    //BORDERS
        //Top
        else if(a==0 && 0<b<map[0].size()-1)
        {
            if(indE(a,b,map) == true || indSE(a,b,map) == true || indS(a,b,map) == true || indSW(a,b,map) == true || indW(a,b,map) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //Right
        else if(0 < a < map.size()-1 && b == map[0].size()-1)
        {
            if(indS(a,b,map) == true || indSW(a,b,map) == true || indS(a,b,map) == true || indNW(a,b,map) == true || indN(a,b,map) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //Bottom
        else if(a==map.size()-1 && 0<b<map[0].size()-1)
        {
            if(indW(a,b,map) == true || indNW(a,b,map) == true || indN(a,b,map) == true || indNE(a,b,map) == true || indE(a,b,map) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //Left
        else if(0 < a < map.size()-1 && b==0)
        {
            if(indN(a,b,map) == true || indNE(a,b,map) == true || indE(a,b,map) == true || indSE(a,b,map) == true || indS(a,b,map) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    //INSIDE
        else if(0<a<map.size() && 0<b<map[0].size())
        {
            if(indN(a,b,map) == true || indNE(a,b,map) == true || indE(a,b,map) == true || indSE(a,b,map) == true || indS(a,b,map) == true ||indSW(a,b,map) == true || indW(a,b,map) == true || indNW(a,b,map) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    
    bool indN(int a, int b, vector<vector<char>> map)
    {
        if(map[a-1][b] == 'T' || map[a-1][b] == '#')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool indNE(int a, int b, vector<vector<char>> map)
    {
        if(map[a-1][b+1] == 'T' || map[a-1][b+1] == '#')
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }
    
    bool indE(int a, int b, vector<vector<char>> map)
    {
        if(map[a][b+1] == 'T' || map[a][b+1] == '#')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool indSE(int a, int b, vector<vector<char>> map)
    {
        if(map[a+1][b+1] == 'T' || map[a+1][b+1] == '#')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool indS(int a, int b, vector<vector<char>> map)
    {
        if(map[a+1][b] == 'T' || map[a+1][b] == '#')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool indSW(int a, int b, vector<vector<char>> map)
    {
        if(map[a+1][b-1] == 'T' || map[a+1][b-1] == '#')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool indW(int a, int b, vector<vector<char>> map)
    {
        if(map[a][b-1] == 'T' || map[a][b-1] == '#')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool indNW(int a, int b, vector<vector<char>> map)
    {
        if(map[a-1][b-1] == 'T' || map[a-1][b-1] == '#')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
    //search for required min population in min number of adjacent cells
    bool adjPop(int a, int b, vector<vector<int>> initPop, int popReq, int cellReq)
    {
        //counts the number of cells that fit the criteria
        int countCell = 0;    
        
    //CORNERS
        //Top left
        if(a == 0 && b == 0)
        {
            //search east
            if(initPop[a][b+1] >= popReq)
            {
                countCell++;
            }
            //search south east
            if(initPop[a+1][b+1] >= popReq)
            {
                countCell++;
            }
            //search south
            if(initPop[a+1][b] >= popReq)
            {
                countCell++;
            }
        }
        //Top Right
        else if(a==0 && b == initPop[0].size()-1)
        {
            //search South
            if(initPop[a+1][b] >= popReq)
            {
                countCell++;
            }
            //search south west
            if(initPop[a+1][b-1] >= popReq)
            {
                countCell++;
            }
            //search West
            if(initPop[a][b-1] >= popReq)
            {
                countCell++;
            }
        }
        //Bottom Right
        else if(a == initPop.size()-1 && b == initPop[0].size()-1)
        {
            //Search West
            if(initPop[a][b-1] >= popReq)
            {
                countCell++;
            }
            //search North west
            if(initPop[a-1][b-1] >= popReq)
            {
                countCell++;
            }
            //search north
            if(initPop[a-1][b] >= popReq)
            {
                countCell++;
            }
        }
        //Bottom left
        else if(a == initPop.size()-1 && b == 0)
        {
            //search north
            if(initPop[a-1][b] >= popReq)
            {
                countCell++;
            }
            //search north east
            if(initPop[a-1][b+1] >= popReq)
            {
                countCell++;
            }
            //search east
            if(initPop[a+1][b+1] >= popReq)
            {
                countCell++;
            }
        }
    //BORDERS
        //Top border
        else if(a==0 && 0<b<initPop[0].size()-1)
        {
            //search East
            if(initPop[a][b+1] >= popReq)
            {
                countCell++;
            }
            //search South East
            if(initPop[a+1][b+1] >= popReq)
            {
                countCell++;
            }
            //search South
            if(initPop[a+1][b] >= popReq)
            {
                countCell++;
            }
            //search West
            if(initPop[a][b-1] >= popReq)
            {
                countCell++;
            }
            //search West
            else if(initPop[a][b-1] >= popReq)
            {
                countCell++;
            }
        }
        //right border
        else if(0 < a < initPop.size()-1 && b == initPop[0].size()-1)
        {
            //search South
            if(initPop[a+1][b] >= popReq)
            {
                countCell++;
            }
            //search South West
            if(initPop[a+1][b-1] >= popReq)
            {
                countCell++;
            }
            //search West
            if(initPop[a][b-1] >= popReq)
            {
                countCell++;
            }
            //search North West
            if(initPop[a-1][b-1] >= popReq)
            {
                countCell++;
            }
            //search North
            if(initPop[a-1][b] >= popReq)
            {
               countCell++;
            }
        }
        //bottom border
        else if(a==initPop.size()-1 && 0<b<initPop[0].size()-1)
        {
            //search West
            if(initPop[a][b-1] >= popReq)
            {
                countCell++;
            }
            //search North West
            if(initPop[a-1][b-1] >= popReq)
            {
                countCell++;
            }
            //search North
            if(initPop[a-1][b] >= popReq)
            {
               countCell++;
            }
            //search North East
            if(initPop[a-1][b+1] >= popReq)
            {
                countCell++;
            }
            //search East
            if(initPop[a][b+1] >= popReq)
            {
                countCell++;
            }
        }
        //left border
        else if(0 < a < initPop.size()-1 && b==0)
        {
            //search North
            if(initPop[a-1][b] >= popReq)
            {
               countCell++;
            }
            //search North East
            if(initPop[a-1][b+1] >= popReq)
            {
                countCell++;
            }
            //search East
            if(initPop[a][b+1] >= popReq)
            {
                countCell++;
            }
            //search South East
            if(initPop[a+1][b+1] >= popReq)
            {
                countCell++;
            }
            //search South
            if(initPop[a+1][b] >= popReq)
            {
                countCell++;
            }
        }
    //Interior
    else if(0<a<initPop.size() && 0<b<initPop[0].size())
    {
        //search North
            if(initPop[a-1][b] >= popReq)
            {
               countCell++;
            }
        //search South
            if(initPop[a+1][b] >= popReq)
            {
                countCell++;
            }
        //search West
            if(initPop[a][b-1] >= popReq)
            {
                countCell++;
            }
        //search East
            if(initPop[a][b+1] >= popReq)
            {
                countCell++;
            }
        //search North West
            if(initPop[a-1][b-1] >= popReq)
            {
                countCell++;
            }
        //search North East
            if(initPop[a-1][b+1] >= popReq)
            {
                countCell++;
            }
        //search South West
            if(initPop[a+1][b-1] >= popReq)
            {
                countCell++;
            }
        //search South East
            if(initPop[a+1][b+1] >= popReq)
            {
                countCell++;
            }
    }
        if(countCell>=cellReq)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
};

#endif

