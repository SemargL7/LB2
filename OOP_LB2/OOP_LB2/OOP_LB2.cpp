#include <iostream>
#include <cmath>
#define PI 3.14
#define N 2

using namespace std;

class Cirle {
private:
	int* center;
	int radius;
	int n;
public:
	Cirle() {
		n = 2;
		center = new int[n];
		for (int i = 0; i < n; i++) {
			center[i] = i + 1;
		}
		radius = 3;
	}
	Cirle(int n ,int *center, int radius) {
		this->n = n;
		this->center = new int[this->n];
		for (int i = 0; i < n; i++) {
			this->center[i] = center[i];
		}
		this->radius = radius;
	}
//	Cirle(const Cirle& obj) {
//		this->n = obj.n;
//		for (int i = 0; i < this->n; i++) {
//			this->center[i] = obj.center[i];
//		}
//		this->radius = obj.radius;
//	}
	Cirle& operator = (const Cirle& obj) {}
	~Cirle() { delete[] center; }

	int GetRadius()				{ return radius; }
	void GetCenter() 
	{ 
		for (int i = 0; i < n; i++) 
			cout << center[i] << endl;  
	}

	void SetCenter(int* center) 
	{ 
		for (int i = 0; i < n; i++)
		this->center[i] = center[i]; 
	}
	void SetRadius(int radius)  { this->radius = radius; }

	double square();
	double longOfcirle();
};

double Cirle::square() {
	if(this->n == 2)
		return (PI * pow(radius, 2));
	else
		return (4 * PI * pow(radius, 2));
}

double Cirle::longOfcirle() {									//шукає довжину кола
	return (2 * PI * radius);
}

int main() {
	cout << "Default:" << endl;
	Cirle obj1;
	obj1.GetCenter();
	cout << obj1.GetRadius() << endl;


	cout << "\n Change:" << endl;
	int cords[] = { 2, 3 };
	obj1.SetCenter(cords);
	obj1.SetRadius(5);

	obj1.GetCenter();
	cout << obj1.GetRadius() << endl;
	cout << "square: "<<obj1.square() << "\nlong of cirle: " << obj1.longOfcirle() << endl << endl;



	int cordTest[] = { 5, 3 , 6};


	cout << "Next Step(1):" << endl;
	Cirle obj2(N, cordTest, 10);
	obj2.GetCenter();
	cout << obj2.GetRadius() << endl;
	cout << "square: " << obj2.square() << "\nlong of cirle: " << obj2.longOfcirle() << endl << endl;



	cout << "Next Step(1 but 3D):" << endl;
	Cirle obj3(N + 1, cordTest, 10);
	obj3.GetCenter();
	cout << obj3.GetRadius() << endl;
	cout << "square: " << obj3.square() << "\nlong of cirle: " << obj3.longOfcirle() << endl << endl;



	cout << "Last Step(Copy):" << endl;
	Cirle obj4 = obj2;
	obj4.GetCenter();
	cout << obj4.GetRadius() << endl;
	cout << "square: " << obj4.square() << "\nlong of cirle: " << obj4.longOfcirle() << endl << endl;

}