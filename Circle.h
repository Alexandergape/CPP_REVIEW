//
// Created by Alexander P on 20/05/17.
//

#ifndef FIRST_STEPS_WITH_C___CIRCLE_H
#define FIRST_STEPS_WITH_C___CIRCLE_H

#include "Shape.h"

class Circle: public Shape{
public:
   Circle();

   Circle(double width);
   virtual ~Circle();
   double Area();
//    int width;
//private:
};


#endif //FIRST_STEPS_WITH_C___CIRCLE_H
