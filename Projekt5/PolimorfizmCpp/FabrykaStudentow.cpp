#include <iostream>
#include "FabrykaStudentow.h"
#include "FabrykaOsob.h"
#include "Student.h"
using namespace std;

Osoba* FabrykaStudentow::utworz(void){
    return new Student;
}

FabrykaStudentow::FabrykaStudentow(){}

FabrykaStudentow::~FabrykaStudentow(){}
