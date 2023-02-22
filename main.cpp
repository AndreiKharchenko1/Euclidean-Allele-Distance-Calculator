#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <string>
#include <stdexcept>

#include <cmath>


using namespace std;
double euclideanmethod(double A,double user){
  return abs(A-user)*abs(A-user);
}
double acceleratedmethod(double A, double user){
  return abs(A-user)*abs(A-user)*abs(A-user);
}

int main(){
    int snps;

 cout << "enter number of snps used for comparison (between 0 and 20)";
 cin >> snps;
double frequencyA[snps];
double frequencyB[snps];
double frequencyC[snps];
 for(int i = 0; i<snps; i++){
    cout << "Enter derived allele frequency in snp # " << i+1 << " in population A : ";
    cin >> frequencyA[i];
    cout << "Enter derived allele frequency in snp # " << i+1 << " in population B : ";
    cin >> frequencyB[i];
    cout << "Enter derived allele frequency in snp # " << i+1 << " in population C : ";
    cin >> frequencyC[i];
 }
 double derivedinuser[snps];
 double frequencyuser[snps];
 double totaleuclideanA =0; double totaleuclideanB = 0; double totaleuclideanC =0;
 double totalacceleratedA =0; double totalacceleratedB = 0; double totalacceleratedC = 0;
 for(int i = 0; i<snps; i++){
    cout << "Enter how many derived alleles you have in snp # " << i+1 << " : "  ;
    cin >> derivedinuser[i];
    cout << "\n";

 }
 for(int i = 0; i < snps; i++){
    frequencyuser[i]= derivedinuser[i]/2;
 }
 for(int i = 0; i< snps; i++){
    totaleuclideanA = totaleuclideanA + euclideanmethod(frequencyA[i], frequencyuser[i]);
    totaleuclideanB = totaleuclideanB + euclideanmethod(frequencyB[i], frequencyuser[i]);
    totaleuclideanC = totaleuclideanC + euclideanmethod(frequencyC[i], frequencyuser[i]);
    totalacceleratedA = totalacceleratedA + acceleratedmethod(frequencyA[i], frequencyuser[i]);
    totalacceleratedB = totalacceleratedB + acceleratedmethod(frequencyB[i], frequencyuser[i]);
    totalacceleratedC = totalacceleratedC + acceleratedmethod(frequencyC[i], frequencyuser[i]);
 }
cout << "Euclidean Method distance to population A is: " << sqrt(totaleuclideanA) << "\n";
cout << "Euclidean Method distance to population B is: " << sqrt(totaleuclideanB) << "\n";
cout << "Euclidean Method distance to population C is: " << sqrt(totaleuclideanC) << "\n";
cout << "Accelerated Euclidean Method distance to population A is: " << sqrt(totalacceleratedA) << "\n";
cout << "Accelerated Euclidean Method distance to population B is: " << sqrt(totalacceleratedB) << "\n";
cout << "Accelerated Euclidean Method distance to population C is: " << sqrt(totalacceleratedC) << "\n";
}
