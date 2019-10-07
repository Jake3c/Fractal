//
//  main.cpp
//  Fractals
//
//  Created by Jake Carrico on 2/4/16.
//  Copyright © 2016 Jake Carrico. All rights reserved.

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;


vector<vector<string> > fractal(vector<vector<string> > pattern, string l);     //advances the fractal one generation
vector<vector<string> > createPattern(string l);                                //creates the design
vector<vector<string> > flipR(vector<vector<string> > pattern);                 //flips along y=-x line
vector<vector<string> > flipL(vector<vector<string> > pattern);                 //flips along y=x line
void display(vector<vector<string> > v);                                        //displays the design




//******************************\\


int main() {
    string s = "\u2588";                                            //unicode for the block character
    int n=0;
    
    vector<vector<string> > design = createPattern(s);              //creates the origional design
    
    cout << "How many times would you like to run the fractal? ";
    cin >> n;
    n = n-1;
    
    display(design);                                                //displays initial design
    string dummy;                                                   //pauses the screen
    getline(cin, dummy);
    
    for(int i=0; i<n; i++){                                         //runs the fractal however long the user inputed
        string dummy;
        cout << "Enter to continue..." << endl;                     //pauses the screen
        getline(cin, dummy);
        design = fractal(design, s);
        display(design);
    }
    
    return 0;
}


//*******************************\\




void display(vector<vector<string> > v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j];
        }
        cout << '\n';
    }
}

vector<vector<string> > createPattern(string l){
    vector<vector<string> > design(3, vector<string>(3));
    for(int i=0; i<design.size(); i++){
        for(int j=0; j<design[i].size(); j++){
            design[i][j] = ' ';
        }
    }
    design[0][0] = l;
    design[1][0] = l;
    design[2][0] = l;
    //design[3][0] = l;
    //design[4][0] = l;
    design[0][1] = l;
    design[0][2] = l;
    //design[0][3] = l;
    //design[4][4] = l;
    //design[3][4] = l;
    design[2][2] = l;
    design[1][2] = l;
    //design[0][4] = l;
    
    return design;
}

vector<vector<string> > fractal(vector<vector<string> >pattern, string l){
    vector<vector<string> > nextGen(pattern.size()*2+1, vector<string>(pattern[0].size()*2+1));
    vector<vector<string> > patL = flipL(pattern);
    vector<vector<string> > patR = flipR(pattern);
    
    for(int i=0; i<pattern.size(); i++){
        for(int j=0; j<pattern[i].size(); j++){
            nextGen[i][j] = pattern[i][j];
            nextGen[i+pattern.size()+1][j] = patR[i][j];
            nextGen[i][j+pattern[0].size()+1] = pattern[i][j];
            nextGen[i+pattern.size()+1][j+pattern[0].size()+1] = patL[i][j];
            
        }
    }
    for(int i=0; i<nextGen.size(); i++){
        nextGen[i][pattern[0].size()] = ' ';
        nextGen[pattern.size()][i] = ' ';
    }
    nextGen[pattern.size()][0] = l;
    nextGen[pattern.size()][nextGen[0].size()-1] = l;
    nextGen[pattern.size()-1][pattern.size()] = l;
    
    
    
    return nextGen;
}

vector<vector<string> > flipR(vector<vector<string> > pattern){
    vector<vector<string> > temp = pattern;
    
    for(int i=0; i<pattern.size(); i++){
        for(int j=0; j<pattern[0].size(); j++){
            temp[i][j] = pattern[pattern.size()-1-j][pattern[0].size()-1-i];
        }
    }
    return temp;
}


vector<vector<string> > flipL(vector<vector<string> > pattern){
    vector<vector<string> > temp = pattern;
    
    for(int i=0; i<pattern.size(); i++){
        for(int j=0; j<pattern[0].size(); j++){
            temp[i][j] = pattern[j][i];
        }
    }
    return temp;
}






























