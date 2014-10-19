// This is the main SDL include file
// iostream is so we can output error messages to console
#include <iostream> 
/*Include strings*/
#include <string>
/*Include vector*/
#include <vector>
/*These are class headers*/
#include "Application.h"
#include "Vec2.h"
#include "Vec4.h"



int main(int argc, char *argv[])
{

	/*Creates the Application*/
	Application SDL;
	SDL.callExecution();

	return 0;
}
