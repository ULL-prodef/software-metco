/***********************************************************************************
 * AUTORES
 *    Jesica de Armas Adrian
 * 
 * FECHA
 *    Abril 2010
 *
 * DESCRIPCION
 *
 * ********************************************************************************/

#ifndef __TDCSP_H__
#define __TDCSP_H__

#include "Individual.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

typedef struct {
        int pat;
        double val;
} ProfArea;


class TDCSP : public Individual{
public:
	// Destructor
	~TDCSP (void){}

	// Initialization method
	bool init (const vector<string> &params);

	// Genetic Operators
	void crossoverPMX(Individual* ind);
	//void crossoverOX(Individual* ind);
	//void crossoverCX(Individual* ind);

	// Operador de reparacion
	bool repair() ;
	bool fit();

	// Evaluation
	void evaluate (void);

	// Clone
	Individual* clone (void) const;

	// Reads a problem from file
  	 bool readFile(const string filename);

	// Check condition 1 <= no <= np -1
	bool checkCondition();
	
	// B�squeda de un patron en el segmento de intercambio 
	int findpat(int elem, int *p1, int *p2, int point1, int point2);	
	//int findPos(int elem, int *p);	
	//bool included(int elem, int *p, int point1, int point2);
	
	// Setters
	//void inline setLength(const int i, const int j, const double value) const { len[i][j] = value; }
	//void inline setWidth(const int i, const int j, const double value) const { wid[i][j] = value; }
	
	// Getters
  	//double inline getLength(const int i, const int j) const { return len[i][j]; }
	//double inline getWidth(const int i, const int j) const { return wid[i][j]; }

	// Generation of an individual
	void restart(void);
	void randomRestart(void);

	// Print solution
	void print(void);
	bool improveOne(Individual *ind, int objIndex);

	// Fix a given final solution
	//void fixSolution(void);
 
	int uniformRandom(int maxValue) const;
 	double inline getMaximum(const int i) const { return totalNumPat-1; }
	double inline getMinimum(const int i) const { return -2; }
	unsigned int getOptDirection(const int i) const;
		 
private:
	void dependentMutation (double pm);
	void dependentCrossover (Individual* ind);
		
	// Length and width of patterns
	static double *len;
	static double *wid;
	static double *prof;
	static double widSheet; 			// Width of mother sheet
	static double lenSheet; 			// Length of mother sheet
	static int totalSize; 				// Total size of gene
	static int numPat;				 // Number of patterns
	static int totalNumPat;
	
	// Constants
	static const int H = -1;
	static const int V = -2;
	static const int NOBJ = 2;
	
	static bool firstin;                    // marca la primera entrada en restart
	
	int size;
	vector<ProfArea> profarea;
};

#endif
