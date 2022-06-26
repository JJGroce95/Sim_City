#ifndef POLLUTION_H
#define POLLUTION_H
#include <iostream>
#include <vector>
using namespace std;

class Pollution
{
    private: 
        int col, row;
        vector<vector<int>> pollution;
        vector<vector<int>> temp;
        
    public:
    //constructor
    Pollution(int a, int b)
    {
        col = a;
        row = b;
        //initialize to zero
        vector<vector<int>> vec(a, vector<int> (b,0));
        pollution = vec;
        temp = pollution;
    }
    
    void update()
    {
        pollution = temp;
    }
    
    void show()
    {
        for (int i = 0; i < pollution.size(); i++) 
        { 
            for (int j = 0; j < pollution[i].size(); j++) 
            cout << pollution[i][j] << " "; 
            cout << endl; 
        } 
    }
    
    void populate(int a, int b, vector<vector<int>> initPop)
    {
        if(initPop[a][b]>pollution[a][b])
        {
            temp[a][b] = initPop[a][b];
        }
        
        
        spreadPol(a, b);
        
    }
        
        void spreadPol(int a, int b)
        {
        //CORNERS
            //Top Left
            if(a == 0 && b == 0)
            {
                //East
                if(polE(a,b,pollution) < pollution[a][b])
                {
                    temp[a][b+1] = pollution[a][b]-1;
                    
                }
                //South East
                if(polSE(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b+1] = pollution[a][b]-1;
                }
                //South
                if(polS(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b] = pollution[a][b]-1;
                }
            }
            //Top Right
            else if(a == 0 && b == pollution[0].size()-1)
            {
                //South
                if(polS(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b] = pollution[a][b]-1;
                }
                //South East
                if(polSE(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b-1] = pollution[a][b]-1;
                }
                //East
                if(polW(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b-1] = pollution[a][b]-1;
                }
            }
            //Bottom Right
            else if(a == pollution.size()-1 && b == pollution[0].size()-1)
            {
                if(polW(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b-1] = pollution[a][b]-1;
                }
                if(polNW(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b-1] = pollution[a][b]-1;
                }
                if(polN(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b] = pollution[a][b]-1;
                }
            }
            //Bottom Left
            else if(a == pollution.size()-1 && b == 0)
            {
                if(polN(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b] = pollution[a][b]-1;
                }
                if(polNE(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b+1] = pollution[a][b]-1;
                }
                if(polE(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b+1] = pollution[a][b]-1;
                }
            }
        //BORDERS
            //Top
            else if(a==0 && 0<b<pollution[0].size()-1)
            {
                //east
                if(polE(a,b,pollution)<pollution[a][b])
                {
                    
                    temp[a][b+1] = pollution[a][b]-1;
                }
                //south east
                if(polSE(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b+1] = pollution[a][b]-1;
                }
                //south
                if(polS(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b] = pollution[a][b]-1;
                }
                //south west
                if(polSW(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b-1] = pollution[a][b]-1;
                }
                //west
                if(polW(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b-1] = pollution[a][b]-1;
                }
            }
            //Right
            else if(0 < a < pollution.size()-1 && b == pollution[0].size()-1)
            {
                //south
                if(polS(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b] = pollution[a][b]-1;
                }
                //south west
                if(polSW(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b-1] = pollution[a][b]-1;
                }
                //west
                if(polW(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b-1] = pollution[a][b]-1;
                }
                //north west
                if(polNW(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b-1] = pollution[a][b]-1;
                }
                //north
                if(polN(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b] = pollution[a][b]-1;
                }
            }
            //Bottom
            else if(a==pollution.size()-1 && 0<b<pollution[0].size()-1)
            {
                //east
                if(polE(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b+1] = pollution[a][b]-1;
                }
                //North east
                if(polNE(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b+1] = pollution[a][b]-1;
                }
                //North
                if(polN(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b] = pollution[a][b]-1;
                }
                //North west
                if(polNW(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b-1] = pollution[a][b]-1;
                }
                //West
                if(polW(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b-1] = pollution[a][b]-1;
                }
            }
            //Left
            else if(0 < a < pollution.size()-1 && b==0)
            {
                //North
                if(polN(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b] = pollution[a][b]-1;
                }
                //North east
                if(polNE(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b+1] = pollution[a][b]-1;
                }
                //east
                if(polE(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b+1] = pollution[a][b]-1;
                }
                //South east
                if(polSE(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b+1] = pollution[a][b]-1;
                }
                //South
                if(polS(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b] = pollution[a][b]-1;
                }
            }
            //Inside
            else if(0<a<pollution.size() && 0<b<pollution[0].size())
            {
                 //North
                if(polN(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b] = pollution[a][b]-1;
                }
                //North east
                if(polNE(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b+1] = pollution[a][b]-1;
                }
                //east
                if(polE(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b+1] = pollution[a][b]-1;
                }
                //South east
                if(polSE(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b+1] = pollution[a][b]-1;
                }
                //South
                if(polS(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b] = pollution[a][b]-1;
                }
                //south west
                if(polSW(a,b,pollution)<pollution[a][b])
                {
                    temp[a+1][b-1] = pollution[a][b]-1;
                }
                //West
                if(polW(a,b,pollution)<pollution[a][b])
                {
                    temp[a][b-1] = pollution[a][b]-1;
                }
                //North west
                if(polNW(a,b,pollution)<pollution[a][b])
                {
                    temp[a-1][b-1] = pollution[a][b]-1;
                }
            }
        }
        
        int polN(int a, int b, vector<vector<int>> pollution)
        {
            return pollution[a-1][b];
        }
        int polNE(int a, int b, vector<vector<int>>pollution)
        {
            return pollution[a-1][b+1];
        }
        int polE(int a, int b, vector<vector<int>> pollution)
        {
            return pollution[a][b+1];
        }
        int polSE(int a, int b, vector<vector<int>> pollution)
        {
            return pollution[a+1][b+1];
        }
        int polS(int a, int b, vector<vector<int>> pollution)
        {
            return pollution[a+1][b];
        }
        int polSW(int a, int b, vector<vector<int>> pollution)
        {
            return pollution[a+1][b-1];
        }
        int polW(int a, int b, vector<vector<int>> pollution)
        {
            return pollution[a][b-1];
        }
        int polNW(int a, int b, vector<vector<int>> pollution)
        {
            return pollution[a-1][b-1];
        }
        
        int totalPollution()
        {
            int sumPol = 0;
            for(int i = 0; i<pollution.size();i++)
            {
                for(int j = 0;j<pollution.size();j++)
                {
                    sumPol+=pollution[i][j];
                }
            }
            return sumPol;
        }
};
/*
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
int main()
{
    int 
    refresh = 0, limit = 0, //time iteration (refresh), tot iterations (limit)
    avWork = 10;            //available workers
    
 
    
//->//placeholder population map.  Replace with actual population map.
    vector<vector<int>> initPop{ {7, 0, 2, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};
   
    Pollution Pol(initPop.size(), initPop[0].size());         //class declaration for pollution
    
    //get limit from user
    limit = getLimit();
    
    //run the project
    while(refresh<limit)
    {
        cout << "\t|Day " << refresh+1 << "|" << endl;
        
        for(int i = 0; i<initPop.size(); i++)
        {
            for(int j = 0; j<initPop[i].size(); j++)
            {
                Pol.populate(i, j, initPop);
            }
            
        }
        Pol.update();
        refresh++;
        Pol.show(); //show pollution map
    }
    
    
    return 0;
}*/

#endif