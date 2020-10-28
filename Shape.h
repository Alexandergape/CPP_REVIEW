//
// Created by Alexander P on 20/05/17.
//

#ifndef FIRST_STEPS_WITH_C___SHAPE_H
#define FIRST_STEPS_WITH_C___SHAPE_H


class Shape {
public:
   static int numOfShapes;
   Shape();
   Shape(double heigth);
   Shape(double heigth, double width);
//    Shape(const Shape& orig);
   virtual ~Shape();

   //setters and getters
   static int getNumOfShapes();

   double getHeigth();

   void setHeigth(double heigth);

   double getWidth();

   void setWidth(double width);

   virtual double Area(); // virtual means it can be overrated

//private:
protected:
   double heigth;
   double width;
};

#endif //FIRST_STEPS_WITH_C___SHAPE_H
