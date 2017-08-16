//#define EMAIL "justinthompson593@gmail.com"
//
//  main.cpp
//  Inbox
//
//  Created by Justin Thompson on 8/15/17.
//  Copyright © 2017 Justin Thompson. All rights reserved.
//

#include <iostream>
#include "Inbox.hpp"

using namespace std;


Inbox In(EMAIL);


int main(int argc, const char * argv[]) {

	for(int i=0; i<argc; i++){
		if( strncmp(argv[i], "-m", 2) == 0 ||  strncmp(argv[i], "-msg", 4) == 0 || strncmp(argv[i], "-message", 8) == 0 )
			In.message();
		
		if( strncmp(argv[i], "-g", 2) == 0 || strncmp(argv[i], "-get-msg", 8) == 0 )
			In.getMessages();
	}

	return 0;
}
