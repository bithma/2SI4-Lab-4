
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){
	int i;
	int j;
	if (row <= 0) { // sets rows and columns to 3 if they are not a valid number
			rowsNum = 3;
		} else {
			rowsNum = row;
		}

		if (col <= 0) {
			colsNum = 3;
		} else {
			colsNum = col;
		}

		matrixData = (int **)malloc(rowsNum*sizeof(int*)); // allocating memory based on size of rows

		    for (i = 0 ; i < rowsNum ; ++i ){
		    	matrixData[i] = (int*) malloc(colsNum*sizeof(int)); // space for each column in each row

		    	for (j = 0 ; j < colsNum ; ++j ){ // setting every in the matrix to 0
		    		matrixData[i][j]=0;
		    	}
		    }


	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/


}


Matrix::Matrix(int row, int col, int** table){


	this->colsNum = col;
	this->rowsNum = row;
	int i;
	int j;

	matrixData = (int **)malloc(rowsNum*sizeof(int*));


		 for (i=0 ; i<rowsNum; i++ ) // runs through rows of matrix
		    {
		       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
		    }

		    for (i=0 ; i<rowsNum ;i++ ){ //runs through coloums of matrix

		    	for (j=0; j<colsNum; j++ ){
		    		matrixData[i][j]= table [i][j]; // adds data to matrixdata
		}
		    }

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/

	

}

int Matrix::getElement(int i, int j){

	if(i<0 || i>=rowsNum || j<0 || j>= colsNum){
			throw out_of_range("Invalid indexes."); //returns message if invalid i and j values
		return -1;
		}
		return matrixData [i][j]; //returns element

	}



bool Matrix::setElement(int x, int i, int j){
	if((i>=0 && i<rowsNum) && (j>=0 && j< colsNum)){ //checks if i and j values are acceptable
		matrixData [i][j] = x; //changes value in matrix
	return true;
			}

    return false; // false if action could not be completed
}


Matrix Matrix::copy(){

	/* fix the code and write your implementation below */

    Matrix copy=  Matrix(this -> rowsNum,this -> colsNum, this -> matrixData); // matrix is copied


    return  copy;


}


void Matrix::addTo( Matrix m ){
	int i;
	int j;

	if ((this -> rowsNum != m.rowsNum) ||(this -> colsNum != m.colsNum) ){ //checks if operation is possible
		throw invalid_argument("Invalid operation");
	}

	for (i = 0; i< m.rowsNum; i++){ //runs through each element in matrix
		for (j=0; i< m.colsNum; j++){
			this -> matrixData[i][j] = this -> matrixData[i][j] + m.matrixData[i][j]; // adds value from other matrix
		}
	}

	
}


Matrix Matrix::subMatrix(int i, int j){
	int row;
	int col;

	/* The exception detail message should read: "Submatrix not defined"*/
	if(i<0 || i>=this ->rowsNum || j<0 || j>= this -> colsNum){ //checking to see if i and j values are acceptable
		throw out_of_range("Submatrix not defined");
	}

	/* fix the code and write your implementation below */
	Matrix subM = Matrix (i+1,j+1);

	for (row = 0; row < i+1; row++){ //running through all elements in the matrix
		for (col = 0; col <j+1; col++) {
		subM.matrixData[row][col] = this -> matrixData[row][col]; //adds values into subM matrix
		}
	}



    


    return  subM;
}


int Matrix::getsizeofrows(){

	
	/* update below return */
	return this-> rowsNum; //returns value of rows
}


int Matrix::getsizeofcols(){



	/* update below return */
    return this -> colsNum; //returns value of columns
}


bool Matrix::isUpperTr(){

	/* write your implementation here and update return accordingly */
	int i; //Initialize variables
	int j;
	int sum= 0 ;
	for (i=0; i< rowsNum; i++ ){ //runs through all rows and columns of matrix below diagonal
		for (j=i+1; j<colsNum; j++){
			sum += matrixData[i][j]; //

		}
	}
	if (sum != 0){ //all values below diagonal should add to 0 to be diagonal
		return false;
	}
	  return true;
}


string Matrix::toString(){
	string output = ""; // empty string
	int i = 0;
	int j=0;

	for (i=0; i<rowsNum; i++){ //runs through all elements in matrix
		for (j=0; j<colsNum; j++){
			output = output + to_string(matrixData[i][j]) + " "; // adds row elements to string
		}
		output += "\n"; // adds spaces between each row
	}


	//return output;
	 return output;
}
