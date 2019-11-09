// simple_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "simple_dll.h"
#include <iostream>


using namespace std;

simple_dll::simple_dll()
{
}


simple_dll::~simple_dll()
{
}

void simple_dll::hello()
{
    cout << "Hello World from DLL" << endl;

}

void simple_dll::helloStatic()
{
	cout << "Hello World from DLL static" << endl;
}