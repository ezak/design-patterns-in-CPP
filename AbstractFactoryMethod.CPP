// Familly: Creational Pattern
// Name: Abstract Factory Method

#include <iostream>

class Shape {
public:
	Shape(){
		id_ = total_++;
	}

	virtual void draw() = 0;

protected:
	int id_;
	static int total_;
};

int Shape::total_ = 0;


class Circle : public Shape{
public:
	void draw(){
		cout<<"Circle " << id_ << ": draw" <<endl;
	}
};

class Square : public Shape {
	
public:
	void draw(){
		cout<<"Square "<<id_<<": draw"<<endl;
	}
};


class Ellipse : public Shape{
public:
	void draw(){
		cout<<"Square "<<id_<<": draw"<<endl;
	}
};

class Rectangle : public Shape{
public:
	void draw(){
		cout<<"Rectangle "<<id_<<": draw"<<endl;
	
	}

};


class Factory{
public:
	virtual Shape* createCurvedInstance() = 0;
	virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory{
public:
	Shape* createCurvedInstance(){
		return new Circle;
	}

	Shape* createStraightInstance(){
		return new Square;
	}

};

class RobustShapeFactory : public Factory{
public:
	Shape* createCurvedInstance(){
		return new Ellipse;
	}

	Shape* creteStraightInstance(){
		return new Rectangle;
	}
};

int main(){

#ifdef SIMPLE
	Factory* factory = new SimpleFactory;
#elif ROBUST
	Factory* factory = new RobustShapeFactory;
#endif

	Shape* shape[3];

	shape[0] = factory->createCurvedInstance();
	shape[1] = factory->createStraightInstance();
	shape[2] = factory->createCurvedInstance();

	for(int i=0; i<3; i++){
		shape[i]->draw();	
	}
	
	return 0;
}
