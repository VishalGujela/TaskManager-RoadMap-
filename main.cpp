#include <iostream>
#include "cli.hpp"

using namespace std;

int main(int argc,char **argv){
	CLI cli(argc,argv);
	if(!cli.isTrue()){
		return 0;
	}
	cli.processArgs();
	return 0;
}
