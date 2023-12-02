#include <iostream>
#include <fstream>

#include "CLinear.h"

using namespace std;

CLinear::CLinear(): CGeometria() {}

void CLinear::Area() {

    area = width * length;
    
}
