#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <fstream>
using namespace std;

vector<double> MakePoint(int d, mt19937 &gen, uniform_real_distribution<> &dis){ //Permite generar puntos aleatorios dentro.
	
	vector<double> point;
	for(int i=0;i<d;i++){
		point.push_back(dis(gen)); 
	}
	return point;
}

double distancia(vector<double> a, vector<double> b){
	double suma=0.0; 
	for(int i=0;i<a.size();i++){
		suma = suma + (pow((a.at(i))-(b.at(i)),2));
	}
	return sqrt(suma);
}

int main(){
	ofstream f("text.txt");
	vector<vector<double>> points;
	int d = 5000;
	int n=100;
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0,1.0);
	for (int i=0;i<n;i++){
		points.push_back(MakePoint(d,gen,dis));
		
	}
	
	for(int i=0;i<points.size();i++){
		for(int j=i+1;j<points.size();j++){
			
			double dis = distancia(points.at(i), points.at(j));
			if(i==0&&j==1){
				f<<dis;
			}else{
				f<<endl;
				f << dis;
			}
			
			
		}
		
	}
	f.close();
	return 0;
}